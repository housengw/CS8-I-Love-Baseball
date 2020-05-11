#ifndef EDGE_CONTAINER_H
#define EDGE_CONTAINER_H
#include "edge.h"
#include "container.h"


class EdgeContainer: public Container<Edge>
{
public:
    EdgeContainer();
    void print();
};

#endif // EDGE_CONTAINER_H
