#include "dijkstra.h"

/**************************************************************
 * Dijkstra::Dijkstra()
 * ____________________________________________________________
 * This method intializes the members with default values
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * initialize private members to default values
 *************************************************************/
Dijkstra::Dijkstra(){
    c = nullptr;
    p = nullptr;
    _adjacency_matrix = nullptr;
    _from_node = 0;
}


/**************************************************************
 * Dijkstra::Dijkstra(int from_node, int** adjacency_matrix, size_t size)
 * ____________________________________________________________
 * This method intializes the members with paremeters values
 * ___________________________________________________________
 * Pre-Condition
 * Start node, adjacency matrix, and size are given
 *
 * Post-Condition
 * initialize private members to parameters values
 *************************************************************/
Dijkstra::Dijkstra(int from_node,            //IN - start node
                   int** adjacency_matrix,   //IN - adjacency matrix
                   size_t size)              //IN - size
{
    //PROC - initialize the arrays and adjacency_matrix
    //       then call run to run Dijkstra
    _initialize_arrays(size);
    _from_node = from_node;
    _size = size;
    _adjacency_matrix = new int*[size];
    for (size_t i=0; i<size; i++){
        _adjacency_matrix[i] = new int[size];
        for (size_t j=0; j<size; j++){
            _adjacency_matrix[i][j] = adjacency_matrix[i][j];
        }
    }
    _run();  //call run
}


/**************************************************************
 * Dijkstra& Dijkstra::operator=(const Dijkstra& rhs)
 * ____________________________________________________________
 * This method sets this Dijkstra to be the same as rhs
 * ___________________________________________________________
 * Pre-Condition
 * Dijkstra rhs is given
 *
 * Post-Condition
 * return reference to this Dijkstra
 *************************************************************/
Dijkstra& Dijkstra::operator=(const Dijkstra& rhs)  //Dijkstra that this
                                                    //LHS will be set equal to
{
    if (this == &rhs) return *this;
    if (p != nullptr) delete[] p;
    if (c != nullptr) delete[] c;
    if (_adjacency_matrix != nullptr){
        for (size_t i=0; i<_size; i++){
            delete[] _adjacency_matrix[i];
        }
        delete[] _adjacency_matrix;
    }

    _from_node = rhs._from_node;
    _size = rhs._size;
    p = new int[_size];
    c = new int[_size];
    _adjacency_matrix = new int*[_size];
    for (size_t i=0; i<rhs._size; i++){
        c[i] = rhs.c[i];
        p[i] = rhs.p[i];
        _adjacency_matrix[i] = new int[_size];
        for (size_t j=0; j<rhs._size; j++){
            _adjacency_matrix[i][j] = rhs._adjacency_matrix[i][j];
        }
    }
    return *this;
}


/**************************************************************
 * Dijkstra::Dijkstra(const Dijkstra& copy_this)
 * ____________________________________________________________
 * This method sets this Dijkstra to a copy of the given Dijkstra
 * ___________________________________________________________
 * Pre-Condition
 * Dijkstra copy_this is given
 *
 * Post-Condition
 * None
 *************************************************************/
Dijkstra::Dijkstra(const Dijkstra& copy_this)//Dijkstra that this
                                             //LHS will be set equal to
{
    _from_node = copy_this._from_node;
    _size = copy_this._size;
    p = new int[_size];
    c = new int[_size];
    _adjacency_matrix = new int*[_size];
    for (size_t i=0; i<copy_this._size; i++){
        c[i] = copy_this.c[i];
        p[i] = copy_this.p[i];
        _adjacency_matrix[i] = new int[_size];
        for (size_t j=0; j<copy_this._size; j++){
            _adjacency_matrix[i][j] = copy_this._adjacency_matrix[i][j];
        }
    }
}


/**************************************************************
 * Dijkstra::~Dijkstra()
 * ____________________________________________________________
 * This method deletes the Dijkstra
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * Deletes all allocated arrays and matrices
 *************************************************************/
Dijkstra::~Dijkstra()
{
    if (c != nullptr) delete[] c;
    if (p != nullptr) delete[] p;
    if (_adjacency_matrix != nullptr){
        for (size_t i=0; i<_size; i++){
            delete[] _adjacency_matrix[i];
        }
        delete[] _adjacency_matrix;
    }
}

/**************************************************************
 * void Dijkstra::_run()
 * ____________________________________________________________
 * This method runs Dijkstra
 * ___________________________________________________________
 * Pre-Condition
 * All arrays are initialized
 *
 * Post-Condition
 * Nodes added to s and c, p arrays refilled
 *************************************************************/
void Dijkstra::_run()
{
    Container<int> s;
    int node;
    c[_from_node] = 0;

    //PROC - iterate while s.size != size
    //       call find_unsigned_min_not_in_s () to get the next node
    //       and add to s, refilled c and p arrays by verifying
    //       connection between nodes
    while (s.size() < _size){
        node = find_unsigned_min_not_in_s(c, _size, s);
        s.add(node);
        for (size_t j=0; j<_size; j++){
            if (contains(s, j) || !_connected(node, j)) continue;
            if (c[j] < 0 ||
                c[node] + _adjacency_matrix[node][j] < c[j]){
                c[j] = c[node] + _adjacency_matrix[node][j];
                p[j] = node;
            }
        }
    }
}

/**************************************************************
 * void Dijkstra::_initialize_arrays(size_t size)
 * ____________________________________________________________
 * This method initialize c and p arrays
 * ___________________________________________________________
 * Pre-Condition
 * Size of array is given
 *
 * Post-Condition
 * p and c arrays created and initialized
 *************************************************************/
void Dijkstra::_initialize_arrays (size_t size) //IN - size of arrays
{
    p = new int[size];
    c = new int[size];

    for (size_t i=0; i<size; i++){
        p[i] = -1;
        c[i] = -1;
    }
}

/**************************************************************
 * int Dijkstra:: get_cost(int to_node)
 * ____________________________________________________________
 * This method returns the cost in c array
 * ___________________________________________________________
 * Pre-Condition
 * To_node int given
 *
 * Post-Condition
 * return cost c[to_node]
 *************************************************************/
int Dijkstra:: get_cost(int to_node)   //IN - node index
{
    assert (to_node >= 0 && to_node < _size);
    return c[to_node];
}

/**************************************************************
 * bool Dijkstra::_connected(int from_city, int to_city)
 * ____________________________________________________________
 * This method verifies if there is connection between the cities
 * ___________________________________________________________
 * Pre-Condition
 * int from_city and to_city are given
 *
 * Post-Condition
 * return true if there is connection else false
 *************************************************************/
bool Dijkstra::_connected(int from_city, //the city to be checked
                          int to_city){  //the city to be checked
    return _adjacency_matrix[from_city][to_city] >= 0;
}


/**************************************************************
 * Container<int> Dijkstra::reconstruct(int to_node)
 * ____________________________________________________________
 * This method reconstruct and return Container
 * ___________________________________________________________
 * Pre-Condition
 * int to_city is given and if there is no parent call recursively the function
 *
 * Post-Condition
 * return reconstructed Container
 *************************************************************/
Container<int> Dijkstra::reconstruct(int to_node) //IN - start node
{
    //PROC - is p[to_node] < 0 return container
    //       else call the function recursively
    if (p[to_node] < 0){
        Container<int> c;
        c.add(_from_node);
        return c;
    }
    else{
        return reconstruct(p[to_node]) + to_node;
    }
}
