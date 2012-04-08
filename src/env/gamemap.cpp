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
--  PROGRAMMERS:    Mike Zobac / Chris Sim
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


/*------------------------------------------------------------------------------------
--  FUNCTION:   GameMap ctor - reads a map of tiles from and xml file and instanciates
--                             that map.
--
--  DATE:       March 29, 2012
--
--  DESIGNER:   Chris Sim
--
--  PROGRAMMER: Chris Sim
--
--  INTERFACE:  GameMap :: GameMap(QString fileName)
--
--  NOTES:
-------------------------------------------------------------------------------------*/

GameMap :: GameMap(QString fileName)
{
    // DOM method of reading XML, not SAX
    // it reads the entire document, then parse any data needed
    QDomDocument doc;

    // Load the file
    QFile map(fileName);
    if(!map.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
    }
    else
    {
        if(doc.setContent(&map))
        {
            qDebug() << "Failed to load the map";
        }
        map.close();
    }

    // get the root element
    QDomElement maps = doc.firstChildElement();

    // create tiles
    arrangeElements(maps, "tile", "gid");

}



/*------------------------------------------------------------------------------------
--  FUNCTION:   arrangeElements - go through each node in the XML doc and lay out
--                                the tiles at positions in tileSize intervals
--
--  DATE:       March 29, 2012
--
--  DESIGNER:   Chris Sim
--
--  PROGRAMMER: Chris Sim
--
--  INTERFACE:  void arrangeElements(QDomElement root, QString tagname, QString attribute)
--
--  NOTES:      goes row by row (ie. 0 to xSize at y = 0, then same again at y = tileSize)
-------------------------------------------------------------------------------------*/

void GameMap::arrangeElements(QDomElement root, QString tagname, QString attribute)
{
    QDomNodeList items = root.elementsByTagName(tagname);
    int posX = 0, posY = 0;
    
    for(int i = 0; i < items.count(); i++)
    {
        QDomNode itemnode = items.at(i);

        // convert to element
        if(itemnode.isElement())
        {
            QDomElement tile = itemnode.toElement();
        
            if(tile.attribute(attribute) == 0)
            {
                gameTiles_[posX / tileSize][posY / tileSize] = new SeaTile(Point(posX, posY));
            }
            else
            {
                gameTiles_[posX / tileSize][posY / tileSize] = new LandTile(Point(posX, posY));
            }

            if((posX += tileSize) == xSize)
            {
                posX = 0;
                posY += tileSize;
            }
        }
    }
}






