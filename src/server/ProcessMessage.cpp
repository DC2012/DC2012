#include "servermain.h"

void ProcessMessage(PDATA pdata)
{
    GameObject* gameObject;
    Server*  server = Server::getInstance();
    Message* recvMessage;
    Message  sendMessage;
    int clientID;
    std::string data;
    std::ostringstream osstream;
    std::istringstream isstream;

    // object creation parameters
    int type, objID, degree, posX, posY, playerID, speed, health, attack,
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

            if(sendMessage.setAll(data, Message::STATUS))
                server->write(sendMessage, clientID);

            // create a string for GameObjectFactory to create the ship
                // setting up all the parameters
            type     = SHIP1;
            objID    = 1;       // hard-coded need to fix 
            degree   = 0;       // hard-coded need to fix 
            posX     = 500;     // hard-coded need to fix 
            posY     = 600;     // hard-coded need to fix 
            playerID = clientID;
            speed    = 0;
            health   = 100;     // hard-coded need to fix 
            attack   = 30;      // hard-coded need to fix 
            end      = SHIP_STR;

            // create the GOM_Ship object
            gameObject = GOM_Ship (type, objID, degree, posX, posY,
                                   playerID, speed, health, attack);
            // add to map still needs to be implemented 

            //Send CREATION message to all clients
            if(sendMessage.setAll(gameObject->toString(), Message::CREATION))
            {
                server->write(sendMessage);
            }
            else
            {
                //std::cout << "Error: data too long" << std::endl;
            }
            break;

        case Message::ACTION:
            // create a string for GameObjectFactory to create the projectile
                // parsing all the parameters
            isstream = std::istringstream(recvMessage->getData());
            isstream >> type >> objID >> degree >> posX >> posY;
            isstream >> playerID >> speed >> ttl >> damage >> endCheck;

            if(!isstream.good() || endCheck != PROJECTILE_STR)
                break;

            // assigns the appropriate objID
            objID = 2;  // hard-coded need to fix 

            // create the GOM_Projectile object
            gameObject = GOM_Projectile (type, objID, degree, posX, posY,
                                         playerID, speed, ttl, damage);
            // add to map still needs to be implemented 

            //Send CREATION message to all clients
            if(sendMessage.setAll(gameObject->toString(), Message::CREATION))
            {
                server.write(sendMessage);
            }
            else
            {
                std::cout << "Error: data too long" << std::endl;
            }
            break;


        case Message::UPDATE:
            // use clientID to find relevant ship in a map 
            clientID = recvMessage->getID();
            // update the ship with the message data
            gameObject->update(recvMessage->getData());

            // echo the UPDATE message to all clients
            // fall-through

        case Message::CHAT:
            //echo to all clients
            sendMessage = *recvMessage;
            server.write(sendMessage);
            break;
        }// end of swtich()
    }// end of while()
}