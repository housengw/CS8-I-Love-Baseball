#ifndef MAP_H
#define MAP_H
#include "stadium_container.h"
#include "edge_container.h"
#include "point_container.h"
#include "save_load.h"
#include "constants.h"
#include "sort_functions.h"
#include "dijkstra.h"
#include <algorithm>

class Map
{
public:
    /****************************************
    **  CONSTRUCTORS  **
    *****************************************/
    Map();

    /*******************************************
    **  ACCESSORS  **
    *******************************************/
    const StadiumContainer& get_stadiums() const{return _stadiums;}
    StadiumContainer& get_stadiums() {return _stadiums;}
    const EdgeContainer& get_edges() const{return _edges;}
    const PointContainer& get_points() const{return _points;}
    const vector<Plottable>& get_plottables() const{return _plottables;}
    const StadiumContainer& get_trip() const{return _trip;}
    vector<Plottable> get_trip_plottables() const;
    int get_cost() const;

    void update_stadium(string stadium_name, Stadium s);
    StadiumContainer get_trip_permutation(StadiumContainer selection);
    StadiumContainer get_trip_greedy(StadiumContainer selection, Stadium start);

    /*******************************************
    **  MUTATOR  **
    *******************************************/
    void add_stadium(Stadium s);
    void set_trip(StadiumContainer trip){_trip = trip;}

private:
    StadiumContainer _stadiums;            //IN/OUT stadiums container
    EdgeContainer _edges;                  //IN/OUT edges container
    PointContainer _points;                //IN/OUT points container
    vector<Plottable> _plottables;         //IN/OUT vector of plottable
    StadiumContainer _trip;                //IN/OUT selected stadiums container


    /*******************************************
    **  Private Functions  **
    *******************************************/
    void _initialize_stadiums();
    void _initialize_edges();
    void _initialize_points();
    void _initialize_plottables();

    EdgeContainer _get_trip_edges() const;
    Container<int> _index(StadiumContainer selection);
    StadiumContainer _get_greedy_permutation(StadiumContainer selection, Stadium start, Container<Dijkstra> d);
    StadiumContainer _reconstruct_trip(StadiumContainer selection, StadiumContainer perm, Container<Dijkstra> d);
    Container<Dijkstra> _make_shortest_paths(StadiumContainer selection);
    StadiumContainer _map_indices_to_stadiums(Container<int> indices);
    int** _make_adjacency_matrix();
    int _compute_cost(vector<Stadium> stadiums, Container<Dijkstra> dijkstras);
};

#endif // MAP_H

/****************************************
 **  CONSTRUCTORS  **
 *****************************************/
/*****************************************
 *  Map();
 *   Constructor: initialize private members to default values
 *   Parameters: None
 *   Return: None
 *****************************************/


/****************************************
 **  ACCESSORS  **
 *****************************************/
/***********************************************
 *  const StadiumContainer& get_stadiums() const
 *   Accessor: return stadiums container
 *   Parameters: none
 *   Return: const stadiums container by reference
 **********************************************/
/***********************************************
 *  StadiumContainer& get_stadiums()
 *   Accessor: return stadiums container
 *   Parameters: none
 *   Return: stadiums container by reference
 **********************************************/
/***********************************************
 *  const EdgeContainer& get_edges() const
 *   Accessor: returns edges container
 *   Parameters: none
 *   Return: edges container by reference
 **********************************************/
/***********************************************
 *  const PointContainer& get_points() const
 *   Accessor: returns points container
 *   Parameters: none
 *   Return: points container by reference
 **********************************************/
/***********************************************
 *  const vector<Plottable>& get_plottables() const
 *   Accessor: returns vector of Plottable
 *   Parameters: none
 *   Return: vector
 **********************************************/
/***********************************************
 *  StadiumContainer& get_trip()
 *   Accessor: return stadiums in trip
 *   Parameters: none
 *   Return: container of the stadiums by reference
 **********************************************/
/***********************************************
 *  int get_cost() const;
 *   Accessor: return cost of trip
 *   Parameters: none
 *   Return: return int cost
 **********************************************/
