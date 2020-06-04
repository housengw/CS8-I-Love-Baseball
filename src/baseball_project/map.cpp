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
    _trip = StadiumContainer();
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
    _edges = _load_edges(APP_EDGES_FILE_PATH);
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
    _points = _load_points(APP_POINTS_FILE_PATH);
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
void Map::_initialize_plottables()
{
    vector<Plottable> plottables;
    Point p1, p2;

    //PROC - get coordinates of edges and insert into
    //       vector<Plottable>
    for (size_t i=0; i<_edges.size(); i++){
        p1 = _points.get_coordinates(_edges[i].get_left_node());
        p2 = _points.get_coordinates(_edges[i].get_right_node());
        plottables.insert(plottables.end(), Plottable(p1, p2));
    }
    _plottables = plottables;
}


/**************************************************************
 * EdgeContainer Map::_get_trip_edges() const
 * ____________________________________________________________
 * This method adds the edges of the trip into EdgeContainer
 * ___________________________________________________________
 * Pre-Condition
 * Verifies if _trip size == 0 return EdgeContainer
 *
 * Post-Condition
 * retrun EdgeContainer of trip edges
 *************************************************************/
EdgeContainer Map::_get_trip_edges() const
{
    //PROC - if trip size == 0 return the EdgeContainer
    //       else for each matched edges get the edges and insert into container
    if (_trip.size() == 0) return EdgeContainer();
    EdgeContainer edges;
    for (size_t i=0; i<_edges.size(); i++){
        for (size_t j=0; j<_trip.size()-1; j++){
            if (_edges[i].match(_trip[j].get_stadium_name(),
                                _trip[j+1].get_stadium_name())){
                edges.add(_edges[i]);
            }
        }
    }
    return edges;
}


/**************************************************************
 * EdgeContainer Map::_get_trip_edges() const
 * ____________________________________________________________
 * This method adds the edges of the trip into EdgeContainer
 * ___________________________________________________________
 * Pre-Condition
 * Verifies if _trip size == 0 return EdgeContainer
 *
 * Post-Condition
 * retrun EdgeContainer of trip edges
 *************************************************************/
vector<Plottable> Map::get_trip_plottables() const
{

    //PROC - get coordinates of edges and insert into
    //       vector<Plottable>
    vector<Plottable> plottables;
    Point p1, p2;
    EdgeContainer edges = _get_trip_edges();
    for (size_t i=0; i<edges.size(); i++){
        p1 = _points.get_coordinates(edges[i].get_left_node());
        p2 = _points.get_coordinates(edges[i].get_right_node());
        plottables.insert(plottables.end(), Plottable(p1, p2));
    }
    return plottables;
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
        }
    }

    for (size_t i=0; i<_points.size(); i++){
        if (_points[i].get_name() == stadium_name){
            _points[i].set_name(s.get_stadium_name());
        }
    }

    for (size_t i=0; i<_edges.size(); i++){
        if (_edges[i].get_left_node() == stadium_name){
            _edges[i].set_left_node(s.get_stadium_name());
        }
        else if (_edges[i].get_right_node() == stadium_name){
            _edges[i].set_right_node(s.get_stadium_name());
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


/**************************************************************
 * StadiumContainer Map::get_trip_greedy(StadiumContainer selection, Stadium start)
 * ____________________________________________________________
 * This method get trip using greedy algorithm
 * ___________________________________________________________
 * Pre-Condition
 * StadiumContainer of selected stadiums, and start stadium
 *
 * Post-Condition
 * return trip in StadiumContainer
 *************************************************************/
StadiumContainer Map::get_trip_greedy (StadiumContainer selection,  //IN - selected stadiums
                                       Stadium start)               //IN - start stadium
{
    //PROC - add start stadium into container if is not found
    if (!selection.contains(start.get_stadium_name())){
        selection.add(start);
    }
    //call make shorthest path of the selected stadiums
    Container<Dijkstra> dijkstras = _make_shortest_paths(selection);
    StadiumContainer greedy_perm, trip;
    //use get greedy permutation and reconstruct the trip
    greedy_perm = _get_greedy_permutation(selection, start, dijkstras);
    trip = _reconstruct_trip(selection, greedy_perm, dijkstras);
    //return trip
    return trip;
}

/**************************************************************
 * StadiumContainer Map::_reconstruct_trip(StadiumContainer selection, StadiumContainer perm,
 *                                      Container<Dijkstra> dijkstras)
 * ____________________________________________________________
 * This method reconstruct the trip
 * ___________________________________________________________
 * Pre-Condition
 * StadiumContainer of selected stadiumm, perm and Dijkstra container
 *
 * Post-Condition
 * return trip in StadiumContainer
 *************************************************************/
StadiumContainer Map::_reconstruct_trip(StadiumContainer selection,    //IN - selected stadiums
                                        StadiumContainer perm,         //IN - greedy_perm
                                        Container<Dijkstra> dijkstras) //IN - dijkstras container
{
    StadiumContainer trip;
    Container<int> reconstructed;
    Container<int> indices = _index(selection);
    int current_index, next_index;
    Dijkstra current_dijkstra;
    trip.add(perm[0]);

    for (size_t i=0; i < perm.size()-1; i++){
        current_index = selection.find(perm[i].get_stadium_name());
        next_index = selection.find(perm[i+1].get_stadium_name());
        current_dijkstra = dijkstras[current_index];
        reconstructed = current_dijkstra.reconstruct(indices[next_index]);

        reconstructed.remove(0);
        trip += _map_indices_to_stadiums(reconstructed);
    }
    return trip;
}

/**************************************************************
 * StadiumContainer Map::_map_indices_to_stadiums(Container<int> indices)
 * ____________________________________________________________
 * This method get the stadiums with the indices container and add into
 * StadiumContainer
 * ___________________________________________________________
 * Pre-Condition
 * Container of int indices given
 *
 * Post-Condition
 * return stadiums in StadiumContainer
 *************************************************************/
StadiumContainer Map::_map_indices_to_stadiums(Container<int> indices) //IN - int container
{
    StadiumContainer stadiums;
    for (size_t i=0; i<indices.size(); i++){
        stadiums.add(_stadiums[indices[i]]);
    }
    return stadiums;
}

/**************************************************************
 * StadiumContainer Map::_get_greedy_permutation(StadiumContainer selection,
 *                            Stadium start, Container<Dijkstra> dijkstras)
 * ____________________________________________________________
 * This method will perform the greedy algorithm and insert the dijkstras
 * of the selected stadiums into greedy perm container
 * ___________________________________________________________
 * Pre-Condition
 * Selected stadiums, start stadium, and dijkstras container are given
 *
 * Post-Condition
 * return greedy perm in StadiumContainer
 *************************************************************/
StadiumContainer Map::_get_greedy_permutation(StadiumContainer selection,    //IN - selected stadiums
                                              Stadium start,                 //IN - start stadium
                                              Container<Dijkstra> dijkstras) //IN - dijkstras container
{
    StadiumContainer greedy_perm;
    Container<int> indices = _index(selection);
    Stadium current_stadium = start;
    Dijkstra current_dijkstra;
    int min, min_index;
    for (size_t i=0; i<selection.size(); i++){
        min = INT_MAX;
        current_dijkstra = dijkstras[selection.find(current_stadium.get_stadium_name())];
        for (size_t i=0; i<selection.size(); i++){
            if (greedy_perm.contains(selection[i].get_stadium_name())) continue;
            int cost = current_dijkstra.get_cost(indices[i]);
            if (cost < min){
                min = cost;
                min_index = i;
            }
        }
        current_stadium = _stadiums[indices[min_index]];
        greedy_perm.add(current_stadium);
    }
    return greedy_perm;
}


/**************************************************************
 * Container<int> Map::_index(StadiumContainer selection)
 * ____________________________________________________________
 * This method will get the index of each stadium in the stadium container
 * and add into a container of int
 * ___________________________________________________________
 * Pre-Condition
 * Selected stadiums is given
 *
 * Post-Condition
 * return container of int
 *************************************************************/
Container<int> Map::_index(StadiumContainer selection)   //IN - selected stadiums
{
    Container<int> indices;
    for (size_t i=0; i<selection.size(); i++){
        indices.add(_stadiums.find(selection[i].get_stadium_name()));
    }
    return indices;
}


/**************************************************************
 * int Map::_compute_cost(vector<Stadium> stadiums,Container<Dijkstra> dijkstras)
 * ____________________________________________________________
 * This method will compute the total cost between the stadiums
 * ___________________________________________________________
 * Pre-Condition
 * vector of stadiums and dijkstras container are given
 *
 * Post-Condition
 * return total cost between stadiums
 *************************************************************/
int Map::_compute_cost(vector<Stadium> stadiums,
                       Container<Dijkstra> dijkstras)    //IN - dijkstras container
{
    int cost = 0;
    for (size_t i=0; i<stadiums.size()-1; i++){
        int s1, s2;
        s1 = _stadiums.find(stadiums[i].get_stadium_name());
        s2 = _stadiums.find(stadiums[i+1].get_stadium_name());
        cost += dijkstras[s1].get_cost(s2);
    }
    return cost;
}

/**************************************************************
 * Container<Dijkstra> Map::_make_shortest_paths(StadiumContainer selection)
 * ____________________________________________________________
 * This method will find the shortest path between selected stadiums
 * ___________________________________________________________
 * Pre-Condition
 * selected stadiums are given
 *
 * Post-Condition
 * return Dijkstra container with the shortest path between stadiums
 *************************************************************/
Container<Dijkstra> Map::_make_shortest_paths(StadiumContainer selection)  //IN - selected stadiums
{
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

/**************************************************************
 * int** Map::_make_adjacency_matrix()
 * ____________________________________________________________
 * This method will create the adjacency matrix of the stadiums
 * ___________________________________________________________
 * Pre-Condition
 * none
 *
 * Post-Condition
 * return pointer to adjacency matrix
 *************************************************************/
int** Map::_make_adjacency_matrix()
{
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


/**************************************************************
 * int Map::get_cost() const
 * ____________________________________________________________
 * This method will calculate the total cost of the trip
 * ___________________________________________________________
 * Pre-Condition
 * none
 *
 * Post-Condition
 * return int total cost
 *************************************************************/
int Map::get_cost() const{
    int cost=0;
    for (int i=0; i<int(_trip.size())-1; i++){
        cost += _edges.get_cost(_trip[i].get_stadium_name(),
                                _trip[i+1].get_stadium_name());
    }
    return cost;
}


/**************************************************************
 * void Map::add_point(Point p)
 * ____________________________________________________________
 * add a point to _points
 * ___________________________________________________________
 * Pre-Condition
 * none
 *
 * Post-Condition
 * p is added to _points
 *************************************************************/
void Map::add_point(Point p){
    _points.add(p);
}


/**************************************************************
 * void Map::add_edge(Edge e)
 * ____________________________________________________________
 * add an edge to _edges
 * ___________________________________________________________
 * Pre-Condition
 * none
 *
 * Post-Condition
 * e is added to _edges
 *************************************************************/
void Map::add_edge(Edge e){
    _edges.add(e);
}


/**************************************************************
 * bool Map::has_dangling_stadium() const
 * ____________________________________________________________
 * checks if there is an isolated stadium
 * ___________________________________________________________
 * Pre-Condition
 * none
 *
 * Post-Condition
 * true is returned if one or more stadium is isolated
 * false is returned otherwise
 *************************************************************/
bool Map::has_dangling_stadium() const{
    for (size_t i=0; i<_stadiums.size(); i++){
        if (!_edges.contains(_stadiums[i].get_stadium_name())){
            return true;
        }
    }
    return false;
}


/**************************************************************
 * void Map::load_american_stadiums(string file_name)
 * ____________________________________________________________
 * loads american stadiums
 * ___________________________________________________________
 * Pre-Condition
 * none
 *
 * Post-Condition
 * american stadiums from file_name are loaded to _stadiums
 *************************************************************/
void Map::load_american_stadiums(string file_name){
    for (size_t i=0; i<_stadiums.size(); i++){
        if (_stadiums[i].get_league() == AMERICAN_LEAGUE_NAME){
            _stadiums.remove(i);
            i--;
        }
    }
    StadiumContainer american_stadiums;
    load_stadiums(file_name, AMERICAN_LEAGUE_NAME, american_stadiums);
    _stadiums += american_stadiums;
}


/**************************************************************
 * void Map::load_national_stadiums(string file_name)
 * ____________________________________________________________
 * loads national stadiums
 * ___________________________________________________________
 * Pre-Condition
 * none
 *
 * Post-Condition
 * national stadiums from file_name are loaded to _stadiums
 *************************************************************/
void Map::load_national_stadiums(string file_name){
    for (size_t i=0; i<_stadiums.size(); i++){
        if (_stadiums[i].get_league() == NATIONAL_LEAGUE_NAME){
            _stadiums.remove(i);
            i--;
        }
    }
    StadiumContainer national_stadiums;
    load_stadiums(file_name, NATIONAL_LEAGUE_NAME, national_stadiums);
    _stadiums += national_stadiums;
}

/**************************************************************
 * void Map::load_edges(string file_name)
 * ____________________________________________________________
 * loads edges
 * ___________________________________________________________
 * Pre-Condition
 * none
 *
 * Post-Condition
 * edges from file_name are loaded to _edges
 *************************************************************/
void Map::load_edges(string file_name){
    _edges = _load_edges(file_name);
}


/**************************************************************
 * void Map::load_points(string file_name)
 * ____________________________________________________________
 * loads points
 * ___________________________________________________________
 * Pre-Condition
 * none
 *
 * Post-Condition
 * points from file_name are loaded to _points
 *************************************************************/
void Map::load_points(string file_name){
    _points = _load_points(file_name);
}

