#ifndef PROJECTILEGRAPHICSOBJECT_H
#define PROJECTILEGRAPHICSOBJECT_H

class ProjectileGraphicsObject
{
public:
    ProjectileGraphicsObject();
    QGraphicsPixmapItem getPixmapItem();
private:
    ~ProjectileGraphicsObject();
    Point position_;
    QPixmap currentPixmap_;
    QGraphicsPixmapItem pixmapItem_;
    void draw (Point pos);
};

#endif // PROJECTILEGRAPHICSOBJECT_H
