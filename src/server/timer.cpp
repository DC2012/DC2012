#include "servermain.h"

int timer_start(PTIMER ptimer, PDATA pdata)
{
    // initializing data structure
    // and starting the server
    pdata->server = Server::getInstance();
    pdata->server->listen(pdata->portnum);
    pdata->isRunning = 1;
    pdata->objCount = 0;
    pdata->lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(pdata->lock, NULL);
    
    // initializing timer structure
    ptimer->sev.sigev_notify = SIGEV_THREAD;
    ptimer->sev.sigev_value.sival_ptr = pdata;
    ptimer->sev.sigev_notify_attributes = 0;
    ptimer->sev.sigev_notify_function = update; // update function is defined in update.cpp
    
    if(timer_create(CLOCK_REALTIME, &(ptimer->sev), &(ptimer->timerID)) == -1)
        return 0;
    
    ptimer->spec.it_interval.tv_sec = 0;
    ptimer->spec.it_interval.tv_nsec = 1000000000 / FRAME_RATE; // FRAME_RATE is defined in servermain.h
    ptimer->spec.it_value.tv_sec = ptimer->spec.it_interval.tv_sec;
    ptimer->spec.it_value.tv_nsec = ptimer->spec.it_interval.tv_nsec;
    
    if(timer_settime(ptimer->timerID, 0, &(ptimer->spec), 0) == -1)
        return 0;
    
    return 1;
}

void timer_cleanup(PTIMER ptimer, PDATA pdata)
{
    free(pdata->lock);
}