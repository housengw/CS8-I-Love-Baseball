#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "constants.h"

/*******************************************************************
* bool is_unsigned_int(std::string str);
*
* Checks if the given string is an unsigned int
*------------------------------------------------------------------
* Parameter: str (string) //IN - the string to be checked
*------------------------------------------------------------------
* Return: true if the given string is unsigned int
*         false otherwise
*******************************************************************/
bool is_unsigned_int(std::string str);

/*******************************************************************
* vector<string> split_str_into_vector(string str, char split_char);
*
* split a string into a vector based on split_char
*------------------------------------------------------------------
* Parameter: str (string)      //IN - the string to be split
*            split_char (char) //IN - the character to split the string
*                                     by.
*------------------------------------------------------------------
* Return: a vector of the string split by split_char
*******************************************************************/
std::vector<std::string> split(std::string str, char split_char);

/*******************************************************************
* bool is_valid_date(int day, int month, int year);
*
* Checks if the given date is valid
*------------------------------------------------------------------
* Parameter: day (int)    //IN - the day of the date
*            month (int)  //IN - the month of the date
*            year (int)   //IN - the year of the date
*------------------------------------------------------------------
* Return: true if the given date is valid
*         false otherwise
*******************************************************************/
bool is_valid_date(int day, int month, int year);

/*******************************************************************
* bool is_valid_date(std::string date);
*
* Checks if the given date is valid
*------------------------------------------------------------------
* Parameter: date (string) //IN - the date to be validated
*------------------------------------------------------------------
* Return: true if the given date is valid
*         false otherwise
*******************************************************************/
bool is_valid_date(std::string date);

/*******************************************************************
* bool is_leap_year(int year);
*
* Checks if the given year is a leap year
*------------------------------------------------------------------
* Parameter: year (int) //IN - the year to be checked
*------------------------------------------------------------------
* Return: true if the given year is a leap year
*         false otherwise
*******************************************************************/
bool is_leap_year(int year);

/*******************************************************************
* bool is_positive_number(std::string str);
*
* Checks if the given string is a positive number
*------------------------------------------------------------------
* Parameter: str (string) //IN - the string to be checked
*------------------------------------------------------------------
* Return: true if the given string is a positive number
*         false otherwise
*******************************************************************/
bool is_positive_number(std::string str);

/*******************************************************************
* void rstrip_newline(std::string& str);
*
* removes the newline character at the end of a string
*------------------------------------------------------------------
* Parameter: str (string) //IN - the string to be stripped
*------------------------------------------------------------------
* Return: nothing
*******************************************************************/
void rstrip_newline(std::string& str);

/*******************************************************************
* std::string lower(std::string str);
*
* returns a lowercase version of the string
*------------------------------------------------------------------
* Parameter: str (string) //IN - the string to be lowered
*------------------------------------------------------------------
* Return: a lowercase version of the string
*******************************************************************/
std::string lower(std::string str);

#endif // HELPERS_H
