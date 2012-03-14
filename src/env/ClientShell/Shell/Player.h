#ifndef Player_H
#define Player_H

#include <QMap>
#include <QThread>
#include <QTimer>
#include <QObject>
#include <stdlib.h>
#include <iostream>

class   MyThread : public QThread
{
public:
    void run();
};



class Player : public QObject
{

    Q_OBJECT

public:
    Player();

public slots:
    void updateplayer();

};

#endif // Player_H
