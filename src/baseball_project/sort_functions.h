#ifndef SORT_FUNCTIONS_H
#define SORT_FUNCTIONS_H

#include <vector>
#include "stadium_container.h"

/***********************************************
 * bool compare_team_name ( Stadium i,  Stadium j);
 *   Compare: Stadium i and j
 *   Parameters: Stadium i and j
 *   Return: true if team names in ascending order else false
 **********************************************/
bool compare_team_name ( Stadium i,  Stadium j);

/***********************************************
 * bool compare_stadium_name ( Stadium i,  Stadium j);
 *   Compare: Stadium i and j
 *   Parameters: Stadium i and j
 *   Return: true if stadium names in ascending order else false
 **********************************************/
bool compare_stadium_name ( Stadium i, Stadium j);

/***********************************************
 * bool compare_dates ( Stadium i,  Stadium j);
 *   Compare: Stadium i and j
 *   Parameters: Stadium i and j
 *   Return: true if i opened before j
 **********************************************/
bool compare_dates ( Stadium i, Stadium j);

/***********************************************
 * vector<Stadium> vectorize(const StadiumContainer& s);
 *   Vectorize: insert stadiums from container into vector
 *   Parameters: Stadium container
 *   Return: vector of stadiums
 **********************************************/
vector<Stadium> vectorize(const StadiumContainer& s);

/***********************************************
 * void add_stadiums_in_vector(const StadiumContainer& s, vector<Stadium> &dest);
 *   Vectorize: insert stadiums from container into vector
 *   Parameters: Stadium container
 *   Return: vector of stadiums by reference
 **********************************************/
void add_stadiums_in_vector(const StadiumContainer& s, vector<Stadium> &dest);

/***********************************************
 * void sort_by_team_name (vector <Stadium>& stadiums);
 *   Sort: stadiums by team name
 *   Parameters: vector of stadiums
 *   Return: None
 **********************************************/
void sort_by_team_name (vector <Stadium>& stadiums);

/***********************************************
 * void sort_by_stadium_name (vector <Stadium>& stadiums);
 *   Sort: stadiums by stadium name
 *   Parameters: vector of stadiums
 *   Return: None
 **********************************************/
void sort_by_stadium_name (vector <Stadium>& stadiums);

/***********************************************
 * vector<Stadium> sorted_by_stadium_name(const StadiumContainer& stadiums);
 *   Sort: stadiums by stadium name
 *   Parameters: vector of stadiums
 *   Return: vector of stadiums sorted by name
 **********************************************/
vector<Stadium> sorted_by_stadium_name(const StadiumContainer& stadiums);

/***********************************************
 * void sort_by_opened_date (vector <Stadium>& stadiums);
 *   Sort: stadiums by opened date
 *   Parameters: vector of stadiums
 *   Return: None
 **********************************************/
void sort_by_opened_date (vector <Stadium>& stadiums);


#endif // SORT_FUNCTIONS_H
