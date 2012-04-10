#ifndef SHIPGRAPHICSOBJECT_H
#define SHIPGRAPHICSOBJECT_H

#include "graphicsobject.h"
#include <QMutex>
#include <QTimer>

class ShipGraphicsObject : public GraphicsObject
{
    Q_OBJECT
public:
    ShipGraphicsObject(GameObject* gameObject);
    void update(const std::string &data);
    void setCanShoot();
    bool canShoot();
    double shoot(QPoint clickPos);
    void gotHit();

public slots:
    void switchPixmap();

private:
    bool canShoot_;
    QTimer pixmapSwitchTimer_;
};

#endif // SHIPGRAPHICSOBJECT_H
