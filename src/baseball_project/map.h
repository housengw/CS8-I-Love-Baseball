#ifndef MAP_H
#define MAP_H
#include "stadium_container.h"
#include "edge_container.h"
#include "save_load.h"
#include "constants.h"


class Map
{
public:
    Map();
private:
    void _initialize_stadiums();
    StadiumContainer _stadiums;
    EdgeContainer _edges;
    int** _adjacency_matrix;
};

#endif // MAP_H