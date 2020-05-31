#include <iostream>
#include "sort_functions.h"
#include "save_load.h"
#include "map.h"

using namespace std;

void print (vector<Stadium> source);
void test_load_stadiums();
void test_load_edges();
void test_load_points();

void test_modify_sourvenir_name(vector<Stadium>& source);
void test_modify_sourvenir_price(vector<Stadium>& source);
void test_add_sourvenir(vector<Stadium>& source);

const std::string SRC_NATIONAL_FILE_PATH = "../../app/files/NationalTeams.txt";
const std::string SRC_AMERICAN_FILE_PATH = "../../app/files/AmericanTeams.txt";
const std::string SRC_EDGES_FILE_PATH = "../../app/files/edges.csv";
const std::string SRC_POINTS_FILE_PATH = "../../app/files/coordinates.csv";


int main()
{
    Map m;
    return 0;
}


void print (vector<Stadium> source)
{
    vector <Stadium> :: iterator it;
    for (it = source.begin(); it != source.end(); ++it) {
        cout << endl << "    Team: " << it->get_team_name();
        cout << endl << " Stadium: " << it->get_stadium_name();
        cout << endl;
//        it->print_souvenir_list();
        cout << endl;
    }
}

void test_modify_sourvenir_name(vector<Stadium>& source)
{
    vector <Stadium> :: iterator it;
    for (it = source.begin(); it != source.end(); ++it) {
        it->modify_souvenir_name("Baseball cap", "the new name");
    }
}
void test_modify_sourvenir_price(vector<Stadium>& source)
{
    vector <Stadium> :: iterator it;
    for (it = source.begin(); it != source.end(); ++it) {
        it->modify_souvenir_price("Autographed baseball", 1000);
    }
}

void test_add_sourvenir(vector<Stadium>& source)
{
    vector <Stadium> :: iterator it;
    for (it = source.begin(); it != source.end(); ++it) {
        it->add_souvenir("this is cool", 500);
    }
}
