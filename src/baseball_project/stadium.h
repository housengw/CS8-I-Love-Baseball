#ifndef STADIUM_H
#define STADIUM_H
#include <string>
#include "date.h"

#include "souvenirs_container.h"

using namespace std;

class Stadium
{
public:
    /****************************************
    **  CONSTRUCTORS  **
    *****************************************/
    Stadium();
    Stadium (string stadium, string team, string adress1, string adress2, string phone,
             Date date, int capacity, string surface);


    /*******************************************
    **  ACCESSORS  **
    *******************************************/
    //Stadium
    const string& get_stadium_name() const{return _stadium_name;}
    const string& get_team_name() const{return _team_name;}
    //    const string& get_address() const{return _address;}
    const string& get_address1() const{return _address1;}
    const string& get_address2() const{return _address2;}
    const string& get_surface() const{return _surface;}
    const string& get_phone_number() const{return _phone_number;}
    const string& get_league() const{return _league;}
    const Date& get_date_opened() const{return _date_opened;}
    const int& get_capacity() const{return _capacity;}

    //Souvenir
    const souvenir& get_souvenir (string souvenir_name) const;
    souvenir& get_souvenir (string souvenir_name);
    const SouvenirsContainer& get_souvenir_list () const{return souvenirs;}
    SouvenirsContainer& get_souvenir_list (){return souvenirs;}

    void print_info ();
    void print_souvenir_list() const;

    /**********************************************
    **  MUTATORS  **
    ***********************************************/
    void set_stadium_name(const string& stadium_name);
    void set_team_name(const string& team_name);
    //    void set_address(const string& address);

    void set_address1(const string& address);
    void set_address2(const string& address);
    void set_phone_number(const string& phone_number);
    void set_league(const string& league);
    void set_date_opened(const Date& date_opened);
    void set_capacity(const int& capacity);
    void set_surface(const string& surface);

    /**********************************************
    **  Souvenir functions  **
    ***********************************************/
    bool add_souvenir(string name, double price);
    bool modify_souvenir_name(string name, string newName);
    bool modify_souvenir_price(string name, double newPrice);

    /**********************************************
    **  Compare functions  **
    ***********************************************/
    bool operator < (const Stadium& s);
    bool operator >  (const Stadium& s);

private:
    string _stadium_name;      //IN/OUT - stadium name
    string _team_name;         //IN/OUT - team name
    string _address1;          //IN/OUT - address
    string _address2;

    string _phone_number;      //IN/OUT - phone number
    string _league;            //IN/OUT - league
    Date _date_opened;         //IN/OUT - date
    int _capacity;             //IN/OUT - capacity
    string _surface;           //IN/OUT - surface

    SouvenirsContainer souvenirs;  //IN/OUT - sourvenir container
};

#endif // STADIUM_H


/****************************************
 **  CONSTRUCTORS  **
 *****************************************/
/*****************************************
 * Stadium();
 *   Constructor: initialize private members to default values
 *   Parameters: None
 *   Return: None
 *****************************************/
/*****************************************
 *  Stadium (string stadium, string team, string adress1, string adress2, string phone,
 *            Date date, int capacity, string surface);
 *   Constructor: initialize private members to the input data
 *   Parameters: strings stadium, team, address, phone, Date date,
 *               int capacity, and string surface
 *   Return: None
 *****************************************/


/****************************************
 **  ACCESSORS  **
 *****************************************/
/***********************************************
 * const string& get_stadium_name()
 *   Accessor: return stadium name
 *   Parameters: None
 *   Return: string stadium name
 **********************************************/
/***********************************************
 * const string& get_team_name() const
 *   Accessor: return team name
 *   Parameters: None
 *   Return: string team name
 **********************************************/
/***********************************************
 * const string& get_address1() const
 *   Accessor: return address name
 *   Parameters: None
 *   Return: string address
 **********************************************/
/***********************************************
 * const string& get_address1() const
 *   Accessor: return address name
 *   Parameters: None
 *   Return: string address
 **********************************************/
/***********************************************
 * const string& get_address2() const
 *   Accessor: return address name
 *   Parameters: None
 *   Return: string address
 **********************************************/
/***********************************************
 * const string& get_surface() const
 *   Accessor: return surface
 *   Parameters: None
 *   Return: string surface
 **********************************************/
