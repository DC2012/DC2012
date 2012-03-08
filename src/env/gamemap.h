#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <qfile.h>
#include <qmap.h>
#include <qlist.h>
#include <qstring.h>

#include "GameObjectStationary.h"
#include "tile.h"

class GameMap
{
public:
    GameMap();
    GameMap(QString fileName);


private:
    QFile                           xmlMap_;
    QMap<int, GameObjectStationary> mapObjects;
    QList<Tile>                     gameTiles;


};

#endif // GAMEMAP_H
