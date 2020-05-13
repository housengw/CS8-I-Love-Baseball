#include "map.h"

Map::Map()
{
    _initialize_stadiums();
    _initialize_points();
    _initialize_edges();
}


void Map::_initialize_stadiums(){
    //    StadiumContainer national_stadiums, american_stadiums;

    load_stadiums(APP_NATIONAL_FILE_PATH, NATIONAL_LEAGUE_NAME, _NatStadiums);
    load_stadiums(APP_AMERICAN_FILE_PATH, AMERICAN_LEAGUE_NAME,_AmeStadiums);

    //    for (size_t i=0; i<national_stadiums.size(); i++){
    //        _stadiums.add(national_stadiums[i]);
    //    }
    //    for (size_t i=0; i<american_stadiums.size(); i++){
    //        _stadiums.add(american_stadiums[i]);
    //    }
}

void Map::_update_list (const bool &american, const bool &national, const bool &grass, const bool &turf)
{
    if ( american && !national) {
        _list = vectorize(_AmeStadiums);
        if (!grass && turf)
            _list = vectorize(_AmeStadiums.stadiums_turf_surface());
        else if (grass && !turf) {
            _list = vectorize(_AmeStadiums.stadiums_grass_surface());
        }
    }
    else if (!american && national) {
        _list = vectorize(_NatStadiums);
        if (!grass && turf)
            _list = vectorize(_NatStadiums.stadiums_turf_surface());
        else if (grass && !turf) {
            _list = vectorize(_NatStadiums.stadiums_grass_surface());
        }
    }
    else if (american && national) {
        StadiumContainer temp;
        temp += _AmeStadiums;
        temp += _NatStadiums;
        _list = vectorize(temp);
        if (!grass && turf)
            _list = vectorize(temp.stadiums_turf_surface());
        else if (grass && !turf) {
            _list = vectorize(temp.stadiums_grass_surface());
        }
    }
}

vector<Stadium> Map::sorted_TeamName ()
{
    vector<Stadium> temp_list (_list);
    sort_by_team_name (temp_list);
    return temp_list;
}
vector<Stadium> Map::sorted_StadiumName ()
{
    vector<Stadium> temp_list (_list);
    sort_by_stadium_name (temp_list);
    return temp_list;
}
vector<Stadium> Map::sorted_DateOpened ()
{
    vector<Stadium> temp_list (_list);
    sort_by_opened_date (temp_list);
    return temp_list;
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
