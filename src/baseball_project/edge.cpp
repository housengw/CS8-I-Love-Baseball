#include "edge.h"


Edge::Edge():
    _stadium_a(), _stadium_b(), _cost(-1)
{
    //intentionally left empty
}


Edge::Edge(Stadium stadium_a, Stadium stadium_b, int cost):
    _stadium_a(stadium_a), _stadium_b(stadium_b), _cost(cost)
{
    //intentionally left empty
}


void Edge::print_info(){
    cout<<_stadium_a.get_stadium_name()
        <<" <--> "
        <<_stadium_b.get_stadium_name();
}
