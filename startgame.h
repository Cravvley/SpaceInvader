#ifndef STARTGAME_H
#define STARTGAME_H

#include <QWidget>
#include <QMainWindow>
namespace Ui {
class StartGame;
}

class StartGame : public QWidget
{
    Q_OBJECT

public:
    explicit StartGame(QWidget *parent = nullptr);
    ~StartGame();

private slots:
    void on_startGameButton_clicked();

private:
    Ui::StartGame *ui;
};

#endif // STARTGAME_H
