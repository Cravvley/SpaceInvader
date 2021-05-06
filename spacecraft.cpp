#include "spacecraft.h"
#include <QKeyEvent>

Spacecraft::Spacecraft(QGraphicsItem *parent):
    QGraphicsPixmapItem(parent),
    speed(15)
{
    setPixmap(QPixmap(":/graphics/imgs/Spacecraft.png"));
    setFlag(QGraphicsItem::ItemIsFocusable);
}

void Spacecraft::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_D){
            moveBy(speed,0);
    }
    else if(event->key()==Qt::Key_A){
            moveBy(-speed,0);
    }
}
