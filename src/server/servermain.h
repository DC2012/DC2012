#ifndef SERVERMAIN_H_
#define SERVERMAIN_H_

// C style linkage:
extern "C"
{
    extern "C++"
    {
        // networking includes
        //#include "../net/Server.h"
        //#include "../net/Message.h"

        // game object includes
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
        
        #include <stdlib.h>
        #include <signal.h>
        #include <stdio.h>
        #include <pthread.h>
        #include <time.h>
    }

    // frame rate (update frequency)
    #define FRAME_RATE 30
    
    // server data structure
    typedef struct
    {
        int isRunning;
        pthread_mutex_t *lock;
        std::map<int, GameObject *>objects;
        std::map<int, GameObject *>projectile;
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
}

#endif