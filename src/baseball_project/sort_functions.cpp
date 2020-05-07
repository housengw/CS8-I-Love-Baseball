#include "sort_functions.h"


void sort_by_team_name(vector<Stadium> &stadiums)
{
    std::sort (stadiums.begin(), stadiums.end(), compare_team_name);
}

void sort_by_stadium_name (vector <Stadium>& stadiums)
{
    std::sort (stadiums.begin(), stadiums.end(), compare_stadium_name);
}

void sort_by_opened_date (vector <Stadium>& stadiums)
{
    //needs a function to compare dates
//    std::sort (stadiums.begin(), stadiums.end());
}

void add_stadiums_in_vector (StadiumContainer s, vector<Stadium> & dest)
{
    for (size_t i = 0; i < s.size(); ++i) {
        dest.push_back(s[i]);
    }
}

bool compare_team_name ( Stadium i,  Stadium j)
{
    return (i <j);
}

//compare stadium names
bool compare_stadium_name ( Stadium i, Stadium j)
{
    return (i >j);
}
