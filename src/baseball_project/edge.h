#ifndef EDGE_H
#define EDGE_H
#include "stadium.h"


class Edge
{
public:
    /****************************************
    **  CONSTRUCTORS  **
    *****************************************/
    Edge();
    Edge(string stadium_a, string stadium_b, int cost);


    /*******************************************
    **  ACCESSORS  **
    *******************************************/
    bool match(string stadium_a, string stadium_b) const;
    string get_left_node() const{return _stadium_a;}
    string get_right_node() const{return _stadium_b;}
    void set_left_node(string stadium){_stadium_a = stadium;}
    void set_right_node(string stadium){_stadium_b = stadium;}
    int get_cost() const{return _cost;}
    void print_info();

private:
    string _stadium_a;   //IN/OUT - stadium a
    string _stadium_b;   //IN/OUT - stadium b
    int _cost;           //IN/OUT - cost from a to b
};

#endif // EDGE_H

/****************************************
 **  CONSTRUCTORS  **
 *****************************************/
/*****************************************
 *  Edge();
 *   Constructor: initialize private members to default values
 *   Parameters: None
 *   Return: None
 *****************************************/
/*****************************************
 *  Edge(string stadium_a, string stadium_b, int cost);
 *   Constructor: initialize private members to the input data
 *   Parameters: strings stadium a and b and the cost
 *   Return: None
 *****************************************/

/****************************************
 **  ACCESSORS  **
 *****************************************/
/***********************************************
 * bool match (string stadium_a, string stadium_b) const;
 *   Accessor: verifies if stadium a and b are a match
 *   Parameters: string stadium a and b
 *   Return: true if they are a match else false
 **********************************************/
/***********************************************
 * string get_left_node() const
 *   Accessor: returns left node
 *   Parameters: None
 *   Return: left node
**********************************************/
/***********************************************
 * string get_right_node() const
 *   Accessor: returns right node
 *   Parameters: None
 *   Return: right node
**********************************************/
/***********************************************
 * int get_cost() const
 *   Accessor: returns cost between a and b
 *   Parameters: None
 *   Return: cost
**********************************************/
/***********************************************
 * void print_info();
 *   Accessor: display information
 *   Parameters: None
 *   Return: none
**********************************************/



