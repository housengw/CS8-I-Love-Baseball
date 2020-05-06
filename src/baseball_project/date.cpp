#include "date.h"

Date::Date(): _day(1), _month(1), _month_name("January"), _year(2000)
{
    //intentionally left empty
}


Date::Date(int m, int d, int y)
{
    assert(is_valid_date(d, m, y));
    _month = m;
    _day = d;
    _year = y;
}


string Date::get_date() const{
    return to_string(_month) + "/" +
           to_string(_day) + "/" +
           to_string(_year);
}


void Date::set_whole(const string& date){
    // date must haev the format "MM/DD/YYYY"
    assert(is_valid_date(date));
    vector<string> v = split(date, '/');
    _month = stoi(v[0]);
    _day = stoi(v[1]);
    _year = stoi(v[2]);
}


void Date::set_month(int m){
    assert(is_valid_date(_day, m, _year));
    _month = m;
}


void Date::set_day(int d){
    assert(is_valid_date(d, _month, _year));
    _day = d;
}


void Date::set_year(int y){
    assert(is_valid_date(_day, _month, y));
    _year = y;
}


bool Date::is_leap(int y) const{
    return is_leap_year(y);
}
