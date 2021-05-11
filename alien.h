#ifndef ALIEN_H
#define ALIEN_H

#include <QGraphicsPixmapItem>
#include <QtGlobal>

class Alien:public QGraphicsPixmapItem
{
public:
    Alien(qreal _moveX=0.5,qreal _moveY=0.5,QGraphicsItem *parent=nullptr);

protected:
    void advance(int phase);

private:
    qreal moveX;
    qreal moveY;
    int moveCount=0;
    void shotThatGuy(int min,int max);
    void move();
};

#endif // ALIEN_H
