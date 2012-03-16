#include "graphics/gamewindow.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    GameWindow *gameWindow = new GameWindow();

    gameWindow->setFocus();
    gameWindow->start();

    return app.exec();
}
