#include "servermain.h"

void ProcessMessage(PDATA pdata)
{
    GameObject* gameObject;
    Server*  server = pdata->server;
    Message* recvMessage;
    Message  sendMessage;
    int clientID;
    std::string data;
    std::ostringstream ostr;

    // object creation parameters
    ObjectType type;
    int objID, degree, posX, posY, playerID, speed, health, attack,
        damage, ttl;
    char end;
    
    while(pdata->isRunning && (recvMessage = server->read()))
    {
        switch(recvMessage->getType())
        {
        case Message::CONNECTION:
            // send STATUS message to notify a client its cliendID
            clientID = recvMessage->getID();
            sendMessage.setID(clientID);
            
            ostr.clear();
            ostr.str("");
            ostr << clientID;

            if(sendMessage.setAll(ostr.str(), Message::STATUS))
                server->write(&sendMessage, clientID);
                
            // ***** lock mutex
            pthread_mutex_lock(pdata->lock);

            // create a string for GameObjectFactory to create the ship
                // setting up all the parameters
            type     = SHIP1;
            objID    = pdata->objCount++;
            degree   = 0;       // hard-coded need to fix 
            posX     = 500;     // hard-coded need to fix 
            posY     = 600;     // hard-coded need to fix 
            playerID = clientID;
            speed    = 0;
            health   = 100;     // hard-coded need to fix 
            attack   = 30;      // hard-coded need to fix 

            // create the GOM_Ship object
            gameObject = new GOM_Ship(objID, type, degree, posX, posY,
                                   playerID, speed, health, attack);
            
            // add the game object to the map
            if(pdata->objects[objID] != NULL)
                delete pdata->objects[objID];
            pdata->objects[objID] = gameObject;
            
            // unlock mutex *****
            pthread_mutex_unlock(pdata->lock);

            //Send CREATION message to all clients
            if(sendMessage.setAll(gameObject->toString(), Message::CREATION))
            {
                server->write(&sendMessage);
            }
            else
            {
                //std::cout << "Error: data too long" << std::endl;
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
            if(pdata->projectiles[objID] != NULL)
                delete pdata->projectiles[objID];
            
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
                //std::cout << "Error: data too long" << std::endl;
            }
            break;


        case Message::UPDATE:
            data = recvMessage->getData();
            if((objID = GameObjectFactory::getObjectID(data)) == -1)
                break;
            
            // ***** lock mutex
            pthread_mutex_lock(pdata->lock);
            
            // update only if the object exist
            if(pdata->objects[objID] != NULL)
                pdata->objects[objID]->update(data);
            
            // unlock mutex *****
            pthread_mutex_unlock(pdata->lock);
            break;

        case Message::CHAT:
            //echo to all clients
            sendMessage = *recvMessage;
            server->write(&sendMessage);
            break;
        }// end of swtich()
    }// end of while()
}