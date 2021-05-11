#include "alien.h"
#include "bullet.h"
#include <QTime>
#include <QGlobal.h>

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
        shotThatGuy(1,1000);
        move();
    }
}

void Alien::shotThatGuy(int min, int max)
{
    int shouldIBlastHim = qrand()%((max)-min)+min;

    if(shouldIBlastHim==min){
        Bullet *bullet= new Bullet(10);
        this->scene()->addItem(bullet);
        bullet->setX(this->pos().x()+20);
        bullet->setY(this->pos().y()+50);
    }
}

void Alien::move()
{
    if(moveCount==200){ // before change direction
        moveX*=-1;
        moveY*=-1;
        moveCount=0;
    }
    moveCount++;
    moveBy(moveX,moveY);
}
