#ifndef POINT_CONTAINER_H
#define POINT_CONTAINER_H
#include "container.h"
#include "point.h"

using namespace std;

class PointContainer : public Container<Point>
{
  public:
    /********************
     **  CONSTRUCTORS  **
     ********************/
    PointContainer();
    int find(string point_name) const;
    bool contains(string point_name) const;
    Point get_coordinates(string point_name) const;
    void print() const;
};

#endif // POINT_CONTAINER_H
