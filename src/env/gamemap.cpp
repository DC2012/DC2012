/*------------------------------------------------------------------------------
--  SOURCE FILE:    GameMap.cpp - creates the map of tiles on which the GameObjects
--                  are instaciated and the game is played.
--
--  PROGRAM:
--
--  FUNCTIONS:      GameMap :: GameMap(QString fileName)
--                  GameMap :: GameMap(int xSize, int ySize)
--                  GameMap::GameMap()
--
--  DATE:           March 10, 2012
--
--  REVISIONS:
--
--  DESIGNERS:      Mike Zobac
--
--  PROGRAMMERS:    Mike Zobac
--
--  NOTES:
----------------------------------------------------------------------------------*/



#include "gamemap.h"
#include "landtile.h"
#include "seatile.h"

/*-----------------------------------------------------------------------------------
--  FUNCTION:   Default GameMap ctor
--
--  DATE:       March 8, 2012
--
--  DESIGNER:   Mike Zobac
--
--  PROGRAMMER: Mike Zobac
--
--  INTERFACE:  GameMap::GameMap()
--
--  NOTES:
-------------------------------------------------------------------------------------*/


GameMap::GameMap()
{

}


/*-----------------------------------------------------------------------------------
--  FUNCTION:   GameMap ctor - creates and x X y map of tiles, with a perimeter of
--              LandTiles, and an interior of SeaTiles
--
--  DATE:       March 10, 2012
--
--  DESIGNER:   Mike Zobac
--
--  PROGRAMMER: Mike Zobac
--
--  INTERFACE:  GameMap :: GameMap(int xSize, int ySize)
--
--  NOTES:      This function is for creating a basic map used to test other game
--              functions.
-------------------------------------------------------------------------------------*/


GameMap :: GameMap(int xSize, int ySize)
{
    for(int i = 0; i < xSize; i++)
    {
        for(int j = 0; j < ySize; j++)
        {
            if(i == 0 || i == xSize - 1 || j == 0 || j == ySize - 1)
            {
                gameTiles_[i][j] = new LandTile(Point(xSize, ySize));
            }
            else
            {
                gameTiles_[i][j] = new SeaTile(Point(xSize, ySize));
            }
        }
    }
}


/*------------------------------------------------------------------------------------
--  FUNCTION:   GameMap ctor - reads a map of tiles from and xml file and instanciates
--                   that map.
--
--  DATE:
--
--  DESIGNER:   Mike Zobac
--
--  PROGRAMMER: Mike Zobac
--
--  INTERFACE:  GameMap :: GameMap(QString fileName)
--
--  NOTES:
-------------------------------------------------------------------------------------*/

GameMap :: GameMap(QString fileName)
{

}

