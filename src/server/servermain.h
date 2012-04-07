#ifndef SERVERMAIN_H_
#define SERVERMAIN_H_

// C style linkage:
extern "C"
{
    extern "C++"
    {
        // networking includes
        #include "../net/Server.h"
        #include "../net/Message.h"

        // game object includes
        #include "../player/ObjectType.h"
        #include "../player/GameObject.h"
        #include "../player/ObjectStringCheck.h"
        #include "../player/GameObjectFactory.h"
        #include "../player/GOM_Ship.h"
        #include "../player/GOM_Projectile.h"
        #include "../player/GOS_Obstacle.h"
        #include "../player/GOS_PowerUp.h"
        #include "../player/Point.h"
        
        #include <iostream>
        #include <string>
        #include <map>
        #include <vector>
        #include <limits>
        #include <sstream>
    }
    
    #include <stdlib.h>
    #include <signal.h>
    #include <stdio.h>
    #include <pthread.h>
    #include <time.h>
    #include <errno.h>

    #define FRAME_RATE 30 // frame rate (update frequency)
    #define DEFAULT_SV_PORT 9900 // default server listen port
    #define MAX_PLAYERS 8
    
    // server data structure
    typedef struct
    {
        int isRunning;
        int objCount;
        unsigned short portnum;
        Server *server;
        pthread_mutex_t *lock;
        std::map<int, GameObject *>ships;
        std::map<int, GameObject *>projectiles;
        std::map<int, std::string>clients;
    } DATA, *PDATA;
    
    // timer data
    typedef struct
    {
        sigevent sev;
        itimerspec spec;
        timer_t timerID;
    } TIMER, *PTIMER;
    
    // function prototypes
    int timer_start(PTIMER ptimer, PDATA pdata);
    void timer_cleanup(PTIMER ptimer, PDATA pdata);
    void update(sigval arg);
    void ProcessMessage(PDATA pdata);
    Point getStartPoint(const std::map<int, GameObject *> &ships);
}

#endif