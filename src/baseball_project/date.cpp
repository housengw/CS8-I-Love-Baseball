#include "date.h"

// Default constructor
Date::Date() : _month(1), _month_name("January"), _day(1), _year(2000)
{
    // intentionally left empty
    // sets date as 1/1/2000 by default
    // January 1, 2000
}

Date::Date(int month, int day, int year)
{
    assert(is_valid_date(day, month, year));
    _month = month;
    _day = day;
    _year = year;
}

string Date::get_date() const
{
    return to_string(_month) + "/" + to_string(_day) + "/" + to_string(_year);
}

bool Date::is_leap(int year) const { return is_leap_year(year); }

void Date::set_date(const string &date)
{
    // Date must have the format "MM/DD/YYYY"
    assert(is_valid_date(date));
    vector<string> v = split(date, '/');
    _month = stoi(v[0]);
    _day = stoi(v[1]);
    _year = stoi(v[2]);
}

void Date::set_month(int month)
{
    assert(is_valid_date(_day, month, _year));
    _month = month;
}

void Date::set_day(int day)
{
    assert(is_valid_date(day, _month, _year));
    _day = day;
}

void Date::set_year(int year)
{
    assert(is_valid_date(_day, _month, year));
    _year = year;
}

// Returns true if d1 is further back in time than d. Returns true if d1 and d
// are the same date. False otherwise.
bool Date::compare_dates(const Date &d1, const Date &d)
{
    if (d1.get_year() < d.get_year())
    {
        return true;
    }
    else if (d1.get_year() == d.get_year())
    {
        if (d1.get_month() == d.get_month() && d1.get_day() < d.get_day())
        {
            return true;
        }
        else if (d1.get_month() < d.get_month())
        {
            return true;
        }
    }
    return false;
}
