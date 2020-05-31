#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "container.h"
#include "helpers.h"

class Dijkstra
{
public:
    Dijkstra();
    Dijkstra(int from_node, int** adjacency_matrix, size_t size);
    Dijkstra& operator=(const Dijkstra& rhs);
    Dijkstra(const Dijkstra& copy_this);
    ~Dijkstra();
    int get_cost(int to_node);
    Container<int> reconstruct(int to_node);
//private:
    void _run();
    void _initialize_arrays(size_t size);
    bool _connected(int from_city, int to_city);
    int* p;   //array of previous nodes for Dijkstras Algorithm
              //      and Prims Algorithm
    int* c;   //array of costs for Dijkstras Algorithm and Prims
              //      Algorithm
    int _from_node;
    int** _adjacency_matrix;
    size_t _size;
};

#endif // DIJKSTRA_H
