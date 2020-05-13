#ifndef MAP_H
#define MAP_H
#include "stadium_container.h"
#include "edge_container.h"
#include "point_container.h"
#include "save_load.h"
#include "constants.h"


class Map
{
public:
    Map();
    vector<Plottable> get_plottables(bool national_league=true,
                                     bool american_league=true,
                                     bool grass_surface=true,
                                     bool artificial_surface=true);
private:
    void _initialize_stadiums();
    void _initialize_edges();
    void _initialize_points();
    StadiumContainer _stadiums;
    EdgeContainer _edges;
    PointContainer _points;
};

#endif // MAP_H
