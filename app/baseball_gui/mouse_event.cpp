#include "mouse_event.h"

mouse_event::mouse_event(QWidget *parent) : QLabel(parent)
{
    setMouseTracking(true);
}

void mouse_event::mouseMoveEvent(QMouseEvent *ev)
{
    this->x = ev->x();
    this->y = ev->y();
    emit Mouse_Pos();
}

//
void mouse_event::mouseReleaseEvent(QMouseEvent *)
{
    emit Mouse_Release();
}
