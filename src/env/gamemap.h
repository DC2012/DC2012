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
#include <vector>

#include "../player/GameObjectStationary.h"
#include "landtile.h"
#include "seatile.h"
#include "tile.h"


#define xSize 4000
#define ySize 3000
#define tileSize 25


class GameMap
{
    public:
        GameMap();
        GameMap(QString fileName);
        int addTile(Tile tile);
        void arrangeElements(QDomElement root, QString tagname, QString attribute);
        std::vector<std::vector<Tile*> > gameTiles_;

    private:
        QFile                           xmlMap_;
        //QMap<int, GameObjectStationary> mapObjects_; <<<<<<<--- need fix, cannot have instance of abstract class
        //Tile                        gameTiles_;
        

};

#endif // GAMEMAP_H
