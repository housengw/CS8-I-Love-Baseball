#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H

#include <iostream>
#include <fstream>
#include "stadium_container.h"
using namespace std;

void save_stadiums (string file_name, StadiumContainer mcontainer);
void load_stadiums (string file_name, string league, StadiumContainer &mcontainer);


#endif // SAVE_LOAD_H
