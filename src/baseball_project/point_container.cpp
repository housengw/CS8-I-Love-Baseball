#include "point_container.h"

/**************************************************************
 * PointContainer::PointContainer ();
 * ____________________________________________________________
 * This method intializes the members with default values
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * initialize private members to default values
 *************************************************************/
PointContainer::PointContainer()
{
    //intentionally left empty
}

/**************************************************************
 * int PointContainer::find (string point_name) const
 * ____________________________________________________________
 * This method found point is in container
 * ___________________________________________________________
 * Pre-Condition
 * string point name is given
 *
 * Post-Condition
 * return int > 0 if point found else int < 0
 *************************************************************/
int PointContainer::find (string point_name) const   //IN - string point name
{
    int index = -1;
    for (size_t i=0; i<size(); i++){
        if (_list[i].get_name() == point_name){
            index = i;
        }
    }
    return index;
}

/**************************************************************
 * bool PointContainer::contains(string point_name) const
 * ____________________________________________________________
 * This method find if point is in container
 * ___________________________________________________________
 * Pre-Condition
 * string point name is given
 *
 * Post-Condition
 * return true if found else false
 *************************************************************/
bool PointContainer::contains(string point_name) const  //IN - string point name
{
    return (find(point_name) >= 0);
}

/**************************************************************
 * Point PointContainer::get_coordinates(string point_name) const
 * ____________________________________________________________
 * This method returns the coordinates of point
 * ___________________________________________________________
 * Pre-Condition
 * string point name is given
 *
 * Post-Condition
 * return
 *************************************************************/
Point PointContainer::get_coordinates(string point_name) const
{
    assert(contains(point_name));
    for (size_t i=0; i<size(); i++){
        if (_list[i].get_name() == point_name){
            return _list[i];
        }
    }
    return Point();
}


/**************************************************************
 * void PointContainer::print() const
 * ____________________________________________________________
 * This method display the list of points
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * None
 *************************************************************/
void PointContainer::print() const
{
    for (size_t i=0; i<size(); i++){
        cout<<"("<<_list[i].get_x()<<", "
            <<_list[i].get_y()<<") "
            <<_list[i].get_name();
        cout<<endl;
    }
    cout<<endl;
}

