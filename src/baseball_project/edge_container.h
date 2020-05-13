#ifndef EDGE_CONTAINER_H
#define EDGE_CONTAINER_H
#include "edge.h"
#include "container.h"


class EdgeContainer: public Container<Edge>
{
public:
    EdgeContainer();
    int find_connection(string stadium_a, string stadium_b);
    bool connected(string stadium_a, string stadium_b);
    void print();
};

#endif // EDGE_CONTAINER_H
