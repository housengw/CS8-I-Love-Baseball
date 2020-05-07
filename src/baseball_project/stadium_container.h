#ifndef STADIUMCONTAINER_H
#define STADIUMCONTAINER_H
#include <iostream>
#include "stadium.h"
using namespace std;



class StadiumContainer
{
public:
    /****************************************
    **  TYPEDEFS  **
    *****************************************/
    typedef Stadium value_type;

    /****************************************
    **  CONSTRUCTORS  **
    *****************************************/
    StadiumContainer();

    /****************************************
    **  BIG 3  **
    *****************************************/
    ~StadiumContainer ();                                       //destructor
    StadiumContainer& operator = (const StadiumContainer& RHS); //assginment operator
    StadiumContainer (const StadiumContainer &copyThis);        //copy constructor

    StadiumContainer stadiums_grassSurface( );

    bool add(const Stadium & stadium);
    bool remove(size_t index);
    void reserve(size_t n);
    size_t size() const{return _size;}
    bool empty() const{return _size == 0;}
//    const Stadium& operator[](size_t index) const;
    Stadium& operator[](size_t index) ;

    void print();

private:
    Stadium* _stadium_list;
    size_t _allocated;
    size_t _size;
};

#endif // STADIUMCONTAINER_H
