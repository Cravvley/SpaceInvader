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

    Alien *alien=new Alien();
    scene->addItem(alien);
    alien->setX(200);
    alien->setY(200);

    QTimer *timer = new QTimer(scene);
    timer->start(30);
    scene->connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
}

Widget::~Widget()
{
    delete ui;
}

