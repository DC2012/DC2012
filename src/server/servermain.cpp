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
    std::stringstream sstream;

    // object creation parameters
    int type, objID, degree, posX, posY, playerID, speed, health, attack,
        damage, ttl;
    char end;

    while((recvMessage = server->read()))
    {
        switch(recvMessage->getType())
        {
        case Message::CONNECTION:
            // send STATUS message to notify a client its cliendID
            clientID = recvMessage->getID();
            sendMessage.setID(clientID);
            data.clear();
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
            sstream = std::stringstream(data);
                // contructing the message
            sstream << type << ws << objID << ws << degree << ws;
            sstream << posX << ws << posY << ws << playerID << ws;
            sstream << speed << ws << health << ws << attack << end;

            data = sstream.str();

            // create the GOM_Ship object
            gameObject = gameObjectFactory.create(data);
            /* add to map still needs to be implemented */

            //Send CREATION message to all clients
            if(sendMessage.setAll(data, Message::CREATION))
                server.write(sendMessage);
        //iterate through all objects on the server and send CREATION messages to new client(can possibly be done in another thread)
        //    (assuming all objects have a toString() that you can give to a factory to recreate the object)

        //UPDATE message data should have a string representation of the object state, use this to modify the shipObjects
        case Message::UPDATE:
        //use clientID to find relevant ship in a map
        //take the data and update the ship appropriately
        //echo the update message to all clients

        //ACTION message data should be a string that can be used to create a projectile of whatever weapon type
        case Message::ACTION:
        //create a string that the factory can use to make the projectile, basically add in the objectID to it
        //create the projectil and add it to projectileMap
        //send CREATION message to all clients

        //CHAT message data is just text of the message currently, but could be modified later to make PM's not just global
        case Message::CHAT:
        //echo to all clients



        }
    }
}