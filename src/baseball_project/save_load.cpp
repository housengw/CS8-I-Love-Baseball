#include "save_load.h"


void save_stadiums (string file_name, StadiumContainer scontainer){

}

void load_stadiums (string file_name, StadiumContainer &mcontainer)
{
    ifstream file;
    StadiumContainer s_temp;
    string stadium, team, address1, address2, phone, capacity, surface, line, date_str;

    file.open(file_name);
    if (file.fail()){            //message for failure to open the file
        cout <<" File failed to open..."<<endl;
    }
    cout << "  Reading file " <<endl;
    if (file.is_open()){
        while (getline (file, stadium, '\n')){
            rstrip_newline(stadium);
//            cout<<"'"<<stadium<<"'"<<endl;
            getline (file, team, '\n');
            rstrip_newline(team);
//            cout<<"'"<<team<<"'"<<endl;
            getline (file, address1, '\n');
            rstrip_newline(address1);
//            cout<<"'"<<address1<<"'"<<endl;
            getline (file, address2, '\n');
            rstrip_newline(address2);
//            cout<<"'"<<address2<<"'"<<endl;
            getline (file, phone, '\n');
            rstrip_newline(phone);
//            cout<<"'"<<phone<<"'"<<endl;

            getline(file, date_str, '\n');
            rstrip_newline(date_str);
            getline(file, capacity, '\n');
            rstrip_newline(capacity);
            getline (file, surface, '\n');
            rstrip_newline(surface);
//            cout<<"'"<<surface<<"'"<<endl;
            getline (file, line, '\n');
//            cout<<"'"<<line<<"'"<<endl;

            Date date;
            date.set_whole(date_str);
            address1 += address2;
            Stadium _stadium (stadium, team, address1, phone, date, stoi(capacity), surface);
            s_temp.add(_stadium);
        }
    }

    file.close();                //close the file
    cout <<"-----------Stadiums loaded-----------"<<endl;
    mcontainer = s_temp;
}
