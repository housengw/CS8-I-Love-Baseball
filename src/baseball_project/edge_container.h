#ifndef EDGE_CONTAINER_H
#define EDGE_CONTAINER_H
#include "edge.h"


class EdgeContainer
{
public:
    EdgeContainer();

    ~EdgeContainer ();                                       //destructor
    EdgeContainer& operator = (const EdgeContainer& RHS); //assginment operator
    EdgeContainer (const EdgeContainer &copyThis);

    bool add(const Edge& edge);
    bool remove(size_t index);
    void reserve(size_t n);
    size_t size() const{return _size;}
    bool empty() const{return _size == 0;}
    const Edge& operator[](size_t index) const;
    Edge& operator[](size_t index) ;
    void print();
private:
    Edge* _edge_list;
    size_t _allocated;
    size_t _size;
};

#endif // EDGE_CONTAINER_H
