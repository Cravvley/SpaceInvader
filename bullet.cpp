#include "bullet.h"
#include "Alien.h"
#include "alienboss.h">
#include "shield.h"
#include "spacecraft.h"

Bullet::Bullet(double _speed,QGraphicsItem *_thisGuyIsMyBoss,QGraphicsItem *_parent):
    QGraphicsPixmapItem(_parent),
    thisGuyIsMyBoss(_thisGuyIsMyBoss),
    speed(_speed)
{
    setPixmap(QPixmap(":/graphics/imgs/bullet.png"));
    player=new QMediaPlayer(this->scene());
    player->setMedia(QUrl("qrc:/media/media/destroyEnemy.mp3"));
}

void Bullet::advance(int phase){
    if(phase){
        warningBulletInTheEye();
    }
}

void Bullet::warningBulletInTheEye()
{
    moveBy(0,speed);
    int y=scenePos().y();

    if(y<=0){
        delete this;
    }else if(!collidingItems().isEmpty()){
        for (auto item:collidingItems()){
            Bullet * bullet_cast=dynamic_cast<Bullet*>(item);

            Alien *alien_boss_cast=dynamic_cast<Alien*>(thisGuyIsMyBoss);
            Spacecraft *spacecraft_boss_cast=dynamic_cast<Spacecraft*>(thisGuyIsMyBoss);
            AlienBoss *alienBoss_boss_cast=dynamic_cast<AlienBoss*>(thisGuyIsMyBoss);

            Alien *item_alien_cast=dynamic_cast<Alien*>(item);
            AlienBoss *item_alienBoss_cast=dynamic_cast<AlienBoss*>(item);
            Shield *shield_cast=dynamic_cast<Shield*>(item);

            if(!bullet_cast){
                if(alien_boss_cast&&!item_alien_cast){
                    boomHeadShot(item);
                }
                else if(spacecraft_boss_cast&&(item_alien_cast||item_alienBoss_cast)){
                    boomHeadShot(item);
                }
                else if(alienBoss_boss_cast&&!item_alienBoss_cast){
                    boomHeadShot(item);
                }
                else if(shield_cast){
                    boomHeadShot(item);
                }
            }
        }
    }
}

void Bullet::boomHeadShot(QGraphicsItem *item)
{
    player->play();
    this->scene()->removeItem(item);
    delete this;
}
