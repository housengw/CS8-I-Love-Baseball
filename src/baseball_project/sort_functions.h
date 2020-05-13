#ifndef SORT_FUNCTIONS_H
#define SORT_FUNCTIONS_H

#include <vector>
#include "stadium_container.h"

//compare team names
bool compare_team_name ( Stadium i,  Stadium j);

//compare stadium names
bool compare_stadium_name ( Stadium i, Stadium j);

//need a function to compare dates


vector<Stadium> vectorize(const StadiumContainer& s);

//push stadiums into vector
void add_stadiums_in_vector(const StadiumContainer& s, vector<Stadium> &dest);

//sort the stadiums by team name
void sort_by_team_name (vector <Stadium>& stadiums);

//sort the stadiums by stadium name
void sort_by_stadium_name (vector <Stadium>& stadiums);

vector<Stadium> sorted_by_stadium_name(const StadiumContainer& stadiums);

//sort the stadiums by opened date
void sort_by_opened_date (vector <Stadium>& stadiums);


#endif // SORT_FUNCTIONS_H
