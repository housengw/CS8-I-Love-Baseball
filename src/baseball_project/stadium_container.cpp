#include "stadium_container.h"

/**************************************************************
 * StadiumContainer::StadiumContainer ();
 * ____________________________________________________________
 * This method intializes the members with default values
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * initialize private members to default values
 *************************************************************/
StadiumContainer::StadiumContainer()
{
    //intentionally left empty
}


/**************************************************************
 * StadiumContainer StadiumContainer::get_stadiums_grass_surface()
 * ____________________________________________________________
 * This method return stadiums with grass surface
 * ___________________________________________________________
 * Pre-Condition
 * none
 *
 * Post-Condition
 * return stadiums with grass surface
 *************************************************************/
StadiumContainer StadiumContainer::get_stadiums_grass_surface()
{
    StadiumContainer temp;
    string surface;
    for(size_t i = 0; i < _size; i++){
        surface = _list[i].get_surface() ;
        if (surface == GRASS_SURFACE_NAME){
            temp.add(_list[i]);
        }
    }
    return temp;
}

/**************************************************************
 * StadiumContainer StadiumContainer::get_stadiums_turf_surface()
 * ____________________________________________________________
 * This method return stadiums with turf surface
 * ___________________________________________________________
 * Pre-Condition
 * none
 *
 * Post-Condition
 * return stadiums with turf surface
 *************************************************************/
StadiumContainer StadiumContainer::get_stadiums_turf_surface()
{
    StadiumContainer temp;
    string surface;
    for(size_t i = 0; i < _size; i++){
        surface = _list[i].get_surface() ;
        if (surface == TURF_SURFACE_NAME){
            temp.add(_list[i]);
        }
    }
    return temp;
}

/**************************************************************
 * StadiumContainer StadiumContainer::get_american_stadiums()
 * ____________________________________________________________
 * This method return american stadiums
 * ___________________________________________________________
 * Pre-Condition
 * none
 *
 * Post-Condition
 * return american stadiums
 *************************************************************/
StadiumContainer StadiumContainer::get_american_stadiums()
{
    StadiumContainer temp;
    string surface;
    for(size_t i = 0; i < _size; i++){
        surface = _list[i].get_league() ;
        if (surface == AMERICAN_LEAGUE_NAME){
            temp.add(_list[i]);
        }
    }
    return temp;
}

/**************************************************************
 * StadiumContainer StadiumContainer::get_national_stadiums()
 * ____________________________________________________________
 * This method return national stadiums
 * ___________________________________________________________
 * Pre-Condition
 * none
 *
 * Post-Condition
 * return national stadiums
 *************************************************************/
StadiumContainer StadiumContainer::get_national_stadiums()
{
    StadiumContainer temp;
    string surface;
    for(size_t i = 0; i < _size; i++){
        surface = _list[i].get_league() ;
        if (surface == NATIONAL_LEAGUE_NAME){
            temp.add(_list[i]);
        }
    }
    return temp;
}

/**************************************************************
 * int StadiumContainer::find(string stadium_name) const
 * ____________________________________________________________
 * This method find stadium in container
 * ___________________________________________________________
 * Pre-Condition
 * stadium name given
 *
 * Post-Condition
 * return int < 0 if not found else int > 0
 *************************************************************/
int StadiumContainer::find(string stadium_name) const   //IN - stadium name
{
    int index = -1;
    for (size_t i=0; i<size(); i++){
        if (_list[i].get_stadium_name() == stadium_name){
            index = i;
        }
    }
    return index;
}

/**************************************************************
 * bool StadiumContainer::contains(string stadium_name) const
 * ____________________________________________________________
 * This method find stadium in container
 * ___________________________________________________________
 * Pre-Condition
 * stadium name given
 *
 * Post-Condition
 * return false if not found else true
 *************************************************************/
bool StadiumContainer::contains(string stadium_name) const  //IN - stadium name
{
    return (find(stadium_name) >= 0);
}


/**************************************************************
 * const Stadium& StadiumContainer::get_stadium(string stadium_name) const{
 * ____________________________________________________________
 * This method return stadium
 * ___________________________________________________________
 * Pre-Condition
 * stadium name given
 *
 * Post-Condition
 * return stadium
 *************************************************************/
const Stadium& StadiumContainer::get_stadium(string stadium_name) const //IN - stadium name
{
    assert(contains(stadium_name));
    return _list[find(stadium_name)];
}

/**************************************************************
 * Stadium& StadiumContainer::get_stadium(string stadium_name) {
 * ____________________________________________________________
 * This method return stadium
 * ___________________________________________________________
 * Pre-Condition
 * stadium name given
 *
 * Post-Condition
 * return stadium
 *************************************************************/
Stadium& StadiumContainer::get_stadium(string stadium_name)  //IN - stadium name
{
    assert(contains(stadium_name));
    return _list[find(stadium_name)];
}

/**************************************************************
 * void StadiumContainer::print () const
 * ____________________________________________________________
 * This method display the list of stadiums
 * ___________________________________________________________
 * Pre-Condition
 * All private members are initialized
 *
 * Post-Condition
 * display the list of stadiums
 *************************************************************/
void StadiumContainer::print() const{
    for (size_t i=0; i<size(); i++){
        _list[i].print_info();
        cout<<endl;
    }
    cout<<endl;
}
