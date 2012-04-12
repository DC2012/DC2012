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
    static const QPixmap* ex1;
    static const QPixmap* ex2;
    static const QPixmap* ex3;
    static const QPixmap* ex4;
    static const QPixmap* ex5;
    static const QPixmap* ex6;
    static const QPixmap* ex7;
    static const QPixmap* ex8;
};

#endif // SHIPGRAPHICSOBJECT_H
