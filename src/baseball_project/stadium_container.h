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

    StadiumContainer get_stadiums_grass_surface();
    StadiumContainer get_stadiums_turf_surface();
    StadiumContainer get_american_stadiums();
    StadiumContainer get_national_stadiums();

    int find(string stadium_name) const;
    bool contains(string stadium_name) const;
    Stadium get_stadium(string stadium_name) const;
    void print() const;
};

#endif // STADIUMCONTAINER_H
