#include "dijkstra.h"

Dijkstra::Dijkstra(){
    c = nullptr;
    p = nullptr;
    _adjacency_matrix = nullptr;
}


Dijkstra::Dijkstra(int from_node, int** adjacency_matrix, size_t size){
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
    _run();
}


Dijkstra& Dijkstra::operator=(const Dijkstra& rhs){
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


Dijkstra::Dijkstra(const Dijkstra& copy_this){
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


Dijkstra::~Dijkstra(){
    if (c != nullptr) delete[] c;
    if (p != nullptr) delete[] p;
    if (_adjacency_matrix != nullptr){
        for (size_t i=0; i<_size; i++){
            delete[] _adjacency_matrix[i];
        }
        delete[] _adjacency_matrix;
    }
}

void Dijkstra::_run(){
    Container<int> s;
    int node;
    c[_from_node] = 0;

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

void Dijkstra::_initialize_arrays(size_t size){
    p = new int[size];
    c = new int[size];

    for (size_t i=0; i<size; i++){
        p[i] = -1;
        c[i] = -1;
    }
}

int Dijkstra::get_cost(int to_node){
    assert(to_node >= 0 && to_node < _size);
    return c[to_node];
}

bool Dijkstra::_connected(int from_city, //the city to be checked
                          int to_city){  //the city to be checked
    return _adjacency_matrix[from_city][to_city] >= 0;
}
