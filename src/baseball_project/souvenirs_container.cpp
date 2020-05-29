#include "souvenirs_container.h"

/**************************************************************
 * SouvenirsContainer::SouvenirsContainer();
 * ____________________________________________________________
 * This method intializes the members with default values
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * initialize private members to default values
 *************************************************************/
SouvenirsContainer::SouvenirsContainer()
{
    add(souvenir("Baseball cap", 25.99));
    add(souvenir("Baseball bat", 35.35));
    add(souvenir("Team pennant", 12.99));
    add(souvenir("Autographed baseball", 19.99));
}

/**************************************************************
 * int SouvenirsContainer::find(string souvenir_name) const
 * ____________________________________________________________
 * This method find the souvenir in container
 * ___________________________________________________________
 * Pre-Condition
 * string souvenir name is given
 *
 * Post-Condition
 * return int > 0 if souvenir found else int < 0
 *************************************************************/
int SouvenirsContainer::find(string souvenir_name) const  //IN - souvenir name
{
    int index = -1;
    for (size_t i=0; i<size(); i++){
        if (_list[i]._name == souvenir_name){
            index = i;
        }
    }
    return index;
}


/**************************************************************
 * bool SouvenirsContainer::add(const souvenir& item)
 * ____________________________________________________________
 * This method add item into container
 * ___________________________________________________________
 * Pre-Condition
 * souvenir item is given
 *
 * Post-Condition
 * return true if added else false
 *************************************************************/
bool SouvenirsContainer::add(const souvenir& item)  //IN - souvenir item
{

    if(contains(item._name))
    {
        return false;
    }

    if (size() == _allocated){
        reserve(size()*2);
    }
    _list[_size++] = item;
    return true;
}

/**************************************************************
 * souvenir& SouvenirsContainer::get(string souvenir_name)
 * ____________________________________________________________
 * This method return item
 * ___________________________________________________________
 * Pre-Condition
 * souvenir item name is given
 *
 * Post-Condition
 * return souvenir item
 *************************************************************/
souvenir& SouvenirsContainer::get(string souvenir_name)  //IN - souvenir name
{
    assert(contains(souvenir_name));

    return _list[find(souvenir_name)];
}

/**************************************************************
 * const souvenir& SouvenirsContainer::get (string souvenir_name) const
 * ____________________________________________________________
 * This method return item
 * ___________________________________________________________
 * Pre-Condition
 * souvenir item name is given
 *
 * Post-Condition
 * return souvenir item
 *************************************************************/
const souvenir& SouvenirsContainer::get (string souvenir_name) const
{
    assert(contains(souvenir_name));

    return _list[find(souvenir_name)];
}

/**************************************************************
 * bool SouvenirsContainer::contains(string souvenir_name) const
 * ____________________________________________________________
 * This method checks if souvenir is in container
 * ___________________________________________________________
 * Pre-Condition
 * souvenir name is given
 *
 * Post-Condition
 * return true if is container else false
 *************************************************************/
bool SouvenirsContainer::contains(string souvenir_name) const
{
    return (find(souvenir_name) >= 0);
}

/**************************************************************
 * void SouvenirsContainer::print() const
 * ____________________________________________________________
 * This method display the list of souvenirs
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * None
 *************************************************************/
void SouvenirsContainer::print() const
{
    for (size_t i=0; i<size(); i++){
        cout << _list[i];
    }
    cout<<endl;
}
