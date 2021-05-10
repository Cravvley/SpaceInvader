#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include "spacecraft.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    const int WIDTH=815;
    const int HEIGHT=600;
    Ui::Widget *ui;
    QGraphicsScene * scene;
    Spacecraft * spacecraft;
};
#endif // WIDGET_H
