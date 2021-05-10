#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Spacecraft : public QGraphicsPixmapItem
{
public:
    Spacecraft(double _speed,QGraphicsScene *_scene,QGraphicsItem *parent=nullptr);

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    QGraphicsScene * scene;
    double speed;
};

#endif // SPACECRAFT_H
