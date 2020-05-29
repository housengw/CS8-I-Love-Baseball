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
    /****************************************
    **  CONSTRUCTORS  **
    *****************************************/
    Map();

    /*******************************************
    **  ACCESSORS  **
    *******************************************/
    const StadiumContainer& get_stadiums() const{return _stadiums;}
    StadiumContainer& get_stadiums() {return _stadiums;}
    const EdgeContainer& get_edges() const{return _edges;}
    const PointContainer& get_points() const{return _points;}
    const vector<Plottable>& get_plottables() const{return _plottables;}
    void update_stadium(string stadium_name, Stadium s);

    /*******************************************
    **  MUTATOR  **
    *******************************************/
    void add_stadium(Stadium s);

private:
    StadiumContainer _stadiums;            //IN/OUT stadiums container
    EdgeContainer _edges;                  //IN/OUT edges container
    PointContainer _points;                //IN/OUT points container
    vector<Plottable> _plottables;         //IN/OUT vector of plottable
    StadiumContainer _selected_stadiums;   //IN/OUT selected stadiums container


    /*******************************************
    **  Private Functions  **
    *******************************************/
    void _initialize_stadiums();
    void _initialize_edges();
    void _initialize_points();
    void _initialize_plottables();

};

#endif // MAP_H

/****************************************
 **  CONSTRUCTORS  **
 *****************************************/
/*****************************************
 *  Map();
 *   Constructor: initialize private members to default values
 *   Parameters: None
 *   Return: None
 *****************************************/


/****************************************
 **  ACCESSORS  **
 *****************************************/
/***********************************************
 *  const StadiumContainer& get_stadiums() const
 *   Accessor: return stadiums container
 *   Parameters: none
 *   Return: const stadiums container by reference
 **********************************************/
/***********************************************
 *  StadiumContainer& get_stadiums()
 *   Accessor: return stadiums container
 *   Parameters: none
 *   Return: stadiums container by reference
 **********************************************/
/***********************************************
 *  const EdgeContainer& get_edges() const
 *   Accessor: returns edges container
 *   Parameters: none
 *   Return: edges container by reference
 **********************************************/
/***********************************************
 *  const PointContainer& get_points() const
 *   Accessor: returns points container
 *   Parameters: none
 *   Return: points container by reference
 **********************************************/
/***********************************************
 *  const vector<Plottable>& get_plottables() const
 *   Accessor: returns vector of Plottable
 *   Parameters: none
 *   Return: vector
 **********************************************/
/***********************************************
 *  void update_stadium(string stadium_name, Stadium s);
 *   Accessor: update stadium information
 *   Parameters: string stadium name, and Stadium s
 *   Return: None
 **********************************************/


/*******************************************
**  MUTATOR  **
*******************************************/
/***********************************************
 *  void add_stadium(Stadium s);
 *   Mutator: add stadium
 *   Parameters: Stadium s
 *   Return: None
 **********************************************/
