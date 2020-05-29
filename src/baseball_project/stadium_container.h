#ifndef STADIUMCONTAINER_H
#define STADIUMCONTAINER_H
#include <iostream>
#include "stadium.h"
#include "container.h"
using namespace std;


class StadiumContainer: public Container<Stadium>
{
public:
    /****************************************
    **  CONSTRUCTORS  **
    *****************************************/
    StadiumContainer();

    /*******************************************
    **  ACCESSORS  **
    *******************************************/
    StadiumContainer get_stadiums_grass_surface();
    StadiumContainer get_stadiums_turf_surface();
    StadiumContainer get_american_stadiums();
    StadiumContainer get_national_stadiums();

    int find(string stadium_name) const;
    bool contains(string stadium_name) const;
    const Stadium& get_stadium(string stadium_name) const;
    Stadium& get_stadium(string stadium_name);
    void print() const;
};

#endif // STADIUMCONTAINER_H

/****************************************
 **  CONSTRUCTORS  **
 *****************************************/
/*****************************************
 * StadiumContainer();
 *   Constructor: initialize private members to default values
 *   Parameters: None
 *   Return: None
 *****************************************/


/****************************************
 **  ACCESSORS  **
 *****************************************/
/***********************************************
 * StadiumContainer get_stadiums_grass_surface();
 *   Accessor: return stadium with grass surface
 *   Parameters: None
 *   Return: stadiums with grass surface
 **********************************************/
/***********************************************
 *  StadiumContainer get_stadiums_turf_surface();
 *   Accessor: return stadium with turf surface
 *   Parameters: None
 *   Return: stadiums with turf surface
 **********************************************/
/***********************************************
 *  StadiumContainer get_american_stadiums();
 *   Accessor: return only american stadiums
 *   Parameters: None
 *   Return: american stadiums
 **********************************************/
/***********************************************
 *  StadiumContainer get_national_stadiums();
 *   Accessor: return only national stadiums
 *   Parameters: None
 *   Return: national stadiums
 **********************************************/
/***********************************************
 * int find(string stadium_name) const;
 *   Accessor: find stadium in container
 *   Parameters: string stadium_name
 *   Return: int < 0 if not found else int > 0
 **********************************************/
/***********************************************
 * bool contains(string stadium_name) const;
 *   Accessor: find stadium in container
 *   Parameters: string stadium_name
 *   Return: true if found else false
 **********************************************/
/***********************************************
 * const Stadium& get_stadium(string stadium_name) const;
 *   Accessor: return stadium
 *   Parameters: string stadium_name
 *   Return: stadium
 **********************************************/
/***********************************************
 *  Stadium& get_stadium(string stadium_name);
 *   Accessor: return stadium
 *   Parameters: string stadium_name
 *   Return: stadium
 **********************************************/
/***********************************************
 * void print() const;
 *   Accessor: display stadium container
 *   Parameters: None
 *   Return: None
 **********************************************/
