#include "map.h"

Map::Map()
{
    _initialize_stadiums();
    _initialize_points();
    _initialize_edges();
}

void Map::_initialize_stadiums(){
    StadiumContainer national_stadiums, american_stadiums;

    load_stadiums(APP_NATIONAL_FILE_PATH, NATIONAL_LEAGUE_NAME, national_stadiums);
    load_stadiums(APP_AMERICAN_FILE_PATH, AMERICAN_LEAGUE_NAME, american_stadiums);

    for (size_t i=0; i<national_stadiums.size(); i++){
        _stadiums.add(national_stadiums[i]);
    }
    for (size_t i=0; i<american_stadiums.size(); i++){
        _stadiums.add(american_stadiums[i]);
    }
}

void Map::_initialize_edges(){
    _edges = load_edges(APP_EDGES_FILE_PATH, _stadiums);
}


void Map::_initialize_points(){
    _points = load_points(APP_POINTS_FILE_PATH);
}


vector<Plottable> Map::get_plottables(bool national_league,
                                      bool american_league,
                                      bool grass_surface,
                                      bool artificial_surface){
    vector<Plottable> plottables;
    Point p1, p2;
    for (size_t i=0; i<_edges.size(); i++){
        p1 = _points.get_coordinates(_edges[i].get_left_node());
        p2 = _points.get_coordinates(_edges[i].get_right_node());
        plottables.insert(plottables.end(), Plottable(p1, p2));
    }
    return plottables;
}

void Map::update_stadium(string stadium_name, Stadium s){
    for (size_t i=0; i<_stadiums.size(); i++){
        if (_stadiums[i].get_stadium_name() == stadium_name){
            _stadiums[i] = s;
            return;
        }
    }
}
