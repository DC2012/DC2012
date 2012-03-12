#include "tilegraphicsobject.h"

TileGraphicsObject::TileGraphicsObject(int type, Position position)
{
    position_ = position;
    type_ = type;
    draw(type_), positon_;
}

void initGraphics() {
// initialize pixmapArray[]
}

void draw(int type, Position pos) {
    if (type == SEA_TILE) {
    // use the sea tile pixmap
    } else if (type == LAND_TILE) {
    // use the land tile pixmap
    } else {
    // error
    }

// call the graphics controller method to add
// the pixmap item to the scene
}