/***********************************************
 *  void update_stadium(string stadium_name, Stadium s);
 *   Accessor: update stadium information
 *   Parameters: string stadium name, and Stadium s
 *   Return: None
 **********************************************/
/***********************************************
 * StadiumContainer get_trip_greedy(StadiumContainer selection, Stadium start);
 *   Accessor: get trip using greedy algorithm
 *   Parameters: StadiumContainer of selected stadiums, and start stadium
 *   Return: StadiumContainer of trip after runnign greedy algorithm
 **********************************************/
/***********************************************
 *  StadiumContainer get_trip_permutation(StadiumContainer selection);
 *   Accessor: get trip permutation
 *   Parameters: StadiumContainer of selected stadiums
 *   Return: StadiumContainer of trip after permutation
 **********************************************/

/*******************************************
**  MUTATOR  **
*******************************************/
/***********************************************
 *  void add_stadium(Stadium s);
 *   Mutator: add stadium
 *   Parameters: Stadium s
 *   Return: None
 **********************************************/
/***********************************************
 *  void set_trip (StadiumContainer trip)
 *   Mutator: set trip
 *   Parameters: StadiumContainer trip
 *   Return: None
 **********************************************/


/*******************************************
**  Private Functions  **
*******************************************/
/***********************************************
 * void _initialize_stadiums();
 *   Initialize: stadium container
 *   Parameters: None
 *   Return: None
 **********************************************/
/***********************************************
 * void _initialize_edges();
 *   Initialize: edges container
 *   Parameters: None
 *   Return: None
 **********************************************/
/***********************************************
 * void _initialize_points();
 *   Initialize: points container
 *   Parameters: None
 *   Return: None
 **********************************************/
/***********************************************
 * void _initialize_plottables();
 *   Initialize: plottables container
 *   Parameters: None
 *   Return: None
 **********************************************/
/***********************************************
 * EdgeContainer _get_trip_edges() const;
 *   Get: trip edges
 *   Parameters: None
 *   Return: trip edges in EdgeContainer
 **********************************************/
/***********************************************
 * Container<int> _index (StadiumContainer selection);
 *   Function: get index of stadiums in container and insert into a
 *             container of int
 *   Parameters: Stadium container selection
 *   Return: container of int index
 **********************************************/
/***********************************************
 * StadiumContainer _get_greedy_permutation(StadiumContainer selection,
 * Stadium start, Container<Dijkstra> d);
 *   Function: get index of stadiums in container and insert into a
 *             container of int
 *   Parameters: Stadium container selection
 *   Return: container of int index
 **********************************************/
/***********************************************
 * StadiumContainer _get_greedy_permutation(StadiumContainer selection,
 *                 Stadium start, Container<Dijkstra> d);
 *   Function: get greedy permutation of the selected stadiums
 *   Parameters: Stadium container selection, start stadium, and dijkstras container
 *   Return: stadium container
 **********************************************/
/***********************************************
 * StadiumContainer _reconstruct_trip(StadiumContainer selection,
 *                                    StadiumContainer perm, Container<Dijkstra> d);
 *   Function: reconstruct trip
 *   Parameters: Stadium container selection, perm, and dijkstras container
 *   Return: stadium container
 **********************************************/
/***********************************************
 * Container<Dijkstra> _make_shortest_paths(StadiumContainer selection);
 *   Function: make shortest path for the selected stadiums
 *   Parameters: Stadium container selection
 *   Return: Dijkstra container
 **********************************************/
/***********************************************
 * StadiumContainer _map_indices_to_stadiums(Container<int> indices);
 *   Function: get stadiums with the given indices from stadiums container
 *   Parameters: container of int indices
 *   Return: stadium container of stadiums
 **********************************************/
/***********************************************
 * int** _make_adjacency_matrix();
 *   Function: create an adjacency matrix for stadiums
 *   Parameters: None
 *   Return: the adjacency matrix filled with the cos between stadiums
 **********************************************/
/***********************************************
 * int _compute_cost(vector<Stadium> stadiums, Container<Dijkstra> dijkstras)
 *   Function: compute the total cost for the trip
 *   Parameters: vector of stadiums, and dijkstras container
 *   Return: the total int cost
 **********************************************/
