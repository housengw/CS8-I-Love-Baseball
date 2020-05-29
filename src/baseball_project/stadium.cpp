#include "stadium.h"

/**************************************************************
 * Stadium::Stadium ();
 * ____________________________________________________________
 * This method intializes the members with default values
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * initialize private members to default values
 *************************************************************/
Stadium::Stadium():
    _stadium_name(""),
    _team_name(""),
    _address1(""),
    _address2(""),
    _phone_number(""),
    _date_opened(Date()),
    _capacity(0),
    _surface (GRASS_SURFACE_NAME)
{
    //intentionally left empty
}

/**************************************************************
 * Stadium::Stadium(string stadium,string team,string adress1,
 *   string adress2, string phone, Date date, int capacity,string surface)
 * ____________________________________________________________
 * This method intializes the members with paremeters values
 * ___________________________________________________________
 * Pre-Condition
 * string stadiums a and b are given
 *
 * Post-Condition
 * initialize private members to parameters values
 *************************************************************/
Stadium::Stadium (string stadium,                  //IN stadium name
                  string team,                     //IN team name
                  string adress1, string adress2,  //IN adress1 and 2
                  string phone,                    //IN phone
                  Date date,                       //IN date
                  int capacity,                    //IN capacity
                  string surface)                  //IN surface
{
    set_stadium_name(stadium);
    set_team_name(team);
    set_address1(adress1);
    set_address2(adress2);
    set_phone_number(phone);
    set_date_opened(date);
    set_capacity(capacity);
    set_surface (surface);
}

/**************************************************************
 * void Stadium::set_stadium_name(const string& stadium_name){
 * ____________________________________________________________
 * This method sets stadium name
 * ___________________________________________________________
 * Pre-Condition
 * string stadium_name is given
 *
 * Post-Condition
 * stadium name is set to parameter
 *************************************************************/
void Stadium::set_stadium_name(const string& stadium_name)  //IN - stadium name
{
    _stadium_name = stadium_name;
}


/**************************************************************
 * void Stadium::set_team_name(const string& team_name){
 * ____________________________________________________________
 * This method sets team name
 * ___________________________________________________________
 * Pre-Condition
 * string team_name is given
 *
 * Post-Condition
 * team name is set to parameter
 *************************************************************/
void Stadium::set_team_name(const string& team_name){  //IN - team name
    _team_name = team_name;
}


/**************************************************************
 * void Stadium::set_address1(const string& address){
 * ____________________________________________________________
 * This method sets address name
 * ___________________________________________________________
 * Pre-Condition
 * string address is given
 *
 * Post-Condition
 * address1 is set to parameter
 *************************************************************/
void Stadium::set_address1(const string& address){   //IN - address
    _address1 = address;
}

/**************************************************************
 * void Stadium::set_address2(const string& address){
 * ____________________________________________________________
 * This method sets address name
 * ___________________________________________________________
 * Pre-Condition
 * string address is given
 *
 * Post-Condition
 * address2 is set to parameter
 *************************************************************/
void Stadium::set_address2(const string& address){   //IN - address
    _address2 = address;
}


/**************************************************************
 * void Stadium::set_phone_number(const string& phone_number){
 * ____________________________________________________________
 * This method sets phone number
 * ___________________________________________________________
 * Pre-Condition
 * string phone_number is given
 *
 * Post-Condition
 * phone_number is set to parameter
 *************************************************************/
void Stadium::set_phone_number(const string& phone_number){  //IN - phone
    _phone_number = phone_number;
}


/**************************************************************
 * void Stadium::set_league(const string& league){
 * ____________________________________________________________
 * This method sets league
 * ___________________________________________________________
 * Pre-Condition
 * string league is given
 *
 * Post-Condition
 * league is set to parameter
 *************************************************************/
void Stadium::set_league(const string& league){  //IN - league
    _league = league;
}


/**************************************************************
 * void Stadium::set_date_opened(const Date& date_opened){
 * ____________________________________________________________
 * This method sets date opened
 * ___________________________________________________________
 * Pre-Condition
 * date_opened is given
 *
 * Post-Condition
 * date_opened is set to parameter
 *************************************************************/
void Stadium::set_date_opened(const Date& date_opened){   //IN - date_opened
    _date_opened = date_opened;
}


/**************************************************************
 * void Stadium::set_capacity(const int& capacity)
 * ____________________________________________________________
 * This method sets capacity
 * ___________________________________________________________
 * Pre-Condition
 * capacity is given
 *
 * Post-Condition
 * capacity is set to parameter
 *************************************************************/
void Stadium::set_capacity(const int& capacity){   //IN - capacity
    _capacity = capacity;
}

