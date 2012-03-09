#ifndef SHIPCOMPONENT_H
#define SHIPCOMPONENT_H

#include <QGraphicsPixmapItem>

class ShipComponent : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    ShipComponent(QGraphicsItem *parent = NULL);
    void rotate(qreal angle);
    void move(qreal ax, qreal ay);
};

#endif // SHIPCOMPONENT_H
