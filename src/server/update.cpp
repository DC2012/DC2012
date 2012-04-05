#include "servermain.h"

void update(sigval arg)
{
    PDATA pdata = (PDATA)arg.sival_ptr;
    
    // ***** lock mutex
    pthread_mutex_lock(pdata->lock);
    
    
    
    // unlock mutex *****
    pthread_mutex_unlock(pdata->lock);
}