#ifndef POINT_H
#define POINT_H
#include <string>

using namespace std;

class Point
{
  public:
    Point();
    Point(string name, int x, int y);
    string get_name() const { return _name; }
    int get_x() { return _x; }
    int get_y() { return _y; }

    void set_name(string name);
    void set_x(int x);
    void set_y(int y);

  private:
    string _name;
    int _x;
    int _y;
};

struct Plottable
{
    Plottable(Point p1, Point p2) : p1(p1), p2(p2) {}
    Point p1;
    Point p2;
};

#endif // POINT_H
