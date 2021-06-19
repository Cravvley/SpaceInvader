#include "widget.h"
#include "ui_widget.h"
#include "spacecraft.h"
#include"alien.h"
#include"alienboss.h"
#include"shield.h"
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

    spacecraft= new Spacecraft(15);
    spacecraft->setFocus();
    scene->addItem(spacecraft);
    spacecraft->setX(WIDTH/2-200);
    spacecraft->setY(HEIGHT-spacecraft->pixmap().height()-10);

    alienGenerator(3,10,60,90);
    shieldGenerator(3,6,50,70,10);
    shieldGenerator(3,6,50,70,540);

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

void Widget::alienGenerator(int rows, int col, int xOffset, int yOffset)
{
    int Y=5; //alien started y position
    for(int i=0;i<rows;++i){
        int X=-30; //alien started x position
        for(int j=0;j<col;++j){
            X+=xOffset;
            Alien *alien=new Alien(1.15,0.35);
            scene->addItem(alien);
            alien->setX(X);
            alien->setY(Y);
        }
        Y+=yOffset;
    }
}

void Widget::alienBossGenerator(int xStartedPos, int yStartedPos)
{
    AlienBoss *alienBoss=new AlienBoss(7,0.25);
    scene->addItem(alienBoss);
    alienBoss->setX(xStartedPos);
    alienBoss->setY(yStartedPos);
}

void Widget::shieldGenerator(int rows, int col, int xOffset, int yOffset,int startedX)
{
        int Y=scene->height()-350; //shield started y position
        for(int i=0;i<rows;++i){
            int X=startedX; //shield started x position
            for(int j=0;j<col;++j){
                X+=xOffset;
                Shield *shield=new Shield();
                scene->addItem(shield);
                shield->setX(X);
                shield->setY(Y);
            }
            Y+=yOffset;
        }
}


void Widget::nextStage()
{
    winFirstStage=true;
    alienBossGenerator(10,0);
    alienBossGenerator(30,100);
    alienBossGenerator(50,200);
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

    if(destroyWidget){
            _sleep(1000);
            StartGame *sg= new StartGame();
            sg->show();
            destroyWidget=false;
            blockDestroyWidget=true;
            this->destroy();
        }
    else if(alienCounter==0&&!winFirstStage&&!blockDestroyWidget){
       nextStage();
    }
    else if(alienCounter==0&&winFirstStage&&!isEnd&&!blockDestroyWidget){
        scene->clear();
        addText("You won");
        destroyWidget=true;
    }
    else if(!spacecraftExist&&!blockDestroyWidget){
        isEnd=true;
        scene->clear();
        addText("You lost");
        destroyWidget=true;
    }
}
