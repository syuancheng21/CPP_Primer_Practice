#ifndef SYUAN_EX7_22_H
#define SYUAN_EX7_22_H


#include <string>
#include <istream>
#include <ostream>

class Person
{
friend std::istream& read(std::istream& is, Person& p);
friend std::ostream& print(std::ostream& os, const Person& p);

private:
    std::string name;
    std::string address;

public:
    Person() = default;
    Person(const std::string& n, const std::string& a):name(n), address(a) {}
    Person(std::istream& is) { read(is, *this); }

    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
};


std::istream& read(std::istream& is, Person& p) {
    is >> p.name >> p.address;
    return is;
}

std::ostream& print(std::ostream& os, const Person& p) {
    os << "Name: " << p.getName() << ", Address: " << p.getAddress();
    return os;
}


#endif // SYUAN_EX7_22_H