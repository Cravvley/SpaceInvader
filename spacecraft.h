#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include <QGraphicsPixmapItem>

class Spacecraft : public QGraphicsPixmapItem
{
public:
    Spacecraft(QGraphicsItem *parent=nullptr);

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    double speed;
};

#endif // SPACECRAFT_H
