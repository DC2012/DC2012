#ifndef SHIPGRAPHICSOBJECT_H
#define SHIPGRAPHICSOBJECT_H

#include "graphicsobject.h"
#include "../../sprites/sprites.h"
#include <QPixmap>
#include <QMutex>
#include <QTimer>

class ShipGraphicsObject : public GraphicsObject
{
    Q_OBJECT
public:
    ShipGraphicsObject(GameObject* gameObject);
    ~ShipGraphicsObject();
    void update(const std::string &data);
    void setCanShoot();
    bool canShoot();
    double shoot(QPoint clickPos);
    void gotHit(GameObject* hitter);

signals:
    void death();

public slots:
    void explode();

private:
    bool canShoot_;
    QTimer pixmapSwitchTimer_;
    QList<const QPixmap*> exAnim;
    QList<const QPixmap*>::iterator curPic;
    QPixmap* ex1;
    QPixmap* ex2;
    QPixmap* ex3;
    QPixmap* ex4;
    QPixmap* ex5;
    QPixmap* ex6;
    QPixmap* ex7;
    QPixmap* ex8;
};

#endif // SHIPGRAPHICSOBJECT_H
