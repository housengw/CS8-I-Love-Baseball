#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>

using namespace std;

struct Address
{
public:
    Address();
    Address(string street, string city, string state, string zip_code);
    string street;
    string city;
    string state;
    string zip_code;
};

#endif // ADDRESS_H
