#include "map.h"

Map::Map()
{
    _initialize_stadiums();
    _initialize_edges();
}


void Map::_initialize_stadiums(){
    StadiumContainer national_stadiums, american_stadiums;
    load_stadiums(APP_NATIONAL_FILE_PATH, NATIONAL_LEAGUE_NAME, national_stadiums);
    load_stadiums(APP_AMERICAN_FILE_PATH, AMERICAN_LEAGUE_NAME,american_stadiums);
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
