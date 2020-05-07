#include "stadiums_list.h"

StadiumsList::StadiumsList()
{
//    load_stadiums ("NationalTeams.txt", _nationalTeams);
//    load_stadiums ("AmericanTeams.txt", _americanTeams);
}

void StadiumsList::save_stadiums (StadiumContainer scontainer)
{

}

void StadiumsList::save_stadiums (string file_name, StadiumContainer scontainer)
{

}

StadiumContainer StadiumsList::sort_by_stadium_name (StadiumContainer scontainer)
{
    StadiumContainer s_temp = scontainer;
    for(size_t i = 0; i < s_temp.size( ); i++)
        for(size_t j = 0; j < s_temp.size( ); j++)
            if(s_temp[j].get_stadium_name() > s_temp[i].get_stadium_name())
                swap(s_temp[i], s_temp[j]);
    return s_temp;
}

StadiumContainer StadiumsList::sort_by_team_name (StadiumContainer scontainer)
{
    StadiumContainer s_temp = scontainer;
    for(size_t i = 0; i < s_temp.size( ); i++)
        for(size_t j = 0; j < s_temp.size( ); j++)
            if(s_temp[j].get_team_name() > s_temp[i].get_team_name())
                swap(s_temp[i], s_temp[j]);
    return s_temp;
}

StadiumContainer StadiumsList::sort_by_opened_Date (StadiumContainer scontainer)
{
    StadiumContainer s_temp = scontainer;
//    for(size_t i = 0; i < s_temp.size( ); i++)
//        for(size_t j = 0; j < s_temp.size( ); j++)
//            if(s_temp[j].get_date_opened() > s_temp[i].get_date_opened())
//                swap(s_temp[i], s_temp[j]);
    return s_temp;
}

StadiumContainer StadiumsList::stadiums_grass_sorted_name (StadiumContainer scontainer)
{
    return sort_by_team_name (scontainer.stadiums_grassSurface());
}

void StadiumsList::load_stadiums (string file_name, StadiumContainer &mcontainer)
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

            file >> m >> slash >> d >> slash >> y
                    >> capacity ;
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

void StadiumsList::swap(Stadium& t1, Stadium& t2)
{
    Stadium temp = t1;
    t1 = t2;
    t2 = temp;
}
