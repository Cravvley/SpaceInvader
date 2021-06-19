#include "startgame.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartGame sg;
    sg.show();
    return a.exec();
}
