#include "sort_functions.h"


void sort_by_team_name(vector<Stadium> &stadiums)
{
    std::sort (stadiums.begin(), stadiums.end(), compare_team_name);
}

void sort_by_stadium_name (vector <Stadium>& stadiums)
{
    std::sort (stadiums.begin(), stadiums.end(), compare_stadium_name);
}


vector<Stadium> sorted_by_stadium_name(const StadiumContainer& stadiums){
    vector<Stadium> stadium_v;
    for (size_t i=0; i<stadiums.size(); i++){
        stadium_v.insert(stadium_v.end(), stadiums[i]);
    }
    sort_by_stadium_name(stadium_v);
    return stadium_v;
}


void sort_by_opened_date (vector <Stadium>& stadiums)
{
    std::sort (stadiums.begin(), stadiums.end(), compare_dates);
}


vector<Stadium> vectorize(const StadiumContainer& s){
    vector<Stadium> temp;
    for (size_t i=0; i<s.size(); i++){
        temp.push_back(s[i]);
    }
    return temp;
}

void add_stadiums_in_vector (const StadiumContainer& s, vector<Stadium> & dest)
{
    for (size_t i = 0; i < s.size(); i++) {
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

//compare stadiums date opened
bool compare_dates (Stadium i, Stadium j)
{
    Date date;
    return (date.compare_dates (i.get_date_opened(),j.get_date_opened()));
}

