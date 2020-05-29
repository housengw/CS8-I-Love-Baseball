#ifndef EDGE_CONTAINER_H
#define EDGE_CONTAINER_H
#include "edge.h"
#include "container.h"


class EdgeContainer: public Container<Edge>
{
public:
    /****************************************
    **  CONSTRUCTORS  **
    *****************************************/
    EdgeContainer();

    /*******************************************
    **  ACCESSORS  **
    *******************************************/
    int find_connection(string stadium_a, string stadium_b) const;
    int get_cost(string stadium_a, string stadium_b) const;
    bool connected(string stadium_a, string stadium_b) const;
    void print() const;
};

#endif // EDGE_CONTAINER_H

/****************************************
 **  CONSTRUCTORS  **
 *****************************************/
/*****************************************
 *  EdgeContainer();
 *   Constructor: initialize private members to default values
 *   Parameters: None
 *   Return: None
 *****************************************/


/****************************************
 **  ACCESSORS  **
 *****************************************/
/***********************************************
 * int find_connection(string stadium_a, string stadium_b) const;
 *   Accessor: find connection between a and b
 *   Parameters: string stadium a and b
 *   Return: int > 0 if they are connected else int < 0
 **********************************************/
/***********************************************
 * int get_cost(string stadium_a, string stadium_b) const;
 *   Accessor: returns cost between a and b
 *   Parameters: string stadium a and b
 *   Return: cost
**********************************************/
/***********************************************
 * bool connected(string stadium_a, string stadium_b) const;
 *   Accessor: verifies if a and b are connected
 *   Parameters: string stadium a and b
 *   Return: true if a and b are connected else false
**********************************************/
/***********************************************
 * void print_info();
 *   Accessor: display information
 *   Parameters: None
 *   Return: none
**********************************************/
