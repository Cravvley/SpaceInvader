#include "bullet.h"
#include "spacecraft.h"
#include <QKeyEvent>

Spacecraft::Spacecraft(double _speed,QGraphicsItem *parent):
    speed(_speed),
    QGraphicsPixmapItem(parent)

{
    setPixmap(QPixmap(":/graphics/imgs/Spacecraft.png"));
    setFlag(QGraphicsItem::ItemIsFocusable);
    player=new QMediaPlayer(this->scene());
    player->setMedia(QUrl("qrc:/media/media/laserShoot.mp3"));
}

void Spacecraft::keyPressEvent(QKeyEvent *event){

    if(event->key()==Qt::Key_Space){
        shotThatAlien();
    }

    if(event->key()==Qt::Key_D&&this->pos().x()<=(this->scene()->width() - this->pixmap().size().width())){
            moveBy(speed,0);

    }
    else if(event->key()==Qt::Key_A&&this->pos().x()>=0){
        moveBy(-speed,0);
    }
}



void Spacecraft::shotThatAlien()
{
    Bullet *bullet= new Bullet(-10,this);
    this->scene()->addItem(bullet);
    bullet->setX(this->pos().x()+20);
    bullet->setY(this->pos().y()-50);

    player->play();
}
