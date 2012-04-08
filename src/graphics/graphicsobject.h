#ifndef GRAPHICSOBJECT_H
#define GRAPHICSOBJECT_H

#include <QGraphicsPixmapItem>
#include <string>
#include "../player/GameObject.h"
#include "../../sprites/sprites.h"

#define NO_ANIMATION        0;
#define ANIMATE_MOVING      1;
#define ANIMATE_DESTRUCTION 2;

class GraphicsObject
{
public:
    GraphicsObject(GameObject* gameObject);
    QGraphicsPixmapItem* getPixmapItem() const;
    void setPixmapItem(QGraphicsPixmapItem* pixmapItem);
    GameObject* getGameObject();
    virtual void update(const std::string& data);

private:
    GameObject* gameObject_;
    QGraphicsPixmapItem* pixmapItem_;
};

#endif // GRAPHICSOBJECT_H
