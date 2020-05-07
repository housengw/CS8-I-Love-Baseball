#include <iostream>
#include "sort_functions.h"
#include "save_load.h"


void print (vector<Stadium> source);
using namespace std;

int main()
{
    cout <<endl<< "=============================================" <<endl;
    cout << endl << "  Reading from file National Teams" <<endl;
    cout <<endl<< "=============================================" <<endl;
    StadiumContainer NationalTeams;
    StadiumContainer AmericanTeams;

    load_stadiums ("../files/NationalTeams.txt",NationalTeams);
    NationalTeams.print();

    cout <<endl<< "=============================================" <<endl;
    cout << endl << "  Reading from file American Teams" <<endl;
    cout <<endl<< "=============================================" <<endl;

    load_stadiums ("../files/AmericanTeams.txt",AmericanTeams);
    AmericanTeams.print();

    cout <<endl<< "=============================================" <<endl;
    cout << endl << "  Test sorted by Team name" <<endl;
    cout <<endl<< "=============================================" <<endl;
    cout <<endl<< "---------------------------------------" <<endl;
    cout << endl << " National Teams " << endl;
    cout <<endl<< "---------------------------------------" <<endl;
    vector<Stadium> NTsortName;
    add_stadiums_in_vector(NationalTeams, NTsortName);
    sort_by_team_name (NTsortName);
    print (NTsortName);

    cout <<endl<< "---------------------------------------" <<endl;
    cout << endl << " American Teams " << endl;
    cout <<endl<< "---------------------------------------" <<endl;
    vector<Stadium> ATsortName;
    add_stadiums_in_vector(AmericanTeams, ATsortName);
    sort_by_stadium_name(ATsortName);
    print (ATsortName);

    cout <<endl<< "=============================================" <<endl;
    cout << endl << "  Teams with grass surface sorted by Team name" <<endl;
    cout <<endl<< "=============================================" <<endl;

    cout <<endl<< "---------------------------------------" <<endl;
    cout << endl << " National Teams " << endl;
    cout <<endl<< "---------------------------------------" <<endl;

    add_stadiums_in_vector(NationalTeams.stadiums_grassSurface(), NTsortName);
    sort_by_team_name (NTsortName);
    print (NTsortName);

    cout <<endl<< "---------------------------------------" <<endl;
    cout << endl << " American Teams " << endl;
    cout <<endl<< "---------------------------------------" <<endl;
    add_stadiums_in_vector(AmericanTeams.stadiums_grassSurface(), ATsortName);
    sort_by_stadium_name(ATsortName);
    print (ATsortName);

    cout << endl << "===================END================" <<endl;
    return 0;
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