/**************************************************************
 * void Stadium::set_surface(const string& surface)
 * ____________________________________________________________
 * This method sets surface
 * ___________________________________________________________
 * Pre-Condition
 * surface is given
 *
 * Post-Condition
 * surface is set to parameter
 *************************************************************/
void  Stadium::set_surface(const string& surface)  //IN - surface
{
    _surface = surface;
}

/**************************************************************
 * bool Stadium::operator< (const Stadium& s)
 * ____________________________________________________________
 * This method compare LHS and RHS stadiums by team name
 * ___________________________________________________________
 * Pre-Condition
 * Stadium is given
 *
 * Post-Condition
 * return true if LHS and RHS team name in ascending order
 *************************************************************/
bool Stadium::operator< (const Stadium& s)  //IN - stadium
{
    return ( _team_name  < s.get_team_name());
}

/**************************************************************
 * bool Stadium::operator< (const Stadium& s)
 * ____________________________________________________________
 * This method compare LHS and RHS stadiums by stadium name
 * ___________________________________________________________
 * Pre-Condition
 * Stadium is given
 *
 * Post-Condition
 * return true if LHS and RHS stadium name in ascending order
 *************************************************************/
bool Stadium::operator > (const Stadium& s)    //IN - stadium
{
    return ( _stadium_name  < s.get_stadium_name());
}


/**************************************************************
 * souvenir& Stadium::get_souvenir (string souvenir_name)
 * ____________________________________________________________
 * This method return souvenir
 * ___________________________________________________________
 * Pre-Condition
 * souvenir_name is given
 *
 * Post-Condition
 * return souvenir
 *************************************************************/
souvenir& Stadium::get_souvenir (string souvenir_name)
{
    return souvenirs.get(souvenir_name);
}

/**************************************************************
 * const souvenir& Stadium::get_souvenir (string souvenir_name) const
 * ____________________________________________________________
 * This method return souvenir
 * ___________________________________________________________
 * Pre-Condition
 * souvenir_name is given
 *
 * Post-Condition
 * return souvenir
 *************************************************************/
const souvenir& Stadium::get_souvenir (string souvenir_name) const
{
    return souvenirs.get(souvenir_name);
}

/**************************************************************
 * bool Stadium::add_souvenir(string name, double price)
 * ____________________________________________________________
 * This method add souvenir into container
 * ___________________________________________________________
 * Pre-Condition
 * souvenir_name and price are given
 *
 * Post-Condition
 * return true if added else false
 *************************************************************/
bool Stadium::add_souvenir(string name, double price)
{
    return souvenirs.add(souvenir(name, price));
}

/**************************************************************
 * bool Stadium::modify_souvenir_name(string name, string newName)
 * ____________________________________________________________
 * This method modifies souvenir name
 * ___________________________________________________________
 * Pre-Condition
 * souvenir old and newname are given
 *
 * Post-Condition
 * return true if name modified else false
 *************************************************************/
bool Stadium::modify_souvenir_name(string name, string newName)
{
    if(!souvenirs.contains(name))
    {
        return false;
    }
    get_souvenir(name)._name = newName;
    return true;
}

/**************************************************************
 * bool Stadium::modify_souvenir_price(string name, double newPrice)
 * ____________________________________________________________
 * This method modifies souvenir price
 * ___________________________________________________________
 * Pre-Condition
 * souvenir name and new price are given
 *
 * Post-Condition
 * return true if price modified else false
 *************************************************************/
bool Stadium::modify_souvenir_price(string name, double newPrice)
{
    if(!souvenirs.contains(name))
    {
        return false;
    }
    get_souvenir(name)._price = newPrice;
    return true;
}

/**************************************************************
 * void Stadium::print_info ()
 * ____________________________________________________________
 * This method display of stadium
 * ___________________________________________________________
 * Pre-Condition
 * All private members are initialized
 *
 * Post-Condition
 * display the information of stadium
 *************************************************************/
void Stadium::print_info ()
{
    cout << "Stadium : '" << get_stadium_name() << "'" << endl;
    cout << "Team Name: '" << get_team_name() << "'" << endl;
    cout << "Address: '" << get_address1() << "'" << endl
         << get_address2() << "'" << endl;
    cout << "Opened Date: '" << _date_opened.get_date()<< "'" << endl;
    cout << "Phone: '" << get_phone_number() << "'" << endl;

    cout << "Capacity: '" << get_capacity () << "'" << endl;
    cout << "Surface: '" << get_surface() << "'" << endl;

}

/**************************************************************
 * void Stadium::print_souvenir_list ()
 * ____________________________________________________________
 * This method display the list of souvenir
 * ___________________________________________________________
 * Pre-Condition
 * All private members are initialized
 *
 * Post-Condition
 * display the list of souvenir
 *************************************************************/
void Stadium::print_souvenir_list() const
{
    souvenirs.print();
}

