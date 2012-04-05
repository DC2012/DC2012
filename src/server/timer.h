#ifndef TIMER_H_
#define TIMER_H_

// C style linkage:
extern "C"
{
    #include "servermain.h"
    #include "update.h"
    
    // function prototypes
    int timer_start(PTIMER ptimer, PDATA pdata);
    void timer_cleanup(PTIMER ptimer, PDATA pdata);
}

#endif