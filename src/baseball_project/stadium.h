#ifndef STADIUM_H
#define STADIUM_H
#include <string>
#include "address.h"
#include "date.h"

using namespace std;

class Stadium
{
public:
    Stadium();
    const string& get_stadium_name() const{return _stadium_name;}
    const string& get_team_name() const{return _team_name;}
    const Address& get_address() const{return _address;}
    const int& get_phone_number() const{return _phone_number;}
    const Date& get_date_opened() const{return _date_opened;}
    const int& get_capacity() const{return _capacity;}

    void set_stadium_name(const string& stadium_name);
    void set_team_name(const string& team_name);
    void set_address(const Address& address);
    void set_phone_number(const int& phone_number);
    void set_date_opened(const Date& date_opened);
    void set_capacity(const int& capacity);
private:
    string _stadium_name;
    string _team_name;
    Address _address;
    int _phone_number;
    Date _date_opened;
    int _capacity;
};

#endif // STADIUM_H
