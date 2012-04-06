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
    GraphicsObject(const Point& initialPos, GameObject* gameObject);
    QGraphicsPixmapItem* getPixmapItem() const;
    void setPixmapItem(const QPixmap& pixmap);
    GameObject* getGameObject();
    void update(const std::string& data);

private:
    Point pos_;
    GameObject* gameObject_;
    QGraphicsPixmapItem* pixmapItem_;
};

#endif // GRAPHICSOBJECT_H
