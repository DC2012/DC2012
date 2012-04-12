/*------------------------------------------------------------------------------------
--  SOURCE FILE:    SeaTile.cpp   -  a class for map tiles containing a sea graphic
--                                  which moveable game objects can be drawn on top of.
--
--  PROGRAM:
--
--  FUNCTIONS:      SeaTile::SeaTile() : type_ (SEA)
--                  SeaTile :: SeaTile(Point point) : type_ (SEA), position_(point)
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


#include "seatile.h"

/*-----------------------------------------------------------------------------------
--  FUNCTION:       SeaTile default ctor. - sets the tile type variable to sea.
--
--  DATE:           March 8th, 2012
--
--  DESIGNER:       Mike Zobac
--
--  PROGRAMMER:     Mike Zobac
--
--  INTERFACE:      SeaTile::SeaTile() : type_ (SEA)
--
--  NOTES:          Sets the type_ variable to SEA.  The TileGraphicObject uses this
--                  value to instanciate a propper graphic for that tile.
-------------------------------------------------------------------------------------*/

SeaTile::SeaTile(Point position)
    : Tile(QPixmap(TILE_WATER1), position, SEA)
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
void SeaTile::setGraphic()
{
    graphic_ = new TileGraphicsObject(getPosition(), Sea);
}
*/
