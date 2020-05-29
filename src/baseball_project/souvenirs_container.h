#ifndef SOUVENIRS_CONTAINER_H
#define SOUVENIRS_CONTAINER_H

#include <iostream>
#include "container.h"
using namespace std;


/****************************************
**  SOUVERNIR STRUCTURE  **
*****************************************/
struct souvenir
{
    string _name;    //IN/OUT name
    double _price;   //IN/OUT price

    //initialize private members
    souvenir(string name = "", double price = 0)
    {
        _name = name;
        _price = price;
    }

    //display souvenir information
    friend ostream& operator <<(ostream& outs, const souvenir& print_me)
    {
        outs << "{" << print_me._name << ": $"
             << print_me._price << "}" << endl;
        return outs;
    }
};


class SouvenirsContainer: public Container<souvenir>
{
public:
    /****************************************
    **  CONSTRUCTORS  **
    *****************************************/
    SouvenirsContainer();

    /*******************************************
    **  ACCESSORS  **
    *******************************************/
    const souvenir& get(string souvenir_name) const;
    souvenir& get(string souvenir_name);
    int find(string souvenir_name) const;
    bool contains(string souvenir_name) const;
    void print() const;

    /**********************************************
    **  MUTATORS  **
    ***********************************************/
    bool add(const souvenir& item) override;


};

#endif // SOUVENIRS_CONTAINER_H
