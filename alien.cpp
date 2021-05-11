#include "alien.h"
#include <QDebug>

Alien::Alien(double _moveX,double _moveY,QGraphicsItem *_parent):
    QGraphicsPixmapItem(_parent),
    moveX(_moveX),
    moveY(_moveY)
{
    setPixmap(QPixmap(":/graphics/imgs/alien.png"));
}


void Alien::advance(int phase)
{
    if(phase){
        shotThatGuy();
        move();
    }
}



void Alien::shotThatGuy()
{

}

void Alien::move()
{
    if(moveCount==200){ // before change direction
        qDebug()<<moveX;
        moveX*=-1;
        moveY*=-1;
        moveCount=0;
    }
    moveCount++;
    moveBy(moveX,moveY);
}
