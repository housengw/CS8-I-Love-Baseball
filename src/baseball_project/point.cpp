#include "point.h"

Point::Point() {}

Point::Point(string name, int x, int y) : _name(name), _x(x), _y(y)
{
    // intentionally left empty
}

void Point::set_name(string name)
{
    _name = name;
}

void Point::set_x(int x)
{
    _x = x;
}

void Point::set_y(int y)
{
    _y = y;
}
