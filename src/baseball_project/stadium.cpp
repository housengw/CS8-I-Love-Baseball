#include "stadium.h"

Stadium::Stadium():
    _stadium_name(""),
    _team_name(""),
    _address(Address()),
    _phone_number(0),
    _date_opened(Date()),
    _capacity(0)
{
    //intentionally left empty
}


void Stadium::set_stadium_name(const string& stadium_name){
    _stadium_name = stadium_name;
}


void Stadium::set_team_name(const string& team_name){
    _team_name = team_name;
}


void Stadium::set_address(const Address& address){
    _address = address;
}


void Stadium::set_phone_number(const int& phone_number){
    _phone_number = phone_number;
}


void Stadium::set_date_opened(const Date& date_opened){
    _date_opened = date_opened;
}


void Stadium::set_capacity(const int& capacity){
    _capacity = capacity;
}

