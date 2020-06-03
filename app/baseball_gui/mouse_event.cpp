#include "mouse_event.h"

/*****************************************************************
 * CONSTRUCTOR
 * mouse_event::mouse_event(QWidget *parent) :QLabel(parent)
 *________________________________________________________________
 *  This constructor initializes the mouse tracking as true
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     None
 *
 *  POST-CONDITIONS
 *     None
 *****************************************************************/
mouse_event::mouse_event(QWidget *parent)  //IN - parent of the mainwindow
    : QLabel(parent)
{
    setMouseTracking(true);
}

/*****************************************************************
 *  Method void mouse_event::mouseMoveEvent (QMouseEvent *ev)
 *________________________________________________________________
 *  This function gets the mouse current location
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     mouse is moved
 *
 *  POST-CONDITIONS
 *     coordinated obtained
 *****************************************************************/
void mouse_event::mouseMoveEvent (QMouseEvent *ev)
{
    this->x = ev->x();
    this->y = ev->y();
    emit Mouse_Pos();
}

/*****************************************************************
 *  Method void mouse_event::mouseReleaseEvent (QMouseEvent *ev)
 *________________________________________________________________
 *  This function gets the mouse released location
 *________________________________________________________________
 *  PRE-CONDITIONS
 *     mouse is released
 *
 *  POST-CONDITIONS
 *     coordinates obtained
 *****************************************************************/
void mouse_event::mouseReleaseEvent (QMouseEvent *)
{
    emit Mouse_Release();
}
