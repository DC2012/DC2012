#include "tilegraphicsobject.h"

TileGraphicsObject::TileGraphicsObject(int type, Point position)
{
    position_ = position;
    type_ = type;
    draw(type_, position_);
}

void initGraphics() {
// initialize pixmapArray[]
}

void draw(int type, Point position) {
    if (type == 0) {
    // use the sea tile pixmap
    } else if (type == 1) {
    // use the land tile pixmap
    } else {
    // error
    }

// call the graphics controller method to add
// the pixmap item to the scene
}
