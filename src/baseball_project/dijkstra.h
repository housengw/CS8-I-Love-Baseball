#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "container.h"
#include "helpers.h"

class Dijkstra
{
public:

    /****************************************
    **  CONSTRUCTORS  **
    *****************************************/
    Dijkstra();
    Dijkstra(int from_node, int** adjacency_matrix, size_t size);

    /****************************************
    **  Big Three  **
    *****************************************/
    Dijkstra& operator=(const Dijkstra& rhs);  //assignment operator
    Dijkstra(const Dijkstra& copy_this);       //copy constructor
    ~Dijkstra();                               //destructor

    /****************************************
    **  ACCESSORS  **
    *****************************************/
    int get_cost(int to_node);
    Container<int> reconstruct(int to_node);

private:
    int* p;   //array of previous nodes for Dijkstras Algorithm
              //      and Prims Algorithm
    int* c;   //array of costs for Dijkstras Algorithm and Prims
              //      Algorithm
    int _from_node;           //IN/OUT start node
    int** _adjacency_matrix;  //IN/OUT adjacency matrix
    size_t _size;             //IN/OUT size

    /****************************************
    **  Private Functions  **
    *****************************************/
    void _run();
    void _initialize_arrays(size_t size);
    bool _connected(int from_city, int to_city);

};

#endif // DIJKSTRA_H

/****************************************
 **  CONSTRUCTORS  **
 *****************************************/
/*****************************************
 *  Dijkstra();
 *   Constructor: initialize private members to default values
 *   Parameters: None
 *   Return: None
 *****************************************/
/*****************************************
 *  Dijkstra(int from_node, int** adjacency_matrix, size_t size);
 *   Constructor: initialize private members to given parameters
 *   Parameters: None
 *   Return: None
 *****************************************/


/****************************************
**  Big Three  **
*****************************************/
/*****************************************
 *  Dijkstra& operator=(const Dijkstra& rhs);
 *   Assignment operator: sets this Dijkstra same as rhs
 *   Parameters: Dijkstra rhs
 *   Return: None
 *****************************************/
/*****************************************
 *  Dijkstra(const Dijkstra& copy_this);
 *   Copy constructor: sets this Dijkstra as a copy of copy_this
 *   Parameters: Dijkstra copy_this
 *   Return: None
 *****************************************/
/*****************************************
 *  ~Dijkstra();
 *   Destructor: deletes Dijkstra
 *   Parameters: None
 *   Return: None
 *****************************************/


/****************************************
**  ACCESSORS  **
*****************************************/
/*****************************************
 * int get_cost(int to_node);
 *   Accessor: returns the cost at C[to_node]
 *   Parameters: int to_node
 *   Return: returns int cost
 *****************************************/
/*****************************************
 * Container<int> reconstruct(int to_node);
 *   Accessor: reconstruct
 *   Parameters: int to_node
 *   Return: return reconstructed container
 *****************************************/



/****************************************
**  Private Functions  **
*****************************************/
/*****************************************
 * void _run();
 *   Run: run dijkstras
 *   Parameters: None
 *   Return: None
 *****************************************/
/*****************************************
 * void _initialize_arrays(size_t size);
 *   Initialize: initialize arrays to given size
 *   Parameters: size_t size
 *   Return: None
 *****************************************/
/*****************************************
 * bool _connected(int from_city, int to_city);
 *   Connect: verifies if there is connection between cities
 *   Parameters: int from_city and to_city
 *   Return: return true if they are connected else false
 *****************************************/
