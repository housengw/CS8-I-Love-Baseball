#ifndef DATE_H
#define DATE_H
#include "helpers.h"
#include <string>

using namespace std;

class Date
{
  public:
    Date(); // Default constructor - sets date to 1/1/2000
    Date(int month, int day, int year);
    Date(const string &month, int day, int year); // Unfinished

    /***************
     ** ACCESSORS **
     ***************/
    string get_date() const;                 // access the whole date info
    int get_day() const { return _day; }     // access the day
    int get_month() const { return _month; } // access the month
    int get_year() const { return _year; }   // access the year
    bool is_leap(int year) const;            // checks for leap year

    /**************
     ** MUTATORS **
     **************/
    void set_date(const string &date); // splits passed string value of the
                                       // WHOLE date info. Sets whole date.
    void set_month(int month);         // sets month
    void set_day(int day);             // sets date
    void set_year(int year);           // sets year
    bool compare_dates(const Date &d1, const Date &d); // Returns true if
                                                       // d1 is further back in
                                                       // time than d. Returns
                                                       // true if d1 and d are
                                                       // the same date. False
                                                       // otherwise

  private:
    int _month;         // determines the numeric month
    string _month_name; // determines the name month
    int _day;           // determines the date
    int _year;          // determines the year
};

#endif // DATE_H
