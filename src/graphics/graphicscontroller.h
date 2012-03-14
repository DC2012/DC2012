#ifndef GRAPHICSCONTROLLER_H
#define GRAPHICSCONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "graphicsobject.h"

class GraphicsController : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GraphicsController(QWidget *parent = 0);
    void addGraphic(const GraphicsObject *graphicsObject) const;
    void removeGraphic(const GraphicsObject *graphic) const;

private:
    QGraphicsScene *scene_;
};

#endif // GRAPHICSCONTROLLER_H
