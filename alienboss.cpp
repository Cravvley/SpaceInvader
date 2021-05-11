#include "alienboss.h"
#include "bullet.h"
#include <QTime>
#include <QGlobal.h>

AlienBoss::AlienBoss(double _moveX,double _moveY,QGraphicsItem *_parent):
    Alien(_moveX,_moveY,_parent)
{
    setPixmap(QPixmap(":/graphics/imgs/alienBoss.png"));
    player=new QMediaPlayer(this->scene());
    player->setMedia(QUrl("qrc:/media/media/laserShoot.mp3"));

}

void AlienBoss::advance(int phase)
{
    if(phase){
        shotThatGuy(1,40);
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
