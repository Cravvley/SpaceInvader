#include "alienboss.h"
#include "bullet.h"
#include <QTime>
#include <QGlobal.h>

AlienBoss::AlienBoss(double _moveX,double _moveY,QGraphicsItem *_parent):
    QGraphicsPixmapItem(_parent),
    moveX(_moveX),
    moveY(_moveY)
{
    setPixmap(QPixmap(":/graphics/imgs/alienBoss.png"));
    player=new QMediaPlayer(this->scene());
    player->setMedia(QUrl("qrc:/media/media/laserShoot.mp3"));

}

void AlienBoss::advance(int phase)
{
    if(phase){
        shotThatGuy(1,50);
        move(100);
    }
}

void AlienBoss::shotThatGuy(int min, int max)
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

void AlienBoss::move(int howManyMoveBeforeChangeDirection)
{
    if(moveCount==howManyMoveBeforeChangeDirection){
        moveX*=-1;
        moveY*=-1;
        moveCount=0;
    }
    moveCount++;
    moveBy(moveX,moveY);
}

