#ifndef EDGE_H
#define EDGE_H
#include "stadium.h"


class Edge
{
public:
    Edge();
    Edge(string stadium_a, string stadium_b, int cost);
    bool match(string stadium_a, string stadium_b) const;
    string get_left_node() const{return _stadium_a;}
    string get_right_node() const{return _stadium_b;}
    int get_cost() const{return _cost;}
    void print_info();
private:
    string _stadium_a;
    string _stadium_b;
    int _cost;
};

#endif // EDGE_H
