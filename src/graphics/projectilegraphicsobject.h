#ifndef PROJECTILEGRAPHICSOBJECT_H
#define PROJECTILEGRAPHICSOBJECT_H

#include "graphicsobject.h"

class ProjectileGraphicsObject : public GraphicsObject
{
    Q_OBJECT
public:
    ProjectileGraphicsObject(GameObject* gameObject);
    void update(const std::string &data);
    bool isExpired();
    bool setExpired();

private:
    bool expired_;
};

#endif // PROJECTILEGRAPHICSOBJECT_H
