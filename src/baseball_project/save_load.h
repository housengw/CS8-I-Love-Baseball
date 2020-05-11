#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H

#include <iostream>
#include <fstream>
#include "stadium_container.h"
#include "edge_container.h"
using namespace std;

void save_stadiums (string file_name, const StadiumContainer& mcontainer);
void load_stadiums (string file_name, string league, StadiumContainer &mcontainer);
EdgeContainer load_edges(string file_name, const StadiumContainer& reference);


#endif // SAVE_LOAD_H
