#include "edge.h"


/**************************************************************
 * Edge::Edge ();
 * ____________________________________________________________
 * This method intializes the members with default values
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * initialize private members to default values
 *************************************************************/
Edge::Edge():
    _stadium_a(), _stadium_b(), _cost(-1)
{
    //intentionally left empty
}


/**************************************************************
 * Edge::Edge(string stadium_a, string stadium_b, int cost)
 * ____________________________________________________________
 * This method intializes the members with paremeters values
 * ___________________________________________________________
 * Pre-Condition
 * string stadiums a and b are given
 *
 * Post-Condition
 * initialize private members to parameters values
 *************************************************************/
Edge::Edge(string stadium_a, string stadium_b, int cost):
    _stadium_a(stadium_a), _stadium_b(stadium_b), _cost(cost)
{
    //intentionally left empty
}


/**************************************************************
 * bool Edge::match(string stadium_a, string stadium_b) const
 * ____________________________________________________________
 * This method verifies if stadium a and b are a match
 * ___________________________________________________________
 * Pre-Condition
 * stadiums a and b are given
 *
 * Post-Condition
 * returns true a and b are a match
 *************************************************************/
bool Edge::match(string stadium_a, string stadium_b) const{
    return ((stadium_a == _stadium_a && stadium_b == _stadium_b) ||
            (stadium_a == _stadium_b && stadium_b == _stadium_a));
}


/**************************************************************
 * void Edge::print_info ()
 * ____________________________________________________________
 * This function display the information of the edge
 * ___________________________________________________________
 * Pre-Condition
 * All private members are initialized
 *
 * Post-Condition
 * display the information of the edge
 *************************************************************/
void Edge::print_info(){
    cout<<_stadium_a
        <<" <--> "
        <<_stadium_b;
}
