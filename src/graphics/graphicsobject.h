#ifndef GRAPHICSOBJECT_H
#define GRAPHICSOBJECT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <string>
#include "../player/GameObject.h"
#include "../player/GOM_Projectile.h"
#include "../player/GOM_Ship.h"
#include "../player/GOS_PowerUp.h"
#include "../../sprites/sprites.h"

#define NO_ANIMATION        0;
#define ANIMATE_MOVING      1;
#define ANIMATE_DESTRUCTION 2;

class GraphicsObject : public QObject
{
    Q_OBJECT

public:
    GraphicsObject(GameObject* gameObject, QObject* parent = 0);
    virtual ~GraphicsObject();
    QGraphicsPixmapItem* getPixmapItem() const;
    void setPixmapItem(QGraphicsPixmapItem* pixmapItem);
    GameObject* getGameObject();
    virtual void update(const std::string& data);

signals:
    void shipHit();

private:
    GameObject* gameObject_;
    QGraphicsPixmapItem* pixmapItem_;
    QList<QPixmap>* explodeAnim;
};

#endif // GRAPHICSOBJECT_H
