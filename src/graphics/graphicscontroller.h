#ifndef GRAPHICSCONTROLLER_H
#define GRAPHICSCONTROLLER_H

#include <QObject>
#include <QGraphicsScene>

class GraphicsController : public QObject
{
    Q_OBJECT

public:
    explicit GraphicsController(QGraphicsScene *scene, QObject *parent = 0);
    void addGraphic(const GraphicsObject *graphicsObject) const;
    void removeGraphic(const GraphicsObject *graphic) const;

private:
    QGraphicsScene *scene_;
    
};

#endif // GRAPHICSCONTROLLER_H
