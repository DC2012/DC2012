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
    int clientID;
    std::string data;
    std::string playerName;
    std::istringstream istr;
    std::ostringstream ostr;
    std::map<int, GameObject*>::iterator ii;

    // object creation parameters
    int type, objID, degree, posX, posY, playerID, speed, health, attack;
    
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
            istr >> type >> playerName;
            
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
            
            // set the SendMessage's clientID back
            sendMessage.setID(clientID);
            
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

            //Send CREATION message to all clients
            if(sendMessage.setAll(gameObject->toString(), Message::CREATION))
            {
                server->write(&sendMessage);
                
                // debugging
                std::cout << "ship string for client#" << clientID << std::endl;
                std::cout << pdata->ships[objID]->toString() << std::endl;
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
                                            clientID, 5, 1000, 10);
            
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
            break;

        case Message::UPDATE:
            data = recvMessage->getData();
            
            // retrieve object's ID from the data string
            if((objID = GameObjectFactory::getObjectID(data)) == -1)
                break;
            
            // update only if the object exists
            if(pdata->ships[objID] != NULL)
                pdata->ships[objID]->update(data);
            
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
