#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <qfile.h>
#include <qmap.h>
#include <qlist.h>
#include <qstring.h>
#include "tile.h"

#include "../../../player/GameObjectStationary.h"
#include "landtile.h"
#include "seatile.h"
#include <vector>
class GameMap
{
    public:
        GameMap();
        GameMap(int xSize, int ySize);
        GameMap(QString fileName);
        int addTile(Tile tile);

    private:
        QFile                           xmlMap_;
        QMap<int, GameObjectStationary> mapObjects_;
        //Tile                        gameTiles_;
        std::vector<std::vector<Tile*> > gameTiles_;

};

#endif // GAMEMAP_H
