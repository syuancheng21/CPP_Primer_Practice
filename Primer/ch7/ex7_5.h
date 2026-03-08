//
//ex7_5.h
// Exercise 7.5, P233
//

#ifndef SYUAN_EX7_5_H
#define SYUAN_EX7_5_H

#include <string>

struct Person
{
    std::string name;
    std::string address;

public:
    std::string get_name() const { return name; }
    std::string get_address() const { return address; }
};

#endif // SYUAN_EX7_5_H