#ifndef SHIPGRAPHICSOBJECT_H
#define SHIPGRAPHICSOBJECT_H

#include "graphicsobject.h"
#include <QMutex>

class ShipGraphicsObject : public GraphicsObject
{
public:
    ShipGraphicsObject(GameObject* gameObject);
    void update(const std::string &data);
    void setCanShoot();
    bool canShoot();
    double shoot(QPoint clickPos);

private:
    bool canShoot_;
};

#endif // SHIPGRAPHICSOBJECT_H
