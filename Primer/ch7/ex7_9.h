#ifndef SYUAN_EX7_9_H
#define SYUAN_EX7_9_H

#include <string>
#include <istream>
#include <ostream>


struct Person
{
    std::string name;
    std::string address;

    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
};

std::istream& read(std::istream& is, Person& p) {
    is >> p.name >> p.address;

    return is;
}

std::ostream& print(std::ostream& os, const Person& p) {
    return os << "Name: " << p.getName() << ", Addr: " << p.getAddress() << "\n";
}



#endif // SYUAN_EX7_9_H