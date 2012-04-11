#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <qfile.h>
#include <qmap.h>
#include <qlist.h>
#include <qstring.h>
#include <QtCore>
#include <QtXml/QtXml>
#include <QtXml/QDomNode>
#include <QDebug>
#include <map>

#include "../player/GameObjectStationary.h"
#include "landtile.h"
#include "seatile.h"
#include "tile.h"


#define xSize (160 * tileSize)
#define ySize (120 * tileSize)
#define tileSize 25

class GameMap
{
    public:
        GameMap();
        GameMap(QString fileName);
        bool isLand(const Point& location);
        int addTile(Tile tile);
        void arrangeElements(QDomElement root, QString tagname, QString attribute);
        std::map<Point, Tile*> gameTiles_;

    private:
        QFile                           xmlMap_;
        //QMap<int, GameObjectStationary> mapObjects_; <<<<<<<--- need fix, cannot have instance of abstract class
        //Tile                        gameTiles_;
        

};

#endif // GAMEMAP_H
