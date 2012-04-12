#include "servermain.h"

void ProcessMessage(PDATA pdata)
{
    GameObject* gameObject;
    
    // ***** lock mutex
    pthread_mutex_lock(pdata->lock);
    Server*  server = pdata->server;
    // unlock mutex *****
    pthread_mutex_unlock(pdata->lock);

    Message* recvMessage;
    Message  sendMessage;
    Point pt;
    int clientID;
    std::string data;
    std::string playerName;
    std::istringstream istr;
    std::ostringstream ostr;
    std::map<int, GameObject*>::iterator ii;

    // object creation parameters
    int type, objID, playerID, speed, health, attack;
    double degree, posX, posY;
    
    while(pdata->isRunning && (recvMessage = server->read()))
    {
        clientID = recvMessage->getID();
        sendMessage.setID(clientID);
        
        // ***** lock mutex
        pthread_mutex_lock(pdata->lock);
        
        switch(recvMessage->getType())
        {
        case Message::CONNECTION:
            // extract ship type and player name from message data
            istr.clear();
            istr.str(recvMessage->getData());
            istr >> playerName;
            
            // check if max player is reached on server
            if(pdata->ships.size() >= 8)
            {
                data = std::string("Refused");
                if(sendMessage.setAll(data, Message::CONNECTION))
                    server->write(&sendMessage, clientID);
                break;
            }

            data = std::string("Accepted");
            // add new client to the clients map
            pdata->clients.erase(clientID);
            pdata->clients[clientID] = playerName;
            
            printf("client (ID: %d) connected\n", clientID);

            if(sendMessage.setAll(data, Message::CONNECTION))
                server->write(&sendMessage, clientID);
            
            // send CREATION message for every object in the maps to the client
            for(ii = pdata->projectiles.begin(); ii != pdata->projectiles.end(); ++ii)
            {
                sendMessage.setID(((GOM_Ship*)ii->second)->getPlayerID());
                sendMessage.setAll(ii->second->toString(), Message::CREATION);
                server->write(&sendMessage, clientID);
                
                // debugging
                std::cout << ii->second->toString() << std::endl;
            }
            
            for(ii = pdata->ships.begin(); ii != pdata->ships.end(); ++ii)
            {
                sendMessage.setID(((GOM_Projectile*)ii->second)->getPlayerID());
                sendMessage.setAll(ii->second->toString(), Message::CREATION);
                server->write(&sendMessage, clientID);
                
                // debugging
                std::cout << ii->second->toString() << std::endl;
            }
            break;

        case Message::RESPAWN:
            // extract ship type from msg data
            istr.clear();
            istr.str(recvMessage->getData());
            istr >> type;

            // get a furthest start point from other ships
            pt = getStartPoint(pdata->ships);

            objID    = pdata->objCount++;
            degree   = 0;
            posX     = pt.getX();
            posY     = pt.getY();
            playerID = clientID;
            speed    = 0;
            health   = 100;     // hard-coded need to fix
            attack   = 30;      // hard-coded need to fix

            // create the GOM_Ship object
            gameObject = new GOM_Ship(ObjectType(type), objID, degree, posX, posY,
                                   playerID, speed, health, attack);

            // add the game object to the map
            pdata->ships.erase(clientID);
            pdata->ships[clientID] = gameObject;

            sendMessage.setID(clientID);

            //Send CREATION message to all clients
            if(sendMessage.setAll(gameObject->toString(), Message::CREATION))
            {
                server->write(&sendMessage);

                // debugging
                std::cout << "ship string for client#" << clientID << std::endl;
                std::cout << pdata->ships[clientID]->toString() << std::endl;
            }
            else
            {
                printf("ERROR(client ID: %d): unable to echo CREATION message\n");
            }
            break;

        case Message::ACTION:
            // extract projectile info from msg data
            istr.clear();
            istr.str(recvMessage->getData());
            istr >> posX >> posY >> degree;

            // create a projectile object
            objID = pdata->objCount++;
            gameObject = new GOM_Projectile(PROJECTILE, objID, degree, posX, posY,
                                            clientID, 9, 50, 10);

            // debugging
            //std::cout << "projectile (clientID:" << clientID << ") - ";
            //std::cout << gameObject->toString() << std::endl;
            //std::cout << "recved data: " << recvMessage->getData() << std::endl;
            
            // add projectile object to the projectil map
            pdata->projectiles.erase(objID);
            pdata->projectiles[objID] = gameObject;

            //Send CREATION message to all clients
            if(sendMessage.setAll(gameObject->toString(), Message::CREATION))
            {
                server->write(&sendMessage);
            }
            else
            {
                printf("ERROR(client ID: %d): unable to echo ACTION message\n");
            }
            break;

        case Message::DEATH:
            // send DELETION msg to all clients
            ostr.clear();
            ostr.str("");
            ostr << "S " << pdata->ships[clientID]->getObjID() << " 1";
            sendMessage.setAll(ostr.str(), Message::DELETION);
            server->write(&sendMessage);

            // delete the ship on server
            pdata->ships.erase(clientID);
            break;

        case Message::UPDATE:
            data = recvMessage->getData();
            
            // retrieve object's ID from the data string
            if((objID = GameObjectFactory::getObjectID(data)) == -1)
                break;
            
            // update only if the object exists
            if(pdata->ships[clientID] != NULL)
                pdata->ships[clientID]->update(data);

            //pdata->ships[objID]->printHitBox(std::cout);
            
            // echo the UPDATE message to all clients
            // fall through

        case Message::CHAT:
            //echo to all clients
            sendMessage = *recvMessage;
            server->write(&sendMessage);
            break;
        }// end of swtich()
        
        // unlock mutex *****
        pthread_mutex_unlock(pdata->lock);

        delete recvMessage;
    }// end of while()
}
