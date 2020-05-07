#include "save_load.h"


void save_stadiums (string file_name, StadiumContainer scontainer);

void load_stadiums (string file_name, StadiumContainer &mcontainer)
{
    ifstream file;
    StadiumContainer s_temp;
    string stadium,team, adress1, adress2 ,phone,surface, line;
    int capacity,m,d,y;
    char slash;

    file.open(file_name);
    if (file.fail()){            //message for failure to open the file
        cout <<" File failed to open..."<<endl;
    }
    cout << "  Reading file " <<endl;
    if (file.is_open()){
        while (getline (file, stadium, '\n')){
            getline (file, team, '\n');
            getline (file, adress1, '\n');
            getline (file, adress2, '\n');
            getline (file, phone, '\n');

            file >> m >> slash >> d >> slash >> y >> capacity ;

            getline (file, line, '\n');
            getline (file, surface, '\n');
            getline (file, line, '\n');

            Date date (m,d,y);
            adress1 += adress2;

            Stadium _stadium (stadium, team, adress1, phone, date,capacity, surface);
            s_temp.add(_stadium);
        }
    }

    file.close();                //close the file
    cout <<"-----------Stadiums loaded-----------"<<endl;
    mcontainer = s_temp;
}
