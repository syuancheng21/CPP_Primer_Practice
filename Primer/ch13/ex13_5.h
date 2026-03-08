#ifndef SYUAN_EX13_5_H
#define SYUAN_EX13_5_H

#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
private:
    std::string *ps;
    int i;
};

#endif // SYUAN_EX13_5_H