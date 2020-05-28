#ifndef MAP_H
#define MAP_H
#include "stadium_container.h"
#include "edge_container.h"
#include "point_container.h"
#include "save_load.h"
#include "constants.h"
#include "sort_functions.h"

class Map
{
public:
    Map();
    const StadiumContainer& get_stadiums() const{return _stadiums;}
    StadiumContainer& get_stadiums() {return _stadiums;}
    const EdgeContainer& get_edges() const{return _edges;}
    const PointContainer& get_points() const{return _points;}
    const vector<Plottable>& get_plottables() const{return _plottables;}
    void update_stadium(string stadium_name, Stadium s);
    void add_stadium(Stadium s);
private:
    void _initialize_stadiums();
    void _initialize_edges();
    void _initialize_points();
    void _initialize_plottables();
    StadiumContainer _stadiums;
    EdgeContainer _edges;
    PointContainer _points;
    vector<Plottable> _plottables;
    StadiumContainer _selected_stadiums;
};

#endif // MAP_H
