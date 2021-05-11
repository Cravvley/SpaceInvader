#ifndef ALIENBOSS_H
#define ALIENBOSS_H

#include <QGraphicsPixmapItem>
#include <QtGlobal>
#include <QMediaPlayer>
#include "alien.h"

class AlienBoss:public Alien
{
public:
    AlienBoss(qreal _moveX=0.5,qreal _moveY=0.5,QGraphicsItem *parent=nullptr);
protected:
    void advance(int phase);
    void shotThatGuy(int min,int max);
};

#endif // ALIENBOSS_H
