#include "widget.h"
#include "ui_widget.h"
#include "spacecraft.h"
#include"alien.h"
#include <QTimer>
#include <QGraphicsItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    scene = new QGraphicsScene(0,0,WIDTH,HEIGHT,this);
    scene->setBackgroundBrush(QPixmap(":/graphics/imgs/Space.gif"));
    ui->spaceInvaderView->setScene(scene);

    spacecraft= new Spacecraft(13);
    spacecraft->setFocus();
    scene->addItem(spacecraft);
    spacecraft->setX(WIDTH/2);
    spacecraft->setY(HEIGHT-spacecraft->pixmap().height()-10);

    int Y=20; //alien started y position
    for(int i=0;i<1;++i){
        int X=-30; //alien started x position
        for(int i=0;i<1;++i){
            X+=60;
            Alien *alien=new Alien(0.75,0.25);
            scene->addItem(alien);
            alien->setX(X);
            alien->setY(Y);
        }
        Y+=90;
    }

    QTimer *timer = new QTimer(scene);
    timer->start(30);
    scene->connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    scene->connect(timer,SIGNAL(timeout()),this,SLOT(endGame()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::addText(QString str)
{
    const QColor col=QColor(255,255,255);
    QGraphicsTextItem *text= scene ->addText(str);
    text->setDefaultTextColor(col);
    QFont f;
    f.setPointSize(50);
    text->setFont(f);
    text->setPos(WIDTH/2-150,HEIGHT/2-50);
}

void Widget::endGame()
{
    int alienCounter=0;
    bool spacecraftExist=false;
    auto items=scene->items();
    for(auto item:items){
        Spacecraft *spacecraft_cast=dynamic_cast<Spacecraft*>(item);
        Alien *alien_cast=dynamic_cast<Alien*>(item);
        if(spacecraft_cast){
            spacecraftExist=true;
        }else if(alien_cast){
            alienCounter++;
        }
    }

    if(alienCounter==0&&isEnd)    {
        scene->clear();
        addText("You won");
        scene->disconnect(SIGNAL(timeout()),this,SLOT(endGame()));

    }
    else if(!spacecraftExist){
        isEnd=true;
        scene->clear();
        addText("You lost");
        scene->disconnect(SIGNAL(timeout()),this,SLOT(endGame()));
    }

}

