#include <iostream>
#include "stadium_container.h"
#include "stadiums_list.h"

using namespace std;

int main()
{

    cout <<endl<< "=============================================" <<endl;
    cout << endl << "  Reading from file National Teams" <<endl;
    cout <<endl<< "=============================================" <<endl;
    StadiumContainer NationalTeams;
    StadiumContainer AmericanTeams;
    StadiumContainer Sorted;

    StadiumsList list;
    list.load_stadiums ("NationalTeams.txt",NationalTeams);
    NationalTeams.print();

    cout <<endl<< "=============================================" <<endl;
    cout << endl << "  Reading from file American Teams" <<endl;
    cout <<endl<< "=============================================" <<endl;

    list.load_stadiums ("AmericanTeams.txt",AmericanTeams);
    AmericanTeams.print();

    cout <<endl<< "=============================================" <<endl;
    cout << endl << "  Test sorted by Team name" <<endl;
    cout <<endl<< "=============================================" <<endl;
    cout <<endl<< "---------------------------------------" <<endl;
    cout << endl << " National Teams " << endl;
    cout <<endl<< "---------------------------------------" <<endl;
    Sorted = list.sort_by_stadium_name(NationalTeams);
    Sorted.print();

    cout <<endl<< "---------------------------------------" <<endl;
    cout << endl << " American Teams " << endl;
    cout <<endl<< "---------------------------------------" <<endl;
    Sorted = list.sort_by_stadium_name(AmericanTeams);
    Sorted.print();

    cout <<endl<< "=============================================" <<endl;
    cout << endl << "  Teams with grass surface sorted by Team name" <<endl;
    cout <<endl<< "=============================================" <<endl;

    cout <<endl<< "---------------------------------------" <<endl;
    cout << endl << " National Teams " << endl;
    cout <<endl<< "---------------------------------------" <<endl;
    Sorted = list.stadiums_grass_sorted_name(NationalTeams);
    Sorted.print();

    cout <<endl<< "---------------------------------------" <<endl;
    cout << endl << " American Teams " << endl;
    cout <<endl<< "---------------------------------------" <<endl;
    Sorted = list.stadiums_grass_sorted_name(AmericanTeams);
    Sorted.print();
    return 0;
}
