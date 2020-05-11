#include "save_load.h"


void save_stadiums (string file_name,
                    const StadiumContainer& scontainer){

}

void load_stadiums (string file_name, string league, StadiumContainer &mcontainer)
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
            Stadium s(stadium, team, address1, phone, date, stoi(capacity), surface);
            s.set_league(league);
            s_temp.add(s);
        }
    }

    file.close();                //close the file
    cout <<"-----------Stadiums loaded-----------"<<endl;
    mcontainer = s_temp;
}


EdgeContainer load_edges(string file_name,
                         const StadiumContainer& reference){
    ifstream fin;
    string line;
    EdgeContainer edge_list;
    vector<string> line_fragments;
    fin.open(file_name);
    while (!fin.eof()){
        getline(fin, line);
        rstrip_newline(line);
        line_fragments = split(line, ',');
        int index_a = reference.find(line_fragments[0]);
        int index_b = reference.find(line_fragments[1]);
//        assert(index_a >= 0 && index_b >= 0);
        if (index_a == -1 || index_b == -1){
//            cout<<"line_fragments[0]: "<<line_fragments[0]<<endl;
//            cout<<"line_fragments[1]: "<<line_fragments[1]<<endl;
        }
        else{
            edge_list.add(Edge(reference[index_a],
                               reference[index_b],
                               stoi(line_fragments[2])));
        }
    }
    return edge_list;
}
