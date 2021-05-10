#include "bullet.h"

Bullet::Bullet(double _speed,QGraphicsItem *_parent):
    QGraphicsPixmapItem(_parent),
    speed(_speed)
{
    setPixmap(QPixmap(":/graphics/imgs/bullet.png"));
    setFlag(QGraphicsItem::ItemIsMovable);
}

void Bullet::advance(int phase){
    if(phase){
        moveBy(0,speed);
        int y=scenePos().y();
        if(y<=0){
            delete this;
        }
    }
}
