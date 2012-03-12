/*------------------------------------------------------------------------------------
--  SOURCE FILE:    landtile.cpp   -  a class for map tiles containing a sea graphic
--                                  which moveable game objects can be drawn on top of.
--
--  PROGRAM:
--
--  FUNCTIONS:      LandTile::LandTile() : type_ (LAND)
--                  LandTile :: LandTile(Point point) : type_ (LAND), position_(point)
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
--  INTERFACE:      LandTile::SeaTile() : type_ (LAND)
--
--  NOTES:          Sets the type_ variable to LAND.  The TileGraphicObject uses this
--                  value to instanciate a propper graphic for that tile.
-------------------------------------------------------------------------------------*/

LandTile::LandTile() : type_(LAND)
{
}

/*-----------------------------------------------------------------------------------
--  FUNCTION:       LandTile alternate ctor - takes in a point at which to create the
--                  tile.
--
--  DATE:           March 9th, 2012
--
--  DESIGNER:       Mike Zobac
--
--  PROGRAMMER:     Mike Zobac
--
--  INTERFACE:      LandTile :: Tile(Point point) : type_ (LAND), position_(point)
--
--  NOTES:          Sets the position_ variable to the point passed into the ctor.
-                   This is used by the GameMap object to create a map of tiles at
--                  various map positions.
-------------------------------------------------------------------------------------*/

LandTile :: LandTile(Point point) : type_(LAND), position_(point)
{    
}

/*-----------------------------------------------------------------------------------
--  FUNCTION:       Get Tile Type - returns the type of this tile
--
--  DATE:           March 8th, 2012
--
--  DESIGNER:       Mike Zobac
--
--  PROGRAMMER:     Mike Zobac
--
--  INTERFACE:      int getTileType();
--
--  RETURNS:        the int representing the tile type of this tile
--
--  NOTES:
-------------------------------------------------------------------------------------*/

Tile :: getTileType
{
    return type_;
}

/*-----------------------------------------------------------------------------------
--  FUNCTION:       Set Position - sets the position at the point represented by the
--                  XY coordinates passed in.
--
--  DATE:           March 8th, 2012
--
--  DESIGNER:       Mike Zobac
--
--  PROGRAMMER:     Mike Zobac
--
--  INTERFACE:      void setPosition(int x, int y);
--
--  RETURNS:        void
--
--  NOTES:          This function will likely not be needed.  Tiles should be created
--                  through the constructor that sets this variable.
-------------------------------------------------------------------------------------*/

Tile ::setPosition(int x, int y)
{
    position_ = new Point(x, y);
}

/*-----------------------------------------------------------------------------------
--  FUNCTION:       Get Position
--
--  DATE:           March 8th, 2012
--
--  DESIGNER:       Mike Zobac
--
--  PROGRAMMER:     Mike Zobac
--
--  INTERFACE:      Point getPosition();
--
--  RETURNS:        The point representing the position of the tile.
--
--  NOTES:
-------------------------------------------------------------------------------------*/

Tile ::getPosition()
{
    return position_;
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

Tile :: setGraphic()
{
    new TileGraphicObject(type_, position_);
}
