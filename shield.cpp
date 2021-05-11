#include "shield.h"

Shield::Shield(QGraphicsItem *_parent):
    QGraphicsPixmapItem(_parent)
{
    setPixmap(QPixmap(":/graphics/imgs/shield.png"));
}
