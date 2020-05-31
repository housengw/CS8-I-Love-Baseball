#include "sort_functions.h"


/**************************************************************
 * void sort_by_team_name(vector<Stadium> &stadiums)
 * ____________________________________________________________
 * This method sort the stadiums by team name
 * ___________________________________________________________
 * Pre-Condition
 * vector of stadiums is given
 *
 * Post-Condition
 * stadiums sorted by team name
 *************************************************************/
void sort_by_team_name(vector<Stadium> &stadiums)   //IN/OUT  vector of stadiums
{
    std::sort (stadiums.begin(), stadiums.end(), compare_team_name);
}

/**************************************************************
 * void sort_by_stadium_name(vector<Stadium> &stadiums)
 * ____________________________________________________________
 * This method sort the stadiums by stadium name
 * ___________________________________________________________
 * Pre-Condition
 * vector of stadiums is given
 *
 * Post-Condition
 * stadiums sorted by stadium name
 *************************************************************/
void sort_by_stadium_name (vector <Stadium>& stadiums)  //IN/OUT  vector of stadiums
{
    std::sort (stadiums.begin(), stadiums.end(), compare_stadium_name);
}


/**************************************************************
 * void sort_by_opened_date(vector<Stadium> &stadiums)
 * ____________________________________________________________
 * This method sort the stadiums by opened date
 * ___________________________________________________________
 * Pre-Condition
 * vector of stadiums is given
 *
 * Post-Condition
 * stadiums sorted by opened date
 *************************************************************/
void sort_by_opened_date (vector <Stadium>& stadiums)   //IN/OUT  vector of stadiums
{
    std::sort (stadiums.begin(), stadiums.end(), compare_dates);
}

/**************************************************************
 * vector<Stadium> sorted_by_stadium_name(const StadiumContainer& stadiums){
 * ____________________________________________________________
 * This method sort the stadiums by stadium name
 * ___________________________________________________________
 * Pre-Condition
 * stadium container is given
 *
 * Post-Condition
 * stadiums sorted by stadium name and return in vector
 *************************************************************/
vector<Stadium> sorted_by_stadium_name(const StadiumContainer& stadiums)  //IN/OUT stadiums
{
    vector<Stadium> stadium_v;
    for (size_t i=0; i<stadiums.size(); i++){
        stadium_v.insert(stadium_v.end(), stadiums[i]);
    }
    sort_by_stadium_name(stadium_v);
    return stadium_v;
}


/**************************************************************
 * vector<Stadium> vectorize(const StadiumContainer& s)
 * ____________________________________________________________
 * This method inserts stadiums into vector
 * ___________________________________________________________
 * Pre-Condition
 * stadium container is given
 *
 * Post-Condition
 * stadiums inserted into vector
 *************************************************************/
vector<Stadium> vectorize(const StadiumContainer& s)
{
    vector<Stadium> temp;
    for (size_t i=0; i<s.size(); i++){
        temp.push_back(s[i]);
    }
    return temp;
}


StadiumContainer containerize(const vector<Stadium>& s){
    StadiumContainer c;
    for (size_t i=0; i<s.size(); i++){
        c.add(s[i]);
    }
    return c;
}


/**************************************************************
 * void add_stadiums_in_vector (const StadiumContainer& s, vector<Stadium> & dest)
 * ____________________________________________________________
 * This method inserts stadiums into vector
 * ___________________________________________________________
 * Pre-Condition
 * stadium container and vector are given
 *
 * Post-Condition
 * stadiums inserted into vector
 *************************************************************/
void add_stadiums_in_vector (const StadiumContainer& s, vector<Stadium> & dest)
{
    for (size_t i = 0; i < s.size(); i++) {
        dest.push_back(s[i]);
    }
}

/**************************************************************
 * bool compare_team_name ( Stadium i,  Stadium j)
 * ____________________________________________________________
 * This method compare stadiums by team name
 * ___________________________________________________________
 * Pre-Condition
 * stadium i and j to compare
 *
 * Post-Condition
 * return true is stadium i and j team name are in ascending order
 *************************************************************/
bool compare_team_name ( Stadium i,  Stadium j)
{
    return (i <j);
}

/**************************************************************
 * bool compare_stadium_name ( Stadium i,  Stadium j)
 * ____________________________________________________________
 * This method compare stadiums by stadium name
 * ___________________________________________________________
 * Pre-Condition
 * stadium i and j to compare
 *
 * Post-Condition
 * return true is stadium i and j stadium name are in ascending order
 *************************************************************/
bool compare_stadium_name ( Stadium i, Stadium j)
{
    return (i >j);
}

/**************************************************************
 * bool compare_dates (Stadium i, Stadium j)
 * ____________________________________________________________
 * This method compare stadiums by date
 * ___________________________________________________________
 * Pre-Condition
 * stadium i and j to compare
 *
 * Post-Condition
 * return true if stadium i opened before stadium j
 *************************************************************/
bool compare_dates (Stadium i, Stadium j)
{
    Date date;
    return (date._compare_dates (i.get_date_opened(),j.get_date_opened()));
}

