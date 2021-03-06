#ifndef ALIEN_H
#define ALIEN_H

#include <QGraphicsPixmapItem>
#include <QtGlobal>
#include <QMediaPlayer>

class Alien:public QGraphicsPixmapItem
{
public:
    Alien(qreal _moveX=0.5,qreal _moveY=0.5,QGraphicsItem *parent=nullptr);

protected:
    virtual void advance(int phase);
    qreal moveX;
    qreal moveY;
    int moveCount=0;
    QMediaPlayer *player;
    virtual void shotThatGuy(int min,int max);
    void move(int howManyMoveBeforeChangeDirection);
};

#endif // ALIEN_H
