#include "widget.h"
#include "ui_widget.h"
#include "spacecraft.h"
#include"alien.h"
#include<QDebug>
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

    spacecraft= new Spacecraft(10);
    spacecraft->setFocus();
    scene->addItem(spacecraft);
    spacecraft->setX(WIDTH/2);
    spacecraft->setY(HEIGHT-spacecraft->pixmap().height()-10);

    int Y=20; //alien started y position
    for(int i=0;i<1;++i){
        int X=-30; //alien started x position
        for(int i=0;i<10;++i){
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
}

Widget::~Widget()
{
    delete ui;
}

