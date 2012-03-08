#include "mouseEvent.h"

// constructor
MouseEvent::MouseEvent(QWidget *aParent)
    : QWidget(aParent)
{
    m_mouseClick = false;
}

void MouseEvent::mousePressEvent ( QMouseEvent * e )
{
    // store click position
    m_lastPoint = e->pos();
    // set the flag meaning "click began"
    m_mouseClick = true;
}

void MouseEvent::mouseReleaseEvent ( QMouseEvent * e )
{
    // check if cursor not moved since click beginning
    if ((m_mouseClick) && (e->pos() == m_lastPoint))
    {
        // emit Click signal
        emit mouseClickEvent;
    }
}
