#include "bullet.h"
#include "Alien.h"
#include "spacecraft.h"
#include <QDebug>

Bullet::Bullet(double _speed,QGraphicsItem *_thisGuyIsMyBoss,QGraphicsItem *_parent):
    QGraphicsPixmapItem(_parent),
    thisGuyIsMyBoss(_thisGuyIsMyBoss),
    speed(_speed)
{
    setPixmap(QPixmap(":/graphics/imgs/bullet.png"));
    setFlag(QGraphicsItem::ItemIsMovable);
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

            if(!bullet_cast){
                Alien *alien_boss_cast=dynamic_cast<Alien*>(thisGuyIsMyBoss);
                Spacecraft *spacecraft_boss_cast=dynamic_cast<Spacecraft*>(thisGuyIsMyBoss);

                Alien *item_alien_cast=dynamic_cast<Alien*>(item);

                if(alien_boss_cast&&!item_alien_cast){
                    this->scene()->removeItem(item);
                      delete this;
                }
                else if(spacecraft_boss_cast&&item_alien_cast){
                    this->scene()->removeItem(item);
                      delete this;
                }
              }
        }
    }
}
