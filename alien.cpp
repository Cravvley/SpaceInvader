#include "alien.h"
#include <QDebug>

Alien::Alien(QGraphicsItem *_parent):
    QGraphicsPixmapItem(_parent)
{
    setPixmap(QPixmap(":/graphics/imgs/alien.png"));
    setFlag(QGraphicsItem::ItemIsMovable);
}
