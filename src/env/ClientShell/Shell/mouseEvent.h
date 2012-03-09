#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include <QWidget>
#include <QGraphicsView>
#include <QMouseEvent>
class MouseEvent : public QWidget
{
    Q_OBJECT

signals:
    // define mouseClick signal
    void mouseClickEvent();

public:
    // constructor
    MouseEvent(QWidget *aParent);

protected:
    // implement processing of mouse events
    void mouseReleaseEvent(QMouseEvent * e);
    void mousePressEvent(QMouseEvent * e);

private:
    // member variable to store click position
    QPoint m_lastPoint;
    // member variable - flag of click beginning
    bool m_mouseClick;

};

#endif // MOUSEEVENT_H
