#include "helpers.h"

/**********************************************************
*
* Function is_unsigned_int
*_________________________________________________________
* checks if the given string is an unsigned int
*
* -returns true if the given string is unsigned int
*          false otherwise
*_________________________________________________________
* PRE-CONDITIONS
* The following needs previously defined values:
* str: the string to be checked
*
* POST-CONDITIONS
* true is returned if the given string is unsigned int,
* false is returned otherwise.
***********************************************************/
bool is_unsigned_int(std::string str){ //IN - the string to be checked
    for (unsigned int i=0; i<str.length(); i++){
        if (!isdigit(str[i])) return false;
    }
    return true;
}

/**********************************************************
*
* Function split_str_into_vector
*_________________________________________________________
* splits a string into a vector
*
* -returns a vector that stores the split string
*_________________________________________________________
* PRE-CONDITIONS
* The following needs previously defined values:
* str: the string to be split
* split_char: the char to split the string
*
* POST-CONDITIONS
* a vector that stores the split string is returned
***********************************************************/
std::vector<std::string> split(
        std::string str,  //IN - the string to be split
        char split_char){ //IN - the character to split the string
                          //     by.
    std::vector<std::string> row;
    std::string word;

    std::stringstream s(str);
    while (getline(s, word, split_char)) {
        row.push_back(word);
    }

    return row;
}

/**********************************************************
*
* Function is_valid_date
*_________________________________________________________
* checks if the given date is valid
*
* -returns true if the date is valid
*          false otherwise
*_________________________________________________________
* PRE-CONDITIONS
* The following needs previously defined values:
* day: the day of the date
* month: the month of the date
* year: the year of the date
*
* POST-CONDITIONS
* true is returned if the date is valid
* false is returned otherwise
***********************************************************/
bool is_valid_date(int day,     //IN - the day of the date
                   int month,   //IN - the month of the date
                   int year){   //IN - the year of the date
    if (month < 1 || month > 12) return false;
    if (day < 1) return false;
    if (month == 2){
        if (is_leap_year(year)){
            return (day <= 29);
        }
        else{
            return (day <= 28);
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11){
        return (day <= 30);
    }
    return (day <= 31);
}

/**********************************************************
*
* Function is_valid_date
*_________________________________________________________
* checks if the given date is valid
*
* -returns true if the date is valid
*          false otherwise
*_________________________________________________________
* PRE-CONDITIONS
* The following needs previously defined values:
* date: the string representing a date in MM/DD/YYYY format
*
* POST-CONDITIONS
* true is returned if the date is valid
* false is returned otherwise
***********************************************************/
bool is_valid_date(std::string date){   //IN - the date to be validated
    std::vector<std::string> validationVector = split(date, '/');
    if (validationVector.size() != 3){
        return false;
    }
    int month, day, year;
    if (!is_unsigned_int(validationVector[0]) ||
            !is_unsigned_int(validationVector[1]) ||
            !is_unsigned_int(validationVector[2])){
        return false;
    }

    month = stoi(validationVector[0]);
    day = stoi(validationVector[1]);
    year = stoi(validationVector[2]);
    if (!is_valid_date(day, month, year)){
        return false;
    }
    return true;
}

/**********************************************************
*
* Function is_leap_year
*_________________________________________________________
* checks if the given year is a leap year
*
* -returns true if the year is a leap year
*          false otherwise
*_________________________________________________________
* PRE-CONDITIONS
* The following needs previously defined values:
* year: the year to be checked
*
* POST-CONDITIONS
* true is returned if the year is a leap year
* false is returned otherwise
***********************************************************/
bool is_leap_year(int year){    //IN - the year to be checked
    if (year % 400 == 0) return true;
    else if (year % 100 == 0) return false;
    else if (year % 4 == 0) return true;
    return false;
}

/**********************************************************
*
* Function is_positive_number
*_________________________________________________________
* checks if the given string is a positive number
*
* -returns true if the string is a positive number
*          false otherwise
*_________________________________________________________
* PRE-CONDITIONS
* The following needs previously defined values:
* str: the string to be checked
*
* POST-CONDITIONS
* true is returned if the string is a positive number
* false is returned otherwise
***********************************************************/
bool is_positive_number(std::string str){   //IN - the string to be checked
    int dot_count = 0;
    if (str.length() == 0 || str[0] == '.') return false;
    for (unsigned int i=0; i<str.length(); i++){
        if (!isdigit(str[i])){
            if (str[i] == '.' && dot_count == 0){
                dot_count++;
            }
            else {
                return false;
            }
        }
    }
    return true;
}


/**********************************************************
*
* Function rstrip_newline
*_________________________________________________________
* removes the newline character at the end of a string
*
* -returns nothing
*_________________________________________________________
* PRE-CONDITIONS
* The following needs previously defined values:
* str: the string to be stripped
*
* POST-CONDITIONS
* the newline character at the end of a string has been
* stripped
***********************************************************/
void rstrip_newline(std::string& str){
    if (!isprint(str[str.length()-1]))
        str.erase(str.length()-1);
}

/**********************************************************
*
* Function lower
*_________________________________________________________
* returns a lowercase version of the string
*
* -returns a lowercase version of the string
*_________________________________________________________
* PRE-CONDITIONS
* The following needs previously defined values:
* str: the string to be lowered
*
* POST-CONDITIONS
* a lowercase version of the string is returned
***********************************************************/
std::string lower(std::string str){
    for (unsigned int i=0; i<str.length(); i++){
        str[i] = tolower(str[i]);
    }
    return str;
}

bool contains(Container<int> c, int n){
    for (size_t i=0; i<c.size(); i++){
        if (c[i] == n) return true;
    }
    return false;
}

int find_unsigned_min_not_in_s(int* array, size_t size, Container<int> s){
    if (size <= 0) return -1;
        int min_index = -1;
        int min_val = 0;
        for (size_t i=0; i<size; i++){
            if (contains(s, i) || array[i] < 0) continue;
            if (min_index < 0 || array[i] < min_val){
                min_val = array[i];
                min_index = i;
            }
        }
        return min_index;
}
