#ifndef PROJECTILEGRAPHICSOBJECT_H
#define PROJECTILEGRAPHICSOBJECT_H

#include "graphicsobject.h"

class ProjectileGraphicsObject : public GraphicsObject
{
public:
    ProjectileGraphicsObject(GameObject* gameObject);
    void update(const std::string &data);
};

#endif // PROJECTILEGRAPHICSOBJECT_H
