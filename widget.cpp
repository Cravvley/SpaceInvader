#include "widget.h"
#include "ui_widget.h"
#include "spacecraft.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    scene = new QGraphicsScene(0,0,815,600,this);
    scene->setBackgroundBrush(QPixmap(":/graphics/imgs/Space.gif"));
    ui->spaceInvaderView->setScene(scene);

    spacecraft= new Spacecraft();
    spacecraft->setFocus();
    scene->addItem(spacecraft);
    spacecraft->setX(20);
    spacecraft->setY(550);

}

Widget::~Widget()
{
    delete ui;
}

