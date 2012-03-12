#include "shipcomponent.h"

ShipComponent::ShipComponent(QGraphicsItem *parent)
    : QGraphicsPixmapItem(QPixmap("/home/clarence/images/1jvship.png"), parent)
{

}

void ShipComponent::rotate(qreal angle)
{
    setTransformOriginPoint(offset().x(), offset().y());
    setRotation(angle);
}

void ShipComponent::move(qreal ax, qreal ay)
{
    setOffset(ax, ay);
}
