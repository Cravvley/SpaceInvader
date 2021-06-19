#include "startgame.h"
#include "ui_startgame.h"
#include "widget.h"
#include <QWidget>

StartGame::StartGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartGame)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
}

StartGame::~StartGame()
{
    delete ui;
}

void StartGame::on_startGameButton_clicked()
{
    Widget *w= new Widget();
    w->show();
    this->destroy();
}
