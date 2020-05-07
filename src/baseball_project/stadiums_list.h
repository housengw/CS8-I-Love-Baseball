#ifndef STADIUMSLIST_H
#define STADIUMSLIST_H

#include <iostream>
#include <fstream>
#include "stadium_container.h"

using namespace std;

class StadiumsList
{
public:

    /****************************************
    **  CONSTRUCTORS  **
    *****************************************/
    StadiumsList();

    /****************************************
    **  SORT FUNCTIONS  **
    *****************************************/
    StadiumContainer sort_by_stadium_name (StadiumContainer mcontainer);
    StadiumContainer sort_by_team_name (StadiumContainer mcontainer);
    StadiumContainer sort_by_opened_Date (StadiumContainer mcontainer);
    StadiumContainer stadiums_grass_sorted_name (StadiumContainer mcontainer);


    /****************************************
    **  SAVE AND LOAD IN FILES  **
    *****************************************/
    void save_stadiums(StadiumContainer scontainer);
    StadiumContainer load_stadiums ();
    void save_stadiums (string file_name1, StadiumContainer mcontainer);
    void load_stadiums (string file_name1, StadiumContainer &mcontainer);

    void swap(Stadium& t1, Stadium& t2);


private:
    StadiumContainer _americanTeams;
    StadiumContainer _nationalTeams;
};

#endif // STADIUMSLIST_H
