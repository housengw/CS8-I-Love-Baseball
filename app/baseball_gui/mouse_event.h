#ifndef MOUSE_EVENT_H
#define MOUSE_EVENT_H

#include <QWidget>
#include <QMouseEvent>

#include <QDebug>
#include <QEvent>
#include <QLabel>

class mouse_event : public QLabel
{
    Q_OBJECT
public:
    /********************************
     ** CONSTRUCTOR and DESTRUCTOR **
     ********************************/
    explicit mouse_event(QWidget *parent = nullptr);

    /**************
     ** ACCESSORS **
     **************/
    void mouseMoveEvent (QMouseEvent *ev);
    void mouseReleaseEvent (QMouseEvent *);

    int x, y;    //mouse coordinates

signals:

    /**************
     ** MUTATORS **
     **************/
    void Mouse_Pos ();
    void Mouse_Release ();

public slots:
};

#endif // MOUSE_EVENT_H

/*****************************************************************
 * mouse_event Class
 * ______________________________________________________________
 *  The class 'mouse_event' is used for tracking the mouse position
 ****************************************************************/


/********************************
 ** CONSTRUCTOR and DESTRUCTOR **
 ********************************/
/****************************************************************
* mouse_event (QWidget *parent = nullptr);
*   Constructor; default constructor for a mouse_event object for qtwidgets,
*   Parameters: parent (QWidget)
*   Return: none
***************************************************************/
/****************************************************************
* ~mouse_event();
*   Destructor; default Deconstructor for a mouse_event object for
*                 qtwidgets, deallocates dynamically allocated memory for
*                 the mouse_event.
*   Parameters: none
*   Return: none
***************************************************************/


/****************************************
 **  MUTATORS  **
 *****************************************/
/*******************************************
 *  void Mouse_Pos();
 *   Mutator: It will get the mouse current location
 *   Parameters: None
 *   Return: None
 *****************************************/
/*******************************************
 *  void Mouse_Pos();
 *   Mutator: It will get the mouse released location
 *   Parameters: None
 *   Return: None
 *****************************************/


/****************************************
 **  ACCESSORS  **
 *****************************************/
/*******************************************
 *  void  mouseMoveEvent (QMouseEvent *ev);
 *   Mutator: It will get the mouse current location
 *   Parameters: QMouseEvent *ev
 *   Return: None
 *****************************************/
/*******************************************
 *  void mouseReleaseEvent (QMouseEvent *);
 *   Mutator: It will get the mouse released location
 *   Parameters: QMouseEvent *ev
 *   Return: None
 *****************************************/
