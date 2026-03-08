#ifndef SYUAN_EX13_18_H
#define SYUAN_EX13_18_H

#include <string>

class Employee {
private:
    std::string name;
    int id;

    static int unique_id;

public:
    Employee() {
        id = unique_id++;
    }
    Employee(const std::string& n) {
        id = unique_id++;
        name = n;
    }
};

int Employee::unique_id = 1;


#endif // SYUAN_EX13_18_H