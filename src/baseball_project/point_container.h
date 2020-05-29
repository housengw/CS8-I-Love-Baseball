#ifndef POINT_CONTAINER_H
#define POINT_CONTAINER_H
#include "point.h"
#include "container.h"

using namespace std;

class PointContainer: public Container<Point>
{
public:
    /****************************************
    **  CONSTRUCTORS  **
    *****************************************/
    PointContainer();


    /*******************************************
    **  ACCESSORS  **
    *******************************************/
    int find(string point_name) const;
    bool contains(string point_name) const;
    Point get_coordinates(string point_name) const;
    void print() const;
};

#endif // POINT_CONTAINER_H

/****************************************
 **  CONSTRUCTORS  **
 *****************************************/
/*****************************************
 *  PointContainer();
 *   Constructor: initialize private members to default values
 *   Parameters: None
 *   Return: None
 *****************************************/


/****************************************
 **  ACCESSORS  **
 *****************************************/
/***********************************************
 *  int find(string point_name) const;
 *   Accessor: find point
 *   Parameters: string point name
 *   Return: int > 0 if point is found else int < 0
 **********************************************/
/***********************************************
 *  bool contains(string point_name) const;
 *   Accessor: checks if point is in container
 *   Parameters: string point name
 *   Return: true if point is in container else false
 **********************************************/
/***********************************************
 *  Point get_coordinates(string point_name) const;
 *   Accessor: get coordinates of point
 *   Parameters: string point name
 *   Return: coordiantes of point
 **********************************************/
/***********************************************
 * void print_info();
 *   Accessor: display information
 *   Parameters: None
 *   Return: none
**********************************************/

