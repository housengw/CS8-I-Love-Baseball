#include "point.h"

/**************************************************************
 * Point::Point ();
 * ____________________________________________________________
 * This method intializes the members with default values
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * initialize private members to default values
 *************************************************************/
Point::Point()
{

}


/**************************************************************
 * Point::Point(string name, int x, int y)
 * ____________________________________________________________
 * This method intializes the point with paremeters values
 * ___________________________________________________________
 * Pre-Condition
 * string name and int x,y coodinates are given
 *
 * Post-Condition
 * initialize private members to parameters values
 *************************************************************/
Point::Point(string name, int x, int y):
    _name(name), _x(x), _y(y)
{
    //intentionally left empty
}


/**************************************************************
 * void Point::set_name(string name)
 * ____________________________________________________________
 * This method sets name of point
 * ___________________________________________________________
 * Pre-Condition
 * string name is given
 *
 * Post-Condition
 * name is set to given paremeter
 *************************************************************/
void Point::set_name(string name)   //IN - string name
{
    _name = name;
}


/**************************************************************
 * void Point::set_x(int x)
 * ____________________________________________________________
 * This method sets x coodinate
 * ___________________________________________________________
 * Pre-Condition
 * int x given
 *
 * Post-Condition
 * X is set to given parameter
 *************************************************************/
void Point::set_x(int x){    //IN - int x
    _x = x;
}


/**************************************************************
 * void Point::set_y(int y)
 * ____________________________________________________________
 * This method sets Y coodinate
 * ___________________________________________________________
 * Pre-Condition
 * int Y given
 *
 * Post-Condition
 * Y is set to given parameter
 *************************************************************/
void Point::set_y(int y){  //IN - int y
    _y = y;
}
