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


    /*class map here*/



    //load tylers code        //tylers code here, or in constructor? (menu)

    //init jamies code here when player hits connect with tylers menu


    //timer signal goes here to read from server
    QTimer::connect(timer, SIGNAL(timeout()), &player, SLOT(updateplayer()));
    timer->start(300);

    //execute drawing code for map and player when timer goes off


    while(true)
    {
        /*
            THE KEYPRESS EVENT THAT THIS USES IS NOT CORRECT

            NEED TO FIND A WAY TO CREATE A SINGLE EVENT FOR 4 DIFFERENT KEYS

        */
        keypressed = k.keyPressEvent(keypress);
        switch(keypressed)
        {
            //when key is pressed fill object data with new position
            case 'w':
            case 's':
            case 'a':
            case 'd':
            default:
                break;
        }

        //continously call functions to read player movement(chris functions)

        //update ship and bullet info
    }
    return app.exec();
}
