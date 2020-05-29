#include "date.h"

/**************************************************************
 * Date::Date ();
 * ____________________________________________________________
 * This method intializes the members with default values
 * ___________________________________________________________
 * Pre-Condition
 * None
 *
 * Post-Condition
 * initialize private members to default values
 *************************************************************/
Date::Date(): _day(1), _month(1), _month_name("January"), _year(2000)
{
    //intentionally left empty
}


/**************************************************************
 * Date::Date (int m, int d, int y);
 * ____________________________________________________________
 * This method intializes the members with paremeters values
 * ___________________________________________________________
 * Pre-Condition
 * Verifies if is a valid date
 *
 * Post-Condition
 * initialize private members to parameters values
 *************************************************************/
Date::Date(int m, int d, int y)  //IN - int m, d, y
{
    assert(is_valid_date(d, m, y));
    _month = m;
    _day = d;
    _year = y;
}


/**************************************************************
 * string Date::get_date() const
 * ____________________________________________________________
 * This method returns string date
 * ___________________________________________________________
 * Pre-Condition
 * none
 *
 * Post-Condition
 * return date in string
 *************************************************************/
string Date::get_date() const
{
    return to_string(_month) + "/" +
           to_string(_day) + "/" +
           to_string(_year);
}


/**************************************************************
 * void Date::set_whole(const string& date)
 * ____________________________________________________________
 * This method sets date in string
 * ___________________________________________________________
 * Pre-Condition
 * string date is given
 *
 * Post-Condition
 * set date in string
 *************************************************************/
void Date::set_whole(const string& date)   //IN - string date
{
    // date must haev the format "MM/DD/YYYY"
    assert(is_valid_date(date));
    vector<string> v = split(date, '/');
    _month = stoi(v[0]);
    _day = stoi(v[1]);
    _year = stoi(v[2]);
}


/**************************************************************
 * void Date::set_month(int m)
 * ____________________________________________________________
 * This method sets month
 * ___________________________________________________________
 * Pre-Condition
 * int month
 *
 * Post-Condition
 * month is set to given paremeter
 *************************************************************/
void Date::set_month(int m)   //IN - int m
{
    assert(is_valid_date(_day, m, _year));
    _month = m;
}


/**************************************************************
 * void Date::set_day(int d)
 * ____________________________________________________________
 * This method sets day
 * ___________________________________________________________
 * Pre-Condition
 * int day
 *
 * Post-Condition
 * day is set to given paremeter
 *************************************************************/
void Date::set_day(int d)    //IN - int d
{
    assert(is_valid_date(d, _month, _year));
    _day = d;
}


/**************************************************************
 * void Date::set_year(int y)
 * ____________________________________________________________
 * This method sets year
 * ___________________________________________________________
 * Pre-Condition
 * int year
 *
 * Post-Condition
 * year is set to given paremeter
 *************************************************************/
void Date::set_year(int y)  //IN - int y
{
    assert(is_valid_date(_day, _month, y));
    _year = y;
}

/**************************************************************
 * bool Date::is_leap(int y) const
 * ____________________________________________________________
 * This method verifies if y is a leap year
 * ___________________________________________________________
 * Pre-Condition
 * int year is given
 *
 * Post-Condition
 * returns true if y is a leap year else false
 *************************************************************/
bool Date::is_leap(int y) const    //IN - int y
{
    return is_leap_year(y);
}

/**************************************************************
 * bool Date::_compare_dates(const Date &d1, const Date & d)
 * ____________________________________________________________
 * This method verifies date 1 is before date 2
 * ___________________________________________________________
 * Pre-Condition
 * const Date d1 and d2 are given
 *
 * Post-Condition
 * returns true date 1 is before date 2
 *************************************************************/
bool Date::_compare_dates(const Date &d1, const Date & d)
{
    if (d1.get_year() < d.get_year()){
        return true;
    }
    else if (d1.get_year() == d.get_year()) {
        if (d1.get_month() == d.get_month() &&
                d1.get_day() < d.get_day()){
            return true;
        }
        else if (d1.get_month() < d.get_month()) {
            return true;
        }
    }
    return false;
}

