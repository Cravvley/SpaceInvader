#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include "spacecraft.h"
#include "startgame.h"

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
    const int WIDTH=940;
    const int HEIGHT=750;
    Ui::Widget *ui;
    QGraphicsScene * scene;
    Spacecraft * spacecraft;
    bool isEnd=false;
    bool winFirstStage=false;
    bool destroyWidget=false;
    bool blockDestroyWidget=false;

    void addText(QString str);
    void alienGenerator(int rows,int col,int xOffset,int yOffset);
    void alienBossGenerator(int xStartedPos,int yStartedPos);
    void shieldGenerator(int rows,int col, int xOffset,int yOffset,int startedX);
    void nextStage();

public slots:
    void endGame();
};
#endif // WIDGET_H
