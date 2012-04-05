#ifndef SERVERMAIN_H_
#define SERVERMAIN_H_

// networking includes
//#include "../net/Server.h"
//#include "../net/Message.h"

// game object includes
/*
#include "../player/ObjectType.h"
#include "../player/GameObject.h"
#include "../player/ObjectStringCheck.h"
#include "../player/GameObjectFactory.h"
#include "../player/GOM_Ship.h"
#include "../player/GOM_Projectile.h"
#include "../player/GOS_Obstacle.h"
#include "../player/GOS_PowerUp.h"

#include <iostream>
#include <string>
#include <map>
*/

// C style linkage:
extern "C"
{
    #include <stdlib.h>
    #include <signal.h>
    #include <stdio.h>
    #include <pthread.h>
    #include <time.h>

    // frame rate (update frequency)
    #define FRAME_RATE 30

    // server data structure
    typedef struct
    {
        int isRunning;
        pthread_mutex_t *lock;
        //std::map<int, GameObject *>objects;
        //std::map<int, GameObject *>projectile;
    } DATA, *PDATA;

    // timer data
    typedef struct
    {
        sigevent sev;
        itimerspec spec;
        timer_t timerID;
    } TIMER, *PTIMER;
    
    #include "timer.h"
    //#include "ProcessMessage.h"
}

#endif