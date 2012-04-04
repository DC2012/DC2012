/*-----------------------------------------------------------------------------
--  PROGRAM NAME:
--                  GameServer
--  FUNCTIONS:
--
--
--  DATE:
--                  April 3, 2012
--  REVISIONS:
--
--  DESIGNER:
--                  James Rupert
--                  Po Hsu
--                  Roger Fan
--  PROGRAMMER:
--                  Po Hsu
--
--  NOTES:
--                  This will be the entry point for the game server.
-----------------------------------------------------------------------------*/
#include "../net/Server.h"
#include "../net/Message.h"
#include "../player/ObjectType.h"
#include "../player/GameObject.h"
#include "../player/GameObjectFactory.h"
#include <iostream>
#include <stringstream>
#include <string>

const char ws = ' ';

int main (int argc, char **argv)
{
    GameObjectFactory gameObjectFactory;
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

    while((recvMessage = server->read()))
    {
        switch(recvMessage->getType())
        {
        case Message::CONNECTION:
            data.clear();
            // send STATUS message to notify a client its cliendID
            clientID = recvMessage->getID();
            sendMessage.setID(clientID);

            if(sendMessage.setAll(data, Message::STATUS))
                server.write(sendMessage, clientID);

            // create a string for GameObjectFactory to create the ship
                // setting up all the parameters
            type     = SHIP1;
            objID    = 1;       /* hard-coded need to fix */
            degree   = 0;       /* hard-coded need to fix */
            posX     = 500;     /* hard-coded need to fix */
            posY     = 600;     /* hard-coded need to fix */
            playerID = clientID;
            speed    = 0;
            health   = 100;     /* hard-coded need to fix */
            attack   = 30;      /* hard-coded need to fix */
            end      = SHIP_STR;
            osstream = std::ostringstream(data);
                // contructing the message
            osstream << type << ws << objID << ws << degree << ws;
            osstream << posX << ws << posY << ws << playerID << ws << speed << ws;
            osstream << health << ws << attack << end;

            data = osstream.str();

            // create the GOM_Ship object
            gameObject = gameObjectFactory.create(data);
            /* add to map still needs to be implemented */

            //Send CREATION message to all clients
            if(sendMessage.setAll(data, Message::CREATION))
            {
                server.write(sendMessage);
            }
            else
            {
                std::cout << "Error: data too long" << std::endl;
            }

            /* iterate through all objects on the server and send CREATION messages to new client */
            /* thread this shit */
            break;

        case Message::ACTION:
            data.clear();
            // create a string for GameObjectFactory to create the projectile
                // parsing all the parameters
            isstream = std::istringstream(recvMessage->getData());
            isstream >> type >> objID >> degree >> posX >> posY;
            isstream >> playerID >> speed >> ttl >> damage >> endCheck;

            if(!isstream.good() || endCheck != PROJECTILE_STR)
                break;

            objID = 2;  /* hard-coded need to fix */
            sstream  = std::stringstream(data);
                // recontructing the message
            osstream << type << ws << objID << ws << degree << ws;
            osstream << posX << ws << posY << ws << playerID << ws << speed << ws;
            osstream << damage << ws << ttl << end;

            data = osstream.str();

            // create the GOM_Projectile object
            gameObject = gameObjectFactory.create(data);
            /* add to map still needs to be implemented */

            //Send CREATION message to all clients
            if(sendMessage.setAll(data, Message::CREATION))
            {
                server.write(sendMessage);
            }
            else
            {
                std::cout << "Error: data too long" << std::endl;
            }
            break;


        case Message::UPDATE:
            /* use clientID to find relevant ship in a map */
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
    }// end of while
}// end of main