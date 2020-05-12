#include <iostream>
#include "sort_functions.h"
#include "save_load.h"

using namespace std;

void print (vector<Stadium> source);
void test_load_stadiums();
void test_load_edges();


const std::string SRC_NATIONAL_FILE_PATH = "../../app/files/NationalTeams.txt";
const std::string SRC_AMERICAN_FILE_PATH = "../../app/files/AmericanTeams.txt";
const std::string SRC_EDGES_FILE_PATH = "../../app/files/edges.csv";


int main()
{
    test_load_edges();
    test_load_stadiums();
    return 0;
}


void test_load_stadiums(){
    cout <<endl<< "=============================================" <<endl;
    cout << endl << "  Reading from file National Teams" <<endl;
    cout <<endl<< "=============================================" <<endl;
    StadiumContainer NationalTeams;
    StadiumContainer AmericanTeams;

    load_stadiums (SRC_NATIONAL_FILE_PATH, NATIONAL_LEAGUE_NAME, NationalTeams);
    NationalTeams.print();

    cout <<endl<< "=============================================" <<endl;
    cout << endl << "  Reading from file American Teams" <<endl;
    cout <<endl<< "=============================================" <<endl;

    load_stadiums (SRC_AMERICAN_FILE_PATH, AMERICAN_LEAGUE_NAME, AmericanTeams);
    AmericanTeams.print();

    cout <<endl<< "=============================================" <<endl;
    cout << endl << "  Test sorted by Team name" <<endl;
    cout <<endl<< "=============================================" <<endl;
    cout <<endl<< "---------------------------------------" <<endl;
    cout << endl << " National Teams " << endl;
    cout <<endl<< "---------------------------------------" <<endl;
    vector<Stadium> NTsortName;
    NTsortName = vectorize(NationalTeams);
    sort_by_team_name (NTsortName);
    print (NTsortName);

    cout <<endl<< "---------------------------------------" <<endl;
    cout << endl << " American Teams " << endl;
    cout <<endl<< "---------------------------------------" <<endl;
    vector<Stadium> ATsortName;
    ATsortName = vectorize(AmericanTeams);
    sort_by_stadium_name(ATsortName);
    print (ATsortName);

    cout <<endl<< "=============================================" <<endl;
    cout << endl << "  Teams with grass surface sorted by Team name" <<endl;
    cout <<endl<< "=============================================" <<endl;

    cout <<endl<< "---------------------------------------" <<endl;
    cout << endl << " National Teams " << endl;
    cout <<endl<< "---------------------------------------" <<endl;
    NTsortName = vectorize(NationalTeams.stadiums_grass_surface());
    sort_by_team_name (NTsortName);
    print (NTsortName);

    cout <<endl<< "---------------------------------------" <<endl;
    cout << endl << " American Teams " << endl;
    cout <<endl<< "---------------------------------------" <<endl;
    ATsortName = vectorize(AmericanTeams.stadiums_grass_surface());
    sort_by_stadium_name(ATsortName);
    print (ATsortName);

    cout << endl << "===================END================" <<endl;
}


void test_load_edges(){
    StadiumContainer national_stadiums, american_stadiums, all_stadiums;
    EdgeContainer edge_list;
    load_stadiums(SRC_NATIONAL_FILE_PATH, NATIONAL_LEAGUE_NAME, national_stadiums);
    load_stadiums(SRC_AMERICAN_FILE_PATH, AMERICAN_LEAGUE_NAME,american_stadiums);
    for (size_t i=0; i<national_stadiums.size(); i++){
        all_stadiums.add(national_stadiums[i]);
    }
    for (size_t i=0; i<american_stadiums.size(); i++){
        all_stadiums.add(american_stadiums[i]);
    }
    edge_list = load_edges(SRC_EDGES_FILE_PATH, all_stadiums);
}


void print (vector<Stadium> source)
{
    vector <Stadium> :: iterator it;
    for (it = source.begin(); it != source.end(); ++it) {
        cout << endl << "    Team: " << it->get_team_name();
        cout << endl << " Stadium: " << it->get_stadium_name();
        cout << endl;
    }
}
