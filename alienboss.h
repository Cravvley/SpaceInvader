#ifndef ALIENBOSS_H
#define ALIENBOSS_H

#include <QGraphicsPixmapItem>
#include <QtGlobal>
#include <QMediaPlayer>

class AlienBoss:public QGraphicsPixmapItem
{
public:
    AlienBoss(qreal _moveX=0.5,qreal _moveY=0.5,QGraphicsItem *parent=nullptr);

protected:
    void advance(int phase);

private:
    qreal moveX;
    qreal moveY;
    int moveCount=0;
    QMediaPlayer *player;
    void shotThatGuy(int min,int max);
    void move(int howManyMoveBeforeChangeDirection);
};

#endif // ALIENBOSS_H
