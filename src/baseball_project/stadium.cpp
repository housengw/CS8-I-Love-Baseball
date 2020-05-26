#include "stadium.h"

Stadium::Stadium()
    : _stadium_name(""), _team_name(""), _address1(""), _address2(""),
      _phone_number(""), _date_opened(Date()), _capacity(0),
      _surface(GRASS_SURFACE_NAME)
{
    // intentionally left empty
}

Stadium::Stadium(string stadium,
                 string team,
                 string adress1,
                 string adress2,
                 string phone,
                 Date date,
                 int capacity,
                 string surface)
{
    set_stadium_name(stadium);
    set_team_name(team);
    set_address1(adress1);
    set_address2(adress2);
    set_phone_number(phone);
    set_date_opened(date);
    set_capacity(capacity);
    set_surface(surface);
}

souvenir &Stadium::get_souvenir(string souvenir_name)
{
    return souvenirs.get(souvenir_name);
}

const souvenir &Stadium::get_souvenir(string souvenir_name) const
{
    return souvenirs.get(souvenir_name);
}

void Stadium::set_stadium_name(const string &stadium_name)
{
    _stadium_name = stadium_name;
}

void Stadium::set_team_name(const string &team_name)
{
    _team_name = team_name;
}

void Stadium::set_address1(const string &address)
{
    _address1 = address;
}

void Stadium::set_address2(const string &address)
{
    _address2 = address;
}

void Stadium::set_phone_number(const string &phone_number)
{
    _phone_number = phone_number;
}

void Stadium::set_league(const string &league)
{
    _league = league;
}

void Stadium::set_date_opened(const Date &date_opened)
{
    _date_opened = date_opened;
}

void Stadium::set_capacity(const int &capacity)
{
    _capacity = capacity;
}

void Stadium::set_surface(const string &surface)
{
    _surface = surface;
}

bool Stadium::operator<(const Stadium &s)
{
    return (_team_name < s.get_team_name());
}

bool Stadium::operator>(const Stadium &s)
{
    return (_stadium_name < s.get_stadium_name());
}

void Stadium::print_info()
{
    cout << "Stadium : '" << get_stadium_name() << "'" << endl;
    cout << "Team Name: '" << get_team_name() << "'" << endl;
    cout << "Address: '" << get_address1() << "'" << endl
         << get_address2() << "'" << endl;
    cout << "Opened Date: '" << _date_opened.get_date() << "'" << endl;
    cout << "Phone: '" << get_phone_number() << "'" << endl;

    cout << "Capacity: '" << get_capacity() << "'" << endl;
    cout << "Surface: '" << get_surface() << "'" << endl;
}

void Stadium::print_souvenir_list() const
{
    souvenirs.print();
}

bool Stadium::add_souvenir(string name, double price)
{
    return souvenirs.add(souvenir(name, price));
}

bool Stadium::modify_souvenir_name(string name, string newName)
{
    if (!souvenirs.contains(name))
    {
        return false;
    }
    get_souvenir(name)._name = newName;
    return true;
}

bool Stadium::modify_souvenir_price(string name, double newPrice)
{
    if (!souvenirs.contains(name))
    {
        return false;
    }
    get_souvenir(name)._price = newPrice;
    return true;
}