/***********************************************
 * const string& get_phone_number() const
 *   Accessor: return phone number
 *   Parameters: None
 *   Return: string phone number
 **********************************************/
/***********************************************
 * const string& get_league() const
 *   Accessor: return league
 *   Parameters: None
 *   Return: string league
 **********************************************/
/***********************************************
 * const Date& get_date_opened() const
 *   Accessor: return date opened
 *   Parameters: None
 *   Return: Date date
 **********************************************/
/***********************************************
 * const int& get_capacity() const
 *   Accessor: return capacity
 *   Parameters: None
 *   Return: int capacity
 **********************************************/
/***********************************************
 * const souvenir& get_souvenir (string souvenir_name) const;
 *   Accessor: return souvenir
 *   Parameters: souvenir name
 *   Return: souvenir
 **********************************************/
/***********************************************
 * souvenir& get_souvenir (string souvenir_name);
 *   Accessor: return souvenir
 *   Parameters: souvenir name
 *   Return: souvenir name
 **********************************************/
/***********************************************
 * const SouvenirsContainer& get_souvenir_list () const
 *   Accessor: return souvenir list
 *   Parameters: None
 *   Return: souvenir list
 **********************************************/
/***********************************************
 * SouvenirsContainer& get_souvenir_list ()
 *   Accessor: return souvenir list
 *   Parameters: None
 *   Return: souvenir list
 **********************************************/
/***********************************************
 *  void print_info ();
 *   Accessor: display stadium information
 *   Parameters: None
 *   Return: None
 **********************************************/
/***********************************************
 * void print_souvenir_list() const;
 *   Accessor: display souvenir_list
 *   Parameters: None
 *   Return: None
 **********************************************/


/*******************************************
**  MUTATOR  **
*******************************************/
/***********************************************
 *  void set_stadium_name(const string& stadium_name);
 *   Mutator: set stadium name
 *   Parameters: string stadium name
 *   Return: None
 **********************************************/
/***********************************************
 *  void set_team_name(const string& team_name);
 *   Mutator: set team name
 *   Parameters: string team name
 *   Return: None
 **********************************************/
/***********************************************
 *  void set_address1(const string& address);
 *   Mutator: set address1
 *   Parameters: string address
 *   Return: None
 **********************************************/
/***********************************************
 *  void set_address2(const string& address);
 *   Mutator: set address2
 *   Parameters: string address
 *   Return: None
 **********************************************/
/***********************************************
 *   void set_phone_number(const string& phone_number);
 *   Mutator: set phone_number
 *   Parameters: string phone_number
 *   Return: None
 **********************************************/
/***********************************************
 *  void set_league(const string& league);
 *   Mutator: set league
 *   Parameters: string league
 *   Return: None
 **********************************************/
/***********************************************
 * void set_date_opened(const Date& date_opened);
 *   Mutator: set date_opened
 *   Parameters: Date date_opened
 *   Return: None
 **********************************************/
/***********************************************
 *  void set_capacity(const int& capacity);
 *   Mutator: set capacity
 *   Parameters: int capacity
 *   Return: None
 **********************************************/
/***********************************************
 *  void set_surface(const string& surface);
 *   Mutator: set capacity
 *   Parameters: string capacity
 *   Return: None
 **********************************************/


/**********************************************
**  Souvenir functions  **
***********************************************/
/***********************************************
 * bool add_souvenir(string name, double price);
 *   Mutator: name and price to souvenir
 *   Parameters: string name and double price
 *   Return: None
 **********************************************/
/***********************************************
 * bool modify_souvenir_name(string name, string newName);
 *   Mutator: modify souvenir name
 *   Parameters: string name and new name
 *   Return: None
 **********************************************/
/***********************************************
 * bool modify_souvenir_price(string name, double newPrice);
 *   Mutator: modify souvenir price
 *   Parameters: string name and new price
 *   Return: None
 **********************************************/

/**********************************************
**  Compare functions  **
***********************************************/
/***********************************************
 * bool operator < (const Stadium& s);
 *   Compare: stadiums by team name
 *   Parameters: Stadium s
 *   Return: true if LHS team name is ascending order
 **********************************************/
/***********************************************
 * bool operator < (const Stadium& s);
 *   Compare: stadiums by stadium name
 *   Parameters: Stadium s
 *   Return: true if LHS stadium name is ascending order
 **********************************************/
