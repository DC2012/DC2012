#include "servermain.h"

void update(sigval arg)
{
    PDATA pdata = (PDATA)arg.sival_ptr;
    Server *server;
    Message sendMsg;
    std::map<int, GameObject*>::iterator ii, iii, itShip, iitShip;
    std::map<int, GameObject*>::iterator ii_copy, itShip_copy;
    std::ostringstream ostr;
    GOM_Projectile *projectile;
    GOM_Ship *ship, *bship;
    
    // ***** lock mutex
    pthread_mutex_lock(pdata->lock);
    
    server = pdata->server;
    
    // move the projectiles and do hit detection
    for(ii = pdata->projectiles.begin(); ii != pdata->projectiles.end();)
    {
        ii_copy = ii;
        projectile = (GOM_Projectile *)(ii->second);

        //  move() returns true if ttl_ is 0
        if(projectile->move())
        {
            //  remove the projectile from map is true
            ++ii;
            delete pdata->projectiles[ii_copy->first];
            pdata->projectiles.erase(ii_copy->first);
        }
        else
        {
            ++ii;
            // check collision with ships
            for(iii = pdata->ships.begin(); iii != pdata->ships.end(); ++iii)
            {
                ship = (GOM_Ship *)(iii->second);
                if((ship->getPlayerID() != projectile->getPlayerID())
                    && ship->getHitbox().isCollision(projectile->getHitbox()))
                {
                    // send HIT msg to the collided client
                    ostr.clear();
                    ostr << projectile->getObjID();
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
                    delete pdata->projectiles[ii_copy->first];
                    pdata->projectiles.erase(ii_copy->first);

                    break;
                }
            } // end of for
        } // end of if-else
    } // end of for

    // do hit detection on all ships against all other ships
    for(itShip = pdata->ships.begin(); itShip != pdata->ships.end();)
    {
        itShip_copy = itShip;
        ship = (GOM_Ship *)(itShip->second);

        ++itShip;
        // check collision with ships
        for(iitShip = pdata->ships.begin(); iitShip != pdata->ships.end(); ++iitShip)
        {
            bship = (GOM_Ship *)(iitShip->second);
            // if we are checking a ship against itself, continue
            if(ship == bship)
              continue;
            if(ship->getHitbox().isCollision(bship->getHitbox()))
            {
                // send DELETION msg for both ships to all clients
                ostr.clear();
                ostr.str("");
                ostr << "S" << " " << ship->getObjID() << " 0";
                sendMsg.setID(itShip->first);
                sendMsg.setAll(ostr.str(), Message::DELETION);
                server->write(&sendMsg);
                std::cout << "sent deletion: " << sendMsg.getData() << "\n";

                ostr.clear();
                ostr.str("");
                ostr << "S" << " " << bship->getObjID() << " 0";
                sendMsg.setID(iitShip->first);
                sendMsg.setAll(ostr.str(), Message::DELETION);
                server->write(&sendMsg);
                std::cout << "sent deletion: " << sendMsg.getData() << "\n";

                // delete the ships
                delete pdata->ships[itShip_copy->first];
                delete pdata->ships[iitShip->first];
                std::cout << "free memory done" << std::endl;
                pdata->ships.erase(itShip_copy->first);
                pdata->ships.erase(iitShip->first);
                std::cout << "map erase done" << std::endl;

                break;
            }
        } // end of for
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
