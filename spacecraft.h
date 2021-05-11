#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>

class Spacecraft : public QGraphicsPixmapItem
{
public:
    Spacecraft(double _speed,QGraphicsItem *parent=nullptr);
    void destroyThisGuy();
protected:
    void keyPressEvent(QKeyEvent *event);

private:
    QMediaPlayer *player;
    double speed;
    void shotThatAlien();
};

#endif // SPACECRAFT_H
