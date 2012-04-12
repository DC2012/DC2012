/*------------------------------------------------------------------------------------
--  SOURCE FILE:    LandTile.cpp   -  a class for map tiles containing a sea graphic
--                                  which moveable game objects can be drawn on top of.
--
--  PROGRAM:
--
--  FUNCTIONS:      LandTile::LandTile() : type_ (SEA)
--                  LandTile :: LandTile(Point point) : type_ (SEA), position_(point)
--                  Tile :: getTileType
--                  Tile ::setPosition(int x, int y)
--                  Tile ::getPosition()
--                  Tile :: setGraphic()
--
--  DATE:           March 8th, 2012
--
--  REVISIONS:
--
--  DESIGNERS:      Mike Zobac
--
--  PROGRAMMERS:    Mike Zobac
--
--  NOTES:
-------------------------------------------------------------------------------------*/


#include "landtile.h"

/*-----------------------------------------------------------------------------------
--  FUNCTION:       LandTile default ctor. - sets the tile type variable to sea.
--
--  DATE:           March 8th, 2012
--
--  DESIGNER:       Mike Zobac
--
--  PROGRAMMER:     Mike Zobac
--
--  INTERFACE:      LandTile::LandTile() : type_ (SEA)
--
--  NOTES:          Sets the type_ variable to SEA.  The TileGraphicObject uses this
--                  value to instanciate a propper graphic for that tile.
-------------------------------------------------------------------------------------*/

LandTile::LandTile(Point position)
    : Tile(QPixmap(TILE_LAND1), position, LAND)
{
  
}


/*-----------------------------------------------------------------------------------
--  FUNCTION:       Set Graphic - instanciates a TileGraphicObject and assigns it to
--                      this tile.
--
--  DATE:           March 9th, 2012
--
--  DESIGNER:       Mike Zobac
--
--  PROGRAMMER:     Mike Zobac
--
--  INTERFACE:      void setGraphic(int type_, Point position_);
--
--  RETURNS:        void
--
--  NOTES:
-------------------------------------------------------------------------------------*/

/*
void LandTile::setGraphic()
{
    graphic_ = new TileGraphicsObject(getPosition(), LAND);
}
*/
