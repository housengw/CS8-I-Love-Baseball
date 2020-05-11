#include "map.h"

Map::Map()
{
    _initialize_stadiums();
}


void Map::_initialize_stadiums(){
    StadiumContainer national_stadiums, american_stadiums;
    load_stadiums(NATIONAL_FILE_PATH, NATIONAL_LEAGUE_NAME, national_stadiums);
    load_stadiums(AMERICAN_FILE_PATH, AMERICAN_LEAGUE_NAME,american_stadiums);
    for (size_t i=0; i<national_stadiums.size(); i++){
        _stadiums.add(national_stadiums[i]);
    }
    for (size_t i=0; i<american_stadiums.size(); i++){
        _stadiums.add(american_stadiums[i]);
    }
}
