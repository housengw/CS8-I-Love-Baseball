#include "stadium.h"

Stadium::Stadium():
    _stadium_name(""),
    _team_name(""),
    _address(""),
    _phone_number(""),
    _date_opened(Date()),
    _capacity(0),
    _surface (GRASS_SURFACE_NAME)
{
    //intentionally left empty
}

Stadium::Stadium (string stadium,
                  string team,
                  string adress,
                  string phone,
                  Date date,
                  int capacity,
                  string surface)
{
    set_stadium_name(stadium);
    set_team_name(team);
    set_address(adress);
    set_phone_number(phone);
    set_date_opened(date);
    set_capacity(capacity);
    set_surface (surface);
}

void Stadium::set_stadium_name(const string& stadium_name){
    _stadium_name = stadium_name;
}


void Stadium::set_team_name(const string& team_name){
    _team_name = team_name;
}


void Stadium::set_address(const string& address){
    _address = address;
}


void Stadium::set_phone_number(const string& phone_number){
    _phone_number = phone_number;
}


void Stadium::set_date_opened(const Date& date_opened){
    _date_opened = date_opened;
}


void Stadium::set_capacity(const int& capacity){
    _capacity = capacity;
}

void  Stadium::set_surface(const string& surface)
{
    _surface = surface;
}

bool Stadium::operator< (const Stadium& s)
{
    return ( _team_name  < s.get_team_name());
}

bool Stadium::operator > (const Stadium& s)
{
    return ( _stadium_name  < s.get_stadium_name());
}

void Stadium::print_info ()
{
    cout << "Stadium : " << get_stadium_name() << endl;
    cout << "Team Name: " << get_team_name() << endl;
    cout << "Address: " <<endl<< get_address() << endl;
    cout << "Opened Date: " << _date_opened.get_month() << "/" << _date_opened.get_day ()
                     << "/" << _date_opened.get_year() << endl;
    cout << "Phone: " << get_phone_number() << endl;

    cout << "Capacity:" << get_capacity () << endl;
    cout << "Surface: " << get_surface() << endl;

}

