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
--                  Roger Fan
--
--  NOTES:
--                  This will be the entry point for the game server.
-----------------------------------------------------------------------------*/
#include "servermain.h"

int main(int argc, char **argv)
{
    DATA data;
    TIMER timer;
    
    switch(argc)
    {
    case 1:
        data.portnum = DEFAULT_SV_PORT;
        break;
    case 2:
        data.portnum = atoi(argv[1]);
        break;
    default:
        fprintf(stderr, "Usage: %s [port]\n", argv[0]);
        exit(0);
    }
    
    // this starts the server as well
    timer_start(&timer, &data);
    printf("server started: listening on port %d\n\n", data.portnum);
    
    // start processing messages
    ProcessMessage(&data);
    
    return 0;
}