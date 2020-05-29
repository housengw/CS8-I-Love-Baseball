#include "edge_container.h"

/**************************************************************
 * EdgeContainer::EdgeContainer ();
 * ____________________________________________________________
 * This method intializes the members with default values
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * initialize private members to default values
 *************************************************************/
EdgeContainer::EdgeContainer()
{
    //intentionally left empty
}


/**************************************************************
 * int EdgeContainer::find_connection(string stadium_a, string stadium_b) const
 * ____________________________________________________________
 * This method find connection between a and b
 * ___________________________________________________________
 * Pre-Condition
 * stadiums a and b are given
 *
 * Post-Condition
 * return int > 0 if they are connected else int < 0
 *************************************************************/
int EdgeContainer::find_connection(string stadium_a,        //IN - stadiums a and b
                                   string stadium_b) const
{
    int index = -1;
    for (size_t i=0; i<size(); i++){
        if (_list[i].match(stadium_a, stadium_b)){
            index = i;
        }
    }
    return index;
}


/**************************************************************
 * int EdgeContainer::get_cost(string stadium_a, string stadium_b) const
 * ____________________________________________________________
 * This method returns the cost between a and b
 * ___________________________________________________________
 * Pre-Condition
 * stadiums a and b are given
 *
 * Post-Condition
 * returns cost between a and b
 *************************************************************/
int EdgeContainer::get_cost(string stadium_a,        //IN - stadiums a and b
                            string stadium_b) const
{
    assert(connected(stadium_a, stadium_b));
    return _list[find_connection(stadium_a, stadium_b)].get_cost();
}


/**************************************************************
 * bool EdgeContainer::connected(string stadium_a, string stadium_b) const
 * ____________________________________________________________
 * This method verifies if a and b are connected
 * ___________________________________________________________
 * Pre-Condition
 * stadiums a and b are given
 *
 * Post-Condition
 * returns true if a and b are connected
 *************************************************************/
bool EdgeContainer::connected(string stadium_a,         //IN - stadiums a and b
                              string stadium_b) const
{
    return (find_connection(stadium_a, stadium_b) >= 0);
}


/**************************************************************
 * void EdgeContainer::print_info ()
 * ____________________________________________________________
 * This method display the information in edgecontainer
 * ___________________________________________________________
 * Pre-Condition
 * All private members are initialized
 *
 * Post-Condition
 * display the information in edgecontainer
 *************************************************************/
void EdgeContainer::print() const
{
    for (size_t i=0; i<size(); i++){
        _list[i].print_info();
        cout<<endl;
    }
    cout<<endl;
}
