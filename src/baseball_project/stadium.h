#ifndef STADIUM_H
#define STADIUM_H
#include "date.h"
#include <string>

#include "souvenirs_container.h"

using namespace std;

class Stadium
{
  public:
    Stadium();
    Stadium(string stadium, string team, string adress1, string adress2,
            string phone, Date date, int capacity, string surface);
    const string &get_stadium_name() const { return _stadium_name; }
    const string &get_team_name() const { return _team_name; }
    //    const string& get_address() const{return _address;}
    const string &get_address1() const { return _address1; }
    const string &get_address2() const { return _address2; }
    const string &get_surface() const { return _surface; }
    const string &get_phone_number() const { return _phone_number; }
    const string &get_league() const { return _league; }
    const Date &get_date_opened() const { return _date_opened; }
    const int &get_capacity() const { return _capacity; }
    const souvenir &get_souvenir(string souvenir_name) const;
    souvenir &get_souvenir(string souvenir_name);

    void set_stadium_name(const string &stadium_name);
    void set_team_name(const string &team_name);
    //    void set_address(const string& address);

    void set_address1(const string &address);
    void set_address2(const string &address);
    void set_phone_number(const string &phone_number);
    void set_league(const string &league);
    void set_date_opened(const Date &date_opened);
    void set_capacity(const int &capacity);
    void set_surface(const string &capacity);
    void print_info();
    void print_souvenir_list() const;

    // Modify souvenir list (return ture when modified
    // false when item not in the list)
    bool add_souvenir(string name, double price);
    bool modify_souvenir_name(string name, string newName);
    bool modify_souvenir_price(string name, double newPrice);

    // compare team name
    bool operator<(const Stadium &s);
    // compare stadium name
    bool operator>(const Stadium &s);

  private:
    string _stadium_name;
    string _team_name;
    string _address1;
    string _address2;

    string _phone_number;
    string _league;
    Date _date_opened;
    int _capacity;
    string _surface;

    SouvenirsContainer souvenirs;
};

#endif // STADIUM_H
