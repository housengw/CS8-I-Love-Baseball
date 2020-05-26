#ifndef SOUVENIRS_CONTAINER_H
#define SOUVENIRS_CONTAINER_H

#include "container.h"
#include <iostream>
using namespace std;

struct souvenir
{
    string _name;
    double _price;
    souvenir(string name = "", double price = 0)
    {
        _name = name;
        _price = price;
    }

    friend ostream &operator<<(ostream &outs, const souvenir &print_me)
    {
        outs << "{" << print_me._name << ": $" << print_me._price << "}"
             << endl;
        return outs;
    }
};

class SouvenirsContainer : public Container<souvenir>
{
  public:
    SouvenirsContainer();

    const souvenir &get(string souvenir_name) const;
    souvenir &get(string souvenir_name);

    bool add(const souvenir &item) override;

    int find(string souvenir_name) const;

    void print() const;

    bool contains(string souvenir_name) const;
};

#endif // SOUVENIRS_CONTAINER_H
