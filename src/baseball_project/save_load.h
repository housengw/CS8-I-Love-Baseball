#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H

#include <iostream>
#include <fstream>
#include "stadium_container.h"
#include "edge_container.h"
#include "point_container.h"
using namespace std;

/***********************************************
 * void save_stadiums (string file_name, const StadiumContainer& mcontainer);
 *   Save: save stadiums into file
 *   Parameters: string file name, StadiumContainer mcontainer
 *   Return: None
 **********************************************/
void save_stadiums (string file_name, const StadiumContainer& mcontainer);


/***********************************************
 * void save_password(string file_name, string password);
 *   Save: password into file
 *   Parameters: string file name, string password
 *   Return: None
 **********************************************/
void save_password(string file_name, string password);


/***********************************************
 * void load_stadiums (string file_name, string league, StadiumContainer &mcontainer);
 *   Load: load stadiums from file and insert into container
 *   Parameters: string filename, strign league, and stadium container
 *   Return: None
 **********************************************/
void load_stadiums (string file_name, string league, StadiumContainer &mcontainer);


/***********************************************
 * EdgeContainer load_edges (string file_name, const StadiumContainer& reference);
 *   Load: load edges from file
 *   Parameters: string file name, and reference stadium container
 *   Return: edge container
 **********************************************/
EdgeContainer load_edges(string file_name, const StadiumContainer& reference);


/***********************************************
 * PointContainer load_points (string file_name);
 *   Load: load points from file
 *   Parameters: string file name
 *   Return: point container
 **********************************************/
PointContainer load_points(string file_name);


/***********************************************
 * string load_password(string file_name);
 *   Load: load password from file
 *   Parameters: string file name
 *   Return: string password
 **********************************************/
string load_password(string file_name);


#endif // SAVE_LOAD_H
