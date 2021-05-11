#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Spacecraft : public QGraphicsPixmapItem
{
public:
    Spacecraft(double _speed,QGraphicsItem *parent=nullptr);

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    double speed;
    void shotThatAlien();
};

#endif // SPACECRAFT_H
