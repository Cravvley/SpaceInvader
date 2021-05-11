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
    player=new QMediaPlayer(this->scene());
    player->setMedia(QUrl("qrc:/media/media/laserShoot.mp3"));

}

void Alien::advance(int phase)
{
    if(phase){
        shotThatGuy(1,2000);
        move(250);
    }
}

void Alien::shotThatGuy(int min, int max)
{
    int shouldIBlastHim = qrand()%((max)-min)+min;

    if(shouldIBlastHim==min){
        Bullet *bullet= new Bullet(10,this);
        this->scene()->addItem(bullet);
        bullet->setX(this->pos().x()+20);
        bullet->setY(this->pos().y()+50);

        player->play();
    }
}

void Alien::move(int howManyMoveBeforeChangeDirection)
{
    if(moveCount==howManyMoveBeforeChangeDirection){
        moveX*=-1;
        moveY*=-1;
        moveCount=0;
    }
    moveCount++;
    moveBy(moveX,moveY);
}
