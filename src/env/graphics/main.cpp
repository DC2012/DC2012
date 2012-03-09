//#include "graphicarea.h"
#include "shipcomponent.h"
#include "main.h"
#include "client.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    client player;
    QMap<int ,int> ships;
    QMap<int, int> bullets;
    QTimer *timer = new QTimer(&player);


    /*class map here*/



    //load tylers code        //tylers code here, or in constructor? (menu)

    //init jamies code here when player hits connect with tylers menu

    
    //timer signal goes here to read from server
    QTimer::connect(timer, SIGNAL(timeout()), &player, SLOT(player.updateplayer()));
    timer->start(300);

    //execute drawing code for map and player when timer goes off


    while(true)
    {
        //continously call functions to read player movement

        //update ship and bullet info
    }
    return app.exec();
}
