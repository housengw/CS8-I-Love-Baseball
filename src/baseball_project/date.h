#ifndef DATE_H
#define DATE_H
#include <string>
#include "helpers.h"

using namespace std;

class Date
{
public:
    Date();
    Date(int m, int d, int y);
    Date(const string& m, int d, int y);
    string get_date() const;                        //access the whole date info
    int get_day() const{return _day;}               //access the day
    int get_month() const{return _month;}           //access the month
    int get_year() const{return _year;}             //access the year

    void set_whole(const string& date);             //splits passed string value of the WHOLE date info
    void set_month(int m);                          //sets month
    void set_day(int d);                            //sets date
    void set_year(int y);                           //sets year
    bool is_leap(int y) const;                      //checks for leap year

    bool _compare_dates(const Date &d1, const Date & d);

private:
    int _day;       //determines the date
    int _month;     //determines the numeric month
    string _month_name;   //determines the name month
    int _year;      //determines the year
};

#endif // DATE_H
