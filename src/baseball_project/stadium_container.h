#ifndef STADIUMCONTAINER_H
#define STADIUMCONTAINER_H
#include "stadium.h"


class StadiumContainer
{
public:
    StadiumContainer();
    bool add(Stadium stadium);
    bool remove(size_t index);
    void reserve(size_t n);
    size_t size() const{return _size;}
    bool empty() const{return _size == 0;}
    const Stadium& operator[](size_t index) const;
    void print();
private:
    Stadium* _stadium_list;
    size_t _allocated;
    size_t _size;
};

#endif // STADIUMCONTAINER_H
