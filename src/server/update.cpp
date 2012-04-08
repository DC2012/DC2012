#include "servermain.h"

void update(sigval arg)
{
    PDATA pdata = (PDATA)arg.sival_ptr;
    Server *server;
    Message sendMsg;
    std::map<int, GameObject*>::iterator ii, iii;
    GOM_Projectile *projectile;
    GOM_Ship *ship;
    
    // ***** lock mutex
    pthread_mutex_lock(pdata->lock);
    
    server = pdata->server;
    
    // move the projectiles and do hit detection
    for(ii = pdata->projectiles.begin(); ii != pdata->projectiles.end(); ++ii)
    {
        // move the projectile
        projectile = (GOM_Projectile *)(ii->second);
        projectile->move();
        // check collision with ships
        for(iii = pdata->ships.begin(); iii != pdata->ships.end(); ++iii)
        {
            ship = (GOM_Ship *)(iii->second);
            if(projectile->getHitbox().isCollision(ship->getHitbox()))
            {
                // send HIT msg to collided client

                // send DELETION msg for the projectile to all clients

                break;
            }
        }
    }
    
    // send UPDATE messages of objects to all clients
    for(ii = pdata->ships.begin(); ii != pdata->ships.end(); ++ii)
    {
        sendMsg.setID(((GOM_Ship*)ii->second)->getPlayerID());
        sendMsg.setAll(ii->second->toString(), Message::UPDATE);
        server->write(&sendMsg);
    }
    
    // unlock mutex *****
    pthread_mutex_unlock(pdata->lock);
}
