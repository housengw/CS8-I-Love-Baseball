#ifndef POINT_H
#define POINT_H
#include <string>

using namespace std;


class Point
{
public:
    /****************************************
    **  CONSTRUCTORS  **
    *****************************************/
    Point();
    Point(string name, int x, int y);

    /*******************************************
    **  ACCESSORS  **
    *******************************************/
    string get_name() const{return _name;}
    int get_x(){return _x;}
    int get_y(){return _y;}

    /*******************************************
    **  MUTATORS  **
    *******************************************/
    void set_name(string name);
    void set_x(int x);
    void set_y(int y);

private:
    string _name;   //IN/OUT - name of point
    int _x;         //IN/OUT - x,y coordinates
    int _y;
};

/*******************************************
**  Plottable Structure  **
*******************************************/
struct Plottable
{
    //initialize points
    Plottable(Point p1, Point p2): p1(p1), p2(p2){}
    Point p1;   //point 1 and 2
    Point p2;
};


#endif // POINT_H


/****************************************
 **  CONSTRUCTORS  **
 *****************************************/
/*****************************************
 *  Point();
 *   Constructor: initialize private members to default values
 *   Parameters: None
 *   Return: None
 *****************************************/
/*****************************************
 *  Point(string name, int x, int y);
 *   Constructor: initialize private members to the input data
 *   Parameters: None
 *   Return: None
 *****************************************/


/****************************************
 **  ACCESSORS  **
 *****************************************/
/***********************************************
 *  string get_name() const
 *   Accessor: return name of point
 *   Parameters: none
 *   Return: string name of point
 **********************************************/
/***********************************************
 *  int get_x()
 *   Accessor: return x coordinate
 *   Parameters: none
 *   Return: int x coordinate
 **********************************************/
/***********************************************
 *  int get_y()
 *   Accessor: return y coordinate
 *   Parameters: none
 *   Return: int y coordinate
 **********************************************/


/****************************************
 **  MUTATORS  **
 *****************************************/
/***********************************************
 *  void set_name(string name);
 *   Accessor: set name of point
 *   Parameters: string name
 *   Return: None
 **********************************************/
/***********************************************
 *  void set_x(int x);
 *   Accessor: set x coordinate
 *   Parameters: int x
 *   Return: None
 **********************************************/
/***********************************************
 *   void set_y(int y);
 *   Accessor: set y coordinate
 *   Parameters: int y
 *   Return: None
 **********************************************/
