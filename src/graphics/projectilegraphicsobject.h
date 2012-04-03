#ifndef PROJECTILEGRAPHICSOBJECT_H
#define PROJECTILEGRAPHICSOBJECT_H

#include "graphicsobject.h"

class ProjectileGraphicsObject : public GraphicsObject
{
public:
    ProjectileGraphicsObject(const Point& initialPoint, GameObject* gameObject);
};

#endif // PROJECTILEGRAPHICSOBJECT_H
