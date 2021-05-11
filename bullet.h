#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include<QObject>

class Bullet:public QGraphicsPixmapItem
{

public:
    Bullet(double speed,QGraphicsItem *_thisGuyIsMyBoss=nullptr,QGraphicsItem *parent=nullptr);

protected:
    void advance(int phase);

private:
    double speed;
    QMediaPlayer *player;
    void warningBulletInTheEye();
    QGraphicsItem *thisGuyIsMyBoss;



};

#endif // BULLET_H
