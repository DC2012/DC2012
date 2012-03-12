//#include "graphicarea.h"
#include "shipcomponent.h"
#include "main.h"
#include "client.h"
#include "keyinput.h"
#include "mouseEvent.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    client player;
    QMap<int ,int> ships;
    QMap<int, int> bullets;
    keyInput k;
    QKeyEvent *keypress = new QKeyEvent(QEvent::KeyPress, Qt::Key_W, Qt::NoModifier, "w" ,false, 1);
    char keypressed;

    QTimer *timer = new QTimer(&player);


    return app.exec();
}
