#ifndef SYUAN_EX13_11_H
#define SYUAN_EX13_11_H

#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
    ~HasPtr() {
        delete ps;
    }

    HasPtr& operator=(const HasPtr& rhs_hp) {
        if (this != &rhs_hp) {
            std::string* temp_ps = new std::string(*rhs_hp.ps);
            delete ps;

            ps = temp_ps;
            i = rhs_hp.i;
        }
        return *this;
    }
private:
    std::string *ps;
    int i;
};

#endif // SYUAN_EX13_11_H