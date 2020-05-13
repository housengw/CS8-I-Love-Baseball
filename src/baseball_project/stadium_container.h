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
    StadiumContainer stadiums_grass_surface();
    StadiumContainer stadiums_turf_surface();
    int find(string stadium_name) const;
    bool contains(string stadium_name) const;
    void print() const;
};

#endif // STADIUMCONTAINER_H
