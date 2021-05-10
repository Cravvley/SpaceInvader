#ifndef BULLET_H
#define BULLET_H
#include<QGraphicsPathItem>


class Bullet:public QGraphicsPixmapItem
{
public:
    Bullet(double speed,QGraphicsItem *parent=nullptr);

protected:
    void advance(int phase);

private:
    double speed;
};

#endif // BULLET_H
