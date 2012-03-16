#include "graphics/gamewindow.h"
#include "env/menus/Ships/mainwindow.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    MainWindow menu;
    menu.show();

    return app.exec();
}
