#include "servermain.h"

void update(sigval arg)
{
    PDATA pdata = (PDATA)arg.sival_ptr;
    Server *server;
    Message sendMsg;
    std::map<int, GameObject*>::iterator ii;
    
    // ***** lock mutex
    pthread_mutex_lock(pdata->lock);
    
    server = pdata->server;
    
    // move the projectiles and send UPDATE messages to all clients
    for(ii = pdata->projectiles.begin(); ii != pdata->projectiles.end(); ++ii)
    {
        ((GOM_Projectile *)(ii->second))->move();
        sendMsg.setAll(ii->second->toString(), Message::UPDATE);
        server->write(&sendMsg);
    }
    
    // send UPDATE messages of objects to all clients
    for(ii = pdata->ships.begin(); ii != pdata->ships.end(); ++ii)
    {
        sendMsg.setAll(ii->second->toString(), Message::UPDATE);
        server->write(&sendMsg);
    }
    
    // unlock mutex *****
    pthread_mutex_unlock(pdata->lock);
}