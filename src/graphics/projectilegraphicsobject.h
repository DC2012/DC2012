#ifndef PROJECTILEGRAPHICSOBJECT_H
#define PROJECTILEGRAPHICSOBJECT_H

#include "graphicsobject.h"

class ProjectileGraphicsObject
{
public:
    ProjectileGraphicsObject(Point position);
    QGraphicsPixmapItem getPixmapItem();
private:
    ~ProjectileGraphicsObject();
    Point position_;
    QPixmap currentPixmap_;
    QGraphicsPixmapItem pixmapItem_;
    void draw (Point pos);
};

#endif // PROJECTILEGRAPHICSOBJECT_H
