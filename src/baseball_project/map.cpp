#include "map.h"

/**************************************************************
 * Map::Map ();
 * ____________________________________________________________
 * This method intializes the members with default values
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * initialize private members to default values
 *************************************************************/
Map::Map()
{
    _initialize_stadiums();
    _initialize_points();
    _initialize_edges();
    _initialize_plottables();
    _selected_stadiums = _stadiums;
}

/**************************************************************
 * void Map::_initialize_stadiums()
 * ____________________________________________________________
 * This method intializes stadiums by loading from file
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * load stadiums from file into stadiums container
 *************************************************************/
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

/**************************************************************
 * void Map::_initialize_edges()
 * ____________________________________________________________
 * This method intializes edges by loading from file
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * load edges from file into edges container
 *************************************************************/
void Map::_initialize_edges(){
    _edges = load_edges(APP_EDGES_FILE_PATH, _stadiums);
}


/**************************************************************
 * void Map::_initialize_points()
 * ____________________________________________________________
 * This method intializes points by loading from file
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * load points from file into points container
 *************************************************************/
void Map::_initialize_points(){
    _points = load_points(APP_POINTS_FILE_PATH);
}

/**************************************************************
 * void Map::_initialize_plottables()
 * ____________________________________________________________
 * This method intializes vector of plottable
 * ___________________________________________________________
 * Pre-Condition
 * edges are loaded
 *
 * Post-Condition
 * get coordinates of edges and insert into vector
 *************************************************************/
void Map::_initialize_plottables(){
    vector<Plottable> plottables;
    Point p1, p2;
    for (size_t i=0; i<_edges.size(); i++){
        p1 = _points.get_coordinates(_edges[i].get_left_node());
        p2 = _points.get_coordinates(_edges[i].get_right_node());
        plottables.insert(plottables.end(), Plottable(p1, p2));
    }
    _plottables = plottables;
}


/**************************************************************
 * void Map::update_stadium(string stadium_name, Stadium s)
 * ____________________________________________________________
 * This method upades stadiums information
 * ___________________________________________________________
 * Pre-Condition
 * Stadium name is given
 *
 * Post-Condition
 * update stadium information
 *************************************************************/
void Map::update_stadium(string stadium_name,  //IN - string stadium name
                         Stadium s)            //IN - Stadium s
{
    for (size_t i=0; i<_stadiums.size(); i++){
        if (_stadiums[i].get_stadium_name() == stadium_name){
            _stadiums[i] = s;
            return;
        }
    }
}

/**************************************************************
 * void Map::add_stadium(Stadium s)
 * ____________________________________________________________
 * This method adds a stadium into stadium container
 * ___________________________________________________________
 * Pre-Condition
 * Stadium s given
 *
 * Post-Condition
 * stadium added into container
 *************************************************************/
void Map::add_stadium(Stadium s)   //IN - Stadium s
{
    _stadiums.add(s);
}
