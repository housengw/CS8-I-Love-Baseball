#ifndef EDGE_CONTAINER_H
#define EDGE_CONTAINER_H
#include "container.h"
#include "edge.h"

class EdgeContainer : public Container<Edge>
{
  public:
    EdgeContainer();
    int find_connection(string stadium_a, string stadium_b) const;
    int get_cost(string stadium_a, string stadium_b) const;
    bool connected(string stadium_a, string stadium_b) const;
    void print() const;
};

#endif // EDGE_CONTAINER_H
