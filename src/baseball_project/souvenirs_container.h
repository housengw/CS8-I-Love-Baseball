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
    int _quantity;   //IN/OUT quantity

    //initialize private members
    souvenir(string name = "", double price = 0, int quantity = 1)
    {
        _name = name;
        _price = price;
        _quantity = quantity;
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

/****************************************
 **  CONSTRUCTORS  **
 *****************************************/
/*****************************************
 *  SouvenirsContainer();
 *   Constructor: initialize private members to default values
 *   Parameters: None
 *   Return: None
 *****************************************/


/****************************************
 **  ACCESSORS  **
 *****************************************/
/***********************************************
 *  const souvenir& get(string souvenir_name) const
 *   Accessor: return souvenir
 *   Parameters: souvenir name
 *   Return: const souvenir
 **********************************************/
/***********************************************
 *  souvenir& get(string souvenir_name);
 *   Accessor: return souvenir
 *   Parameters: souvenir name
 *   Return: souvenir
 **********************************************/
/***********************************************
 *  int find(string souvenir_name) const;
 *   Accessor: find souvenir in container
 *   Parameters: souvenir name
 *   Return: int > 0 if found else int < 0
 **********************************************/
/***********************************************
 *  bool contains(string souvenir_name) const;
 *   Accessor: verify if souvenir is contain in souvenir container
 *   Parameters: string souvenir_name
 *   Return: true if souvenir is contained else false
 **********************************************/
/***********************************************
 *  void print() const;
 *   Accessor: print the information of souvenir
 *   Parameters: None
 *   Return: None
 **********************************************/







