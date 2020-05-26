#include "edge.h"

Edge::Edge() : _stadium_a(), _stadium_b(), _cost(-1)
{
    // intentionally left empty
}

Edge::Edge(string stadium_a, string stadium_b, int cost)
    : _stadium_a(stadium_a), _stadium_b(stadium_b), _cost(cost)
{
    // intentionally left empty
}

bool Edge::match(string stadium_a, string stadium_b) const
{
    return ((stadium_a == _stadium_a && stadium_b == _stadium_b) ||
            (stadium_a == _stadium_b && stadium_b == _stadium_a));
}

void Edge::print_info()
{
    cout << _stadium_a << " <--> " << _stadium_b;
}
