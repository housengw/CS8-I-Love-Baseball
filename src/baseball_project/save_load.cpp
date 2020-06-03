#include "save_load.h"


/**************************************************************
 * void save_stadiums (string file_name, const StadiumContainer& sc)
 * ____________________________________________________________
 * Saves stadiums into file
 * ___________________________________________________________
 * Pre-Condition
 * string file name and a stadium container is given
 *
 * Post-Condition
 * stadiums in the stadium container has been saved to a file
 *************************************************************/
void save_stadiums (string file_name,
                    const StadiumContainer& sc){
    ofstream fout;
    fout.open(file_name);
    for (size_t i=0; i<sc.size(); i++){
        fout<<sc[i].get_stadium_name()<<endl
            <<sc[i].get_team_name()<<endl
            <<sc[i].get_address1()<<endl
            <<sc[i].get_address2()<<endl
            <<sc[i].get_phone_number()<<endl
            <<sc[i].get_date_opened().get_date()<<endl
            <<sc[i].get_capacity()<<endl
            <<sc[i].get_surface()<<endl;
        if (i != sc.size()-1)
            fout<<endl;
    }
}

/**************************************************************
 * void save_edges (string file_name, const EdgeContainer& ec)
 * ____________________________________________________________
 * Saves edgess into file
 * ___________________________________________________________
 * Pre-Condition
 * string file name and an edge container is given
 *
 * Post-Condition
 * edges in the edge container is saved to a file
 *************************************************************/
void save_edges (string file_name, const EdgeContainer& ec){
    ofstream fout;
    fout.open(file_name);
    for (size_t i=0; i<ec.size(); i++){
        fout<<ec[i].get_left_node()<<","
            <<ec[i].get_right_node()<<","
            <<ec[i].get_cost();
        if (i != ec.size()-1){
            fout<<endl;
        }
    }
}


/**************************************************************
 * void save_points (string file_name, const PointContainer& pc)
 * ____________________________________________________________
 * Saves points into file
 * ___________________________________________________________
 * Pre-Condition
 * string file name and a point container is given
 *
 * Post-Condition
 * points in the point container is saved to a file
 *************************************************************/
void save_points (string file_name, const PointContainer& pc){
    ofstream fout;
    fout.open(file_name);
    for (size_t i=0; i<pc.size(); i++){
        fout<<pc[i].get_name()<<","
            <<pc[i].get_x()<<","
            <<pc[i].get_y();
        if (i != pc.size()-1){
            fout<<endl;
        }
    }
}


/**************************************************************
 * void save_password(string file_name, string password)
 * ____________________________________________________________
 * This method save password in file
 * ___________________________________________________________
 * Pre-Condition
 * string file name and password are given
 *
 * Post-Condition
 * None
 *************************************************************/
void save_password(string file_name,
                   string password)
{
    ofstream fout;
    fout.open(file_name);
    fout<<password;
    fout.close();
}

/**************************************************************
 * void load_stadiums (string file_name, string league, StadiumContainer &mcontainer)
 * ____________________________________________________________
 * This method load stadiums from file and insert into stadium container
 * ___________________________________________________________
 * Pre-Condition
 * string file name and league, stadium container to store stadiums
 *
 * Post-Condition
 * Stadiums loaded into stadium container
 *************************************************************/
void load_stadiums (string file_name, string league, StadiumContainer &mcontainer)
{
    ifstream file;
    StadiumContainer s_temp;
    string stadium, team, address1, address2, phone, capacity, surface, line, date_str;

    file.open(file_name);
    if (file.fail()){            //message for failure to open the file
        cout <<" File failed to open..."<<endl;
    }
    if (file.is_open()){
        while (getline (file, stadium, '\n')){
            rstrip_newline(stadium);

            getline (file, team, '\n');
            rstrip_newline(team);

            getline (file, address1, '\n');
            rstrip_newline(address1);

            getline (file, address2, '\n');
            rstrip_newline(address2);

            getline (file, phone, '\n');
            rstrip_newline(phone);

            getline(file, date_str, '\n');
            rstrip_newline(date_str);

            getline(file, capacity, '\n');
            rstrip_newline(capacity);

            getline (file, surface, '\n');
            rstrip_newline(surface);

            getline (file, line, '\n');

            Date date;
            date.set_whole(date_str);

            Stadium s(stadium, team, address1,address2, phone, date, stoi(capacity), surface);
            s.set_league(league);
            s_temp.add(s);
        }
    }
    file.close();                //close the file
    mcontainer = s_temp;
}

/**************************************************************
 * EdgeContainer load_edges(string file_name, const StadiumContainer& reference)
 * ____________________________________________________________
 * This method load edges from file and insert into edge container
 * ___________________________________________________________
 * Pre-Condition
 * string file name and reference stadium container
 *
 * Post-Condition
 * Edges loaded into edge container
 *************************************************************/
EdgeContainer _load_edges(string file_name)                   //IN - file name
{
    ifstream fin;
    string line;
    EdgeContainer edge_list;
    vector<string> line_fragments;
    fin.open(file_name);
    while (!fin.eof()){
        getline(fin, line);
        rstrip_newline(line);
        line_fragments = split(line, ',');
        //        assert(reference.contains(line_fragments[0]) &&
        //               reference.contains(line_fragments[1]));
        edge_list.add(Edge(line_fragments[0],
                      line_fragments[1],
                stoi(line_fragments[2])));
    }
    return edge_list;
}

/**************************************************************
 * PointContainer load_points(string file_name )
 * ____________________________________________________________
 * This method load points from file and insert into point container
 * ___________________________________________________________
 * Pre-Condition
 * string file name is given
 *
 * Post-Condition
 * points loaded into points container
 *************************************************************/
PointContainer _load_points(string file_name)   //IN - string file name
{
    ifstream fin;
    string line;
    PointContainer point_list;
    vector<string> line_fragments;
    fin.open(file_name);
    while (!fin.eof()){
        getline(fin, line);
        rstrip_newline(line);
        line_fragments = split(line, ',');
        point_list.add(Point(line_fragments[0],
                       stoi(line_fragments[1]),
                stoi(line_fragments[2])));
    }
    return point_list;
}

/**************************************************************
 * string load_password(string file_name)
 * ____________________________________________________________
 * This method load password from a file
 * ___________________________________________________________
 * Pre-Condition
 * string file name is given
 *
 * Post-Condition
 * return the password
 *************************************************************/
string load_password(string file_name)
{
    ifstream fin;
    fin.open(file_name);
    if (fin.is_open()){
        string password;
        getline(fin, password);
        return password;
    }
    return "";
}
