#include "projectilegraphicsobject.h"

class ProjectileGraphicsObject : public GraphicObject {

    ProjectileGraphicsObject::ProjectileGraphicsObject(Point position)
    {
        position_ = position;
        initGraphics();
    }

}
