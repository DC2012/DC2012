#include "servermain.h"

void ProcessMessage(PDATA pdata)
{
    GameObject* gameObject;
    Server*  server = pdata->server;
    Message* recvMessage;
    Message  sendMessage;
    int clientID;
    std::string data;
    std::string playerName;
    std::istringstream istr;
    std::map<int, GameObject*>::iterator ii;

    // object creation parameters
    int type, objID, degree, posX, posY, playerID, speed, health, attack,
        damage, ttl;
    char end;
    
    while(pdata->isRunning && (recvMessage = server->read()))
    {
        clientID = recvMessage->getID();
        sendMessage.setID(clientID);
        
        switch(recvMessage->getType())
        {
        case Message::CONNECTION:
            // extract ship type and player name from message data
            istr.clear();
            istr.str(recvMessage->getData());
            istr >> type >> playerName;
            
            // ***** lock mutex
            pthread_mutex_lock(pdata->lock);
            
            
            //!!! needs to implement max player checking here!!!
            data = std::string("Accepted");
            // add new client to the clients map
            pdata->clients.erase(clientID);
            pdata->clients[clientID] = playerName;
            
            printf("client (ID: %d) connected\n", clientID);

            if(sendMessage.setAll(data, Message::CONNECTION))
                server->write(&sendMessage, clientID);
            //!!! needs to implement max player checking here!!!
            
            // send CREATION message for every object in the maps to the client
            for(ii = pdata->projectiles.begin(); ii != pdata->projectiles.end(); ++ii)
            {
                sendMessage.setAll(ii->second->toString(), Message::CREATION);
                server->write(&sendMessage, clientID);
            }
            
            for(ii = pdata->ships.begin(); ii != pdata->ships.end(); ++ii)
            {
                sendMessage.setAll(ii->second->toString(), Message::CREATION);
                server->write(&sendMessage, clientID);
            }
            
            // create a string for GameObjectFactory to create the ship
                // setting up all the parameters
            objID    = pdata->objCount++;
            degree   = 0;       // hard-coded need to fix 
            posX     = 150 * pdata->clients.size();     // hard-coded need to fix 
            posY     = 300;     // hard-coded need to fix 
            playerID = clientID;
            speed    = 0;
            health   = 100;     // hard-coded need to fix 
            attack   = 30;      // hard-coded need to fix 

            // create the GOM_Ship object
            gameObject = new GOM_Ship(ObjectType(type), objID, degree, posX, posY,
                                   playerID, speed, health, attack);
            
            // add the game object to the map
            pdata->ships.erase(objID);
            pdata->ships[objID] = gameObject;
            
            // unlock mutex *****
            pthread_mutex_unlock(pdata->lock);

            //Send CREATION message to all clients
            if(sendMessage.setAll(gameObject->toString(), Message::CREATION))
            {
                server->write(&sendMessage);
            }
            else
            {
                printf("ERROR(client ID: %d): unable to echo CREATION message\n");
            }
            break;

        case Message::ACTION:
            // create a projectile object
            gameObject = GameObjectFactory::create(recvMessage->getData());
            
            if(gameObject->getType() != PROJECTILE)
                break;
            
            // ***** lock mutex
            pthread_mutex_lock(pdata->lock);
            
            objID = pdata->objCount++;
            
            // assign object id to the projectile object
            gameObject->setObjID(objID);
            
            // add projectile object to the projectil map
            pdata->projectiles.erase(objID);
            pdata->projectiles[objID] = gameObject;
            
            // unlock mutex *****
            pthread_mutex_unlock(pdata->lock);

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
        
        /* Message::DEATH not implemented yet
        case Message::DEATH:
            break;
        */

        case Message::UPDATE:
            data = recvMessage->getData();
            
            // retrieve object's ID from the data string
            if((objID = GameObjectFactory::getObjectID(data)) == -1)
                break;
            
            // ***** lock mutex
            pthread_mutex_lock(pdata->lock);
            
            // update only if the object exists
            if(pdata->ships[objID] != NULL)
                pdata->ships[objID]->update(data);
            
            // unlock mutex *****
            pthread_mutex_unlock(pdata->lock);
            
            // echo the UPDATE message to all clients
            // fall through

        case Message::CHAT:
            //echo to all clients
            sendMessage = *recvMessage;
            server->write(&sendMessage);
            break;
        }// end of swtich()
    }// end of while()
}