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
    vector<Plottable> get_plottables(bool national_league=true,
                                     bool american_league=true,
                                     bool grass_surface=true,
                                     bool artificial_surface=true);
    const StadiumContainer& get_stadiums() const{return _stadiums;}
    const EdgeContainer& get_edges() const{return _edges;}
    const PointContainer& get_points() const{return _points;}


    void _update_list (const bool &american, const bool &national, const bool &grass, const bool &turf);
    vector<Stadium> sorted_TeamName ();
    vector<Stadium> sorted_StadiumName ();
    vector<Stadium> sorted_DateOpened ();

private:
    void _initialize_stadiums();
    void _initialize_edges();
    void _initialize_points();
    StadiumContainer _stadiums;
    EdgeContainer _edges;
    PointContainer _points;

    StadiumContainer _AmeStadiums;
    StadiumContainer _NatStadiums;
    vector<Stadium> _list;
};

#endif // MAP_H
