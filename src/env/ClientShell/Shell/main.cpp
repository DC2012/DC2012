//#include "graphicarea.h"
#include "shipcomponent.h"
#include "main.h"
#include "../../menus/mainwindow.h"

#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // client player;
    QMap<int , GameObjectMoveable*> ships;

    //server assigns ship ID later
    GOM_Ship *myship;

    //QMap<int, int> bullets;
    //keyInput k;
    //QKeyEvent *keypress = new QKeyEvent(QEvent::KeyPress, Qt::Key_W, Qt::NoModifier, "w" ,false, 1);
    //char keypressed;

    //QTimer *timer = new QTimer(&player);
    GameMap *map = new GameMap(10, 10);
    MainWindow window;

    window.show();
    return app.exec();
}
