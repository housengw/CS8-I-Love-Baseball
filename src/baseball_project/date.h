#ifndef DATE_H
#define DATE_H
#include <string>
#include "helpers.h"

using namespace std;

class Date
{
public:
    /****************************************
    **  CONSTRUCTORS  **
    *****************************************/
    Date();
    Date(int m, int d, int y);
    Date(const string& m, int d, int y);


    /*******************************************
    **  ACCESSORS  **
    *******************************************/
    string get_date() const;                        //access the whole date info
    int get_day() const{return _day;}               //access the day
    int get_month() const{return _month;}           //access the month
    int get_year() const{return _year;}             //access the year
    bool is_leap(int y) const;                      //checks for leap year

    /**********************************************
    **  MUTATORS  **
    ***********************************************/
    void set_whole(const string& date);             //splits passed string value of the WHOLE date info
    void set_month(int m);                          //sets month
    void set_day(int d);                            //sets date
    void set_year(int y);                           //sets year

    /*******************************************
    **  COMPARISON  **
    *******************************************/
    bool _compare_dates(const Date &d1, const Date & d);

private:
    int _day;             //IN/OUT  date
    int _month;           //IN/OUT  numeric month
    string _month_name;   //IN/OUT  name month
    int _year;            //IN/OUT the year
};

#endif // DATE_H

/**************************************************************************
 * Date Class
 *    This class holds a date in form of month, day, year.
 *    The class provides mutators, accessors, and comparison functions.
 **************************************************************************/

/****************************************
 **  CONSTRUCTORS  **
 *****************************************/
/*****************************************
 *  Date();
 *   Constructor: initialize private members to default values
 *   Parameters: None
 *   Return: None
 *****************************************/
/*****************************************
 *  Date(int m, int d, int y);
 *   Constructor: initialize private members to the input data
 *   Parameters: date (m, d,y)
 *   Return: None
 *****************************************/
/*****************************************
 *  Date(const string& m, int d, int y);
 *   Constructor: initialize private members to the input data
 *   Parameters: date (string m, d,y)
 *   Return: None
 *****************************************/

/****************************************
 **  ACCESSORS  **
 *****************************************/
/***********************************************
 * string get_date() const;
 *   Accessor: return date in string
 *   Parameters: None
 *   Return: string date
 **********************************************/
/***********************************************
 * int get_day() const
 *   Accessor: return day
 *   Parameters: None
 *   Return: int day
 **********************************************/
/***********************************************
 * int get_month() const
 *   Accessor: return int month
 *   Parameters: None
 *   Return: int month
 **********************************************/
/***********************************************
 * int get_year() const
 *   Accessor: return int year
 *   Parameters: None
 *   Return: int year
 **********************************************/
/***********************************************
 * bool is_leap(int y) const;
 *   Accessor: checks if y is leap year
 *   Parameters: int y
 *   Return: return true if y is leap year
 **********************************************/


/****************************************
 **  MUTATORS  **
 *****************************************/
/*******************************************
 *  void set_whole(const string& date);
 *   Mutator: set date in string
 *   Parameters: string date
 *   Return: None
 *****************************************/
/*******************************************
 *  void set_month(int m);
 *   Mutator: set month
 *   Parameters: int m
 *   Return: None
 *****************************************/
/*******************************************
 *  void set_day(int d);
 *   Mutator: set day
 *   Parameters: int d
 *   Return: None
 *****************************************/
/*******************************************
 *  void set_year(int y);
 *   Mutator: set year
 *   Parameters: int y
 *   Return: None
 *****************************************/


/****************************************
 **  COMPARISON  **
 *****************************************/
/*******************************************
 *  bool _compare_dates(const Date &d1, const Date & d);
 *   Compare: compare date1 and date 2
 *   Parameters: const Date d1 and d2
 *   Return: true if d1 is earlier than d2
 *****************************************/
