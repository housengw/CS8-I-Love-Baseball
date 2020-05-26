#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H

#include "edge_container.h"
#include "point_container.h"
#include "stadium_container.h"
#include <fstream>
#include <iostream>
using namespace std;

void save_stadiums(string file_name, const StadiumContainer &mcontainer);
void save_password(string file_name, string password);
void load_stadiums(string file_name, string league,
                   StadiumContainer &mcontainer);
EdgeContainer load_edges(string file_name, const StadiumContainer &reference);
PointContainer load_points(string file_name);
string load_password(string file_name);

#endif // SAVE_LOAD_H
