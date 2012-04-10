#include "servermain.h"

void update(sigval arg)
{
    PDATA pdata = (PDATA)arg.sival_ptr;
    Server *server;
    Message sendMsg;
    std::map<int, GameObject*>::iterator ii, iii;
    std::ostringstream ostr;
    GOM_Projectile *projectile;
    GOM_Ship *ship;
    
    // ***** lock mutex
    pthread_mutex_lock(pdata->lock);
    
    server = pdata->server;
    
    // move the projectiles and do hit detection
    for(ii = pdata->projectiles.begin(); ii != pdata->projectiles.end(); ++ii)
    {
        projectile = (GOM_Projectile *)(ii->second);

        //  move() returns true if ttl_ is 0
        if(projectile->move())
        {
            //  remove the projectile from map is true
            pdata->projectiles.erase(ii->first);
        }
        else
        {
            // check collision with ships
            for(iii = pdata->ships.begin(); iii != pdata->ships.end(); ++iii)
            {
                ship = (GOM_Ship *)(iii->second);
                if((ship->getPlayerID() != projectile->getPlayerID())
                    && ship->getHitbox().isCollision(projectile->getHitbox()))
                {
                    // send HIT msg to the collided client
                    ostr.clear();
                    ostr << ship->getObjID();
                    sendMsg.setID(ship->getPlayerID());
                    sendMsg.setAll(ostr.str(), Message::HIT);
                    server->write(&sendMsg, ship->getPlayerID());

                    // send DELETION msg for the projectile to all clients
                    ostr.clear();
                    ostr.str("");
                    ostr << "P" << " " << projectile->getObjID() << " 0";
                    sendMsg.setAll(ostr.str(), Message::DELETION);
                    server->write(&sendMsg);
                    std::cout << "sent deletion: " << sendMsg.getData() << "\n";

                    // delete the projectile
                    pdata->projectiles.erase(ii->first);

                    break;
                }
            } // end of for
        } // end of if-else
    } // end of for
    
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
