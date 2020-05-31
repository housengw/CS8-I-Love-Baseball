#include "map.h"

/**************************************************************
 * Map::Map ();
 * ____________________________________________________________
 * This method intializes the members with default values
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * initialize private members to default values
 *************************************************************/
Map::Map()
{
    _initialize_stadiums();
    _initialize_points();
    _initialize_edges();
    _initialize_plottables();
    _selected_stadiums = _stadiums;
}

/**************************************************************
 * void Map::_initialize_stadiums()
 * ____________________________________________________________
 * This method intializes stadiums by loading from file
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * load stadiums from file into stadiums container
 *************************************************************/
void Map::_initialize_stadiums(){
    StadiumContainer national_stadiums, american_stadiums;

    load_stadiums(APP_NATIONAL_FILE_PATH, NATIONAL_LEAGUE_NAME, national_stadiums);
    load_stadiums(APP_AMERICAN_FILE_PATH, AMERICAN_LEAGUE_NAME, american_stadiums);

    for (size_t i=0; i<national_stadiums.size(); i++){
        _stadiums.add(national_stadiums[i]);
    }
    for (size_t i=0; i<american_stadiums.size(); i++){
        _stadiums.add(american_stadiums[i]);
    }
}

/**************************************************************
 * void Map::_initialize_edges()
 * ____________________________________________________________
 * This method intializes edges by loading from file
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * load edges from file into edges container
 *************************************************************/
void Map::_initialize_edges(){
    _edges = load_edges(APP_EDGES_FILE_PATH, _stadiums);
}


/**************************************************************
 * void Map::_initialize_points()
 * ____________________________________________________________
 * This method intializes points by loading from file
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * load points from file into points container
 *************************************************************/
void Map::_initialize_points(){
    _points = load_points(APP_POINTS_FILE_PATH);
}

/**************************************************************
 * void Map::_initialize_plottables()
 * ____________________________________________________________
 * This method intializes vector of plottable
 * ___________________________________________________________
 * Pre-Condition
 * edges are loaded
 *
 * Post-Condition
 * get coordinates of edges and insert into vector
 *************************************************************/
void Map::_initialize_plottables(){
    vector<Plottable> plottables;
    Point p1, p2;
    for (size_t i=0; i<_edges.size(); i++){
        p1 = _points.get_coordinates(_edges[i].get_left_node());
        p2 = _points.get_coordinates(_edges[i].get_right_node());
        plottables.insert(plottables.end(), Plottable(p1, p2));
    }
    _plottables = plottables;
}


/**************************************************************
 * void Map::update_stadium(string stadium_name, Stadium s)
 * ____________________________________________________________
 * This method upades stadiums information
 * ___________________________________________________________
 * Pre-Condition
 * Stadium name is given
 *
 * Post-Condition
 * update stadium information
 *************************************************************/
void Map::update_stadium(string stadium_name,  //IN - string stadium name
                         Stadium s)            //IN - Stadium s
{
    for (size_t i=0; i<_stadiums.size(); i++){
        if (_stadiums[i].get_stadium_name() == stadium_name){
            _stadiums[i] = s;
            return;
        }
    }
}

/**************************************************************
 * void Map::add_stadium(Stadium s)
 * ____________________________________________________________
 * This method adds a stadium into stadium container
 * ___________________________________________________________
 * Pre-Condition
 * Stadium s given
 *
 * Post-Condition
 * stadium added into container
 *************************************************************/
void Map::add_stadium(Stadium s)   //IN - Stadium s
{
    _stadiums.add(s);
}


StadiumContainer Map::get_trip(StadiumContainer selection){
    Container<Dijkstra> dijkstras;
    dijkstras = _make_shortest_paths(selection);

//    cout<<dijkstras.size()<<endl;
//    for(size_t i=0; i<dijkstras.size(); i++){
//        cout<<_stadiums[i].get_stadium_name()<<": ";
//        for (size_t j=0; j<dijkstras[i]._size; j++){
//            cout<<dijkstras[i].c[j]<<" ";
//        }
//        cout<<endl;
//    }

    vector<Stadium> v = vectorize(selection);
    vector<Stadium> best_case = v;
    int min_cost = INT_MAX;
    int cost;
    int n=0;
    do{
//        cost = _compute_cost(v, dijkstras);
//        if (cost < min_cost){
//            min_cost = cost;
//            best_case = v;
//        }
        n++;
        cout<<"loop "<<n<<"| min_cost: "<<min_cost<<"| cost: "<<cost<<endl;
    }while(next_permutation(v.begin(), v.end()));
    return containerize(best_case);
}


int Map::_compute_cost(vector<Stadium> stadiums, Container<Dijkstra> dijkstras){
    int cost = 0;
    for (size_t i=0; i<stadiums.size()-1; i++){
        int s1, s2;
        s1 = _stadiums.find(stadiums[i].get_stadium_name());
        s2 = _stadiums.find(stadiums[i+1].get_stadium_name());
        cost += dijkstras[s1].get_cost(s2);
    }
    return cost;
}

Container<Dijkstra> Map::_make_shortest_paths(StadiumContainer selection){
    Container<Dijkstra> dijkstras;
    int** adjacency_matrix = _make_adjacency_matrix();
    for (size_t i=0; i<selection.size(); i++){
        Dijkstra d(_stadiums.find(selection[i].get_stadium_name()),
                   adjacency_matrix,
                   _stadiums.size());
        dijkstras.add(Dijkstra(d));
    }

    return dijkstras;
}

int** Map::_make_adjacency_matrix(){
    int** adjacency_matrix;
    size_t matrix_size = _stadiums.size();
    adjacency_matrix = new int*[matrix_size];
    for (size_t i=0; i<matrix_size; i++){
        adjacency_matrix[i] = new int[matrix_size];
        for (size_t j=0; j<matrix_size; j++){
            string stadium_i, stadium_j;
            stadium_i = _stadiums[i].get_stadium_name();
            stadium_j = _stadiums[j].get_stadium_name();
            if (_edges.connected(stadium_i, stadium_j))
                adjacency_matrix[i][j] = _edges.get_cost(stadium_i, stadium_j);
            else
                adjacency_matrix[i][j] = -1;
        }
    }
    return adjacency_matrix;
}
