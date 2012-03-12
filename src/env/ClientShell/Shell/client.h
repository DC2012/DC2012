#ifndef CLIENT_H
#define CLIENT_H

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



class client : public QObject
{

    Q_OBJECT

public:
    client();

public slots:
    void updateplayer();

};

#endif // CLIENT_H
