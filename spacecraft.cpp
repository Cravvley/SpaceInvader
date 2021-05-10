#include "bullet.h"
#include "spacecraft.h"
#include <QKeyEvent>

Spacecraft::Spacecraft(double _speed,QGraphicsScene *_scene,QGraphicsItem *parent):
    speed(_speed),
    scene(_scene),
    QGraphicsPixmapItem(parent)

{
    setPixmap(QPixmap(":/graphics/imgs/Spacecraft.png"));
    setFlag(QGraphicsItem::ItemIsFocusable);
}

void Spacecraft::keyPressEvent(QKeyEvent *event){

    if(event->key()==Qt::Key_Space){
        Bullet *bullet= new Bullet(-10);
        scene->addItem(bullet);
        bullet->setX(this->pos().x()+20);
        bullet->setY(this->pos().y()-50);
    }

    if(event->key()==Qt::Key_D&&this->pos().x()<=(scene->width() - this->pixmap().size().width())){
            moveBy(speed,0);

    }
    else if(event->key()==Qt::Key_A&&this->pos().x()>=0){
        moveBy(-speed,0);
    }
}
