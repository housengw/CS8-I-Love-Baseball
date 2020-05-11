#ifndef POINT_CONTAINER_H
#define POINT_CONTAINER_H
#include "point.h"
#include "container.h"

using namespace std;

class PointContainer: public Container<Point>
{
public:
    /****************************************
    **  CONSTRUCTORS  **
    *****************************************/
    PointContainer();
    int find(string point_name) const;
    void print();
};

#endif // POINT_CONTAINER_H
