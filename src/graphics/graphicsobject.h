#ifndef GRAPHICSOBJECT_H
#define GRAPHICSOBJECT_H

#include <QGraphicsPixmapItem>
#include "../player/GameObject.h"
#include "sprites.h"

#define NO_ANIMATION        0;
#define ANIMATE_MOVING      1;
#define ANIMATE_DESTRUCTION 2;

class GraphicsObject
{
public:
    GraphicsObject(const Point& initialPos);
    QGraphicsPixmapItem* getPixmapItem() const;
    void setPixmapItem(const QPixmap& pixmap);

private:
    QGraphicsPixmapItem* pixmapItem_;
    Point pos_;
};

#endif // GRAPHICSOBJECT_H
