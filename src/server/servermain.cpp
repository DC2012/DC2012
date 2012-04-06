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

int main()
{
    DATA data;
    TIMER timer;
    
    timer_start(&timer, &data);
    ProcessMessage(&data);
    
    return 0;
}