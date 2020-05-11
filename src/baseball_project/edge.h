#ifndef EDGE_H
#define EDGE_H
#include "stadium.h"


class Edge
{
public:
    Edge();
    Edge(Stadium stadium_a, Stadium stadium_b, int cost);
    void print_info();
private:
    Stadium _stadium_a;
    Stadium _stadium_b;
    int _cost;
};

#endif // EDGE_H
