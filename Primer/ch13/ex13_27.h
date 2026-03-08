#ifndef SYUAN_EX13_27_H
#define SYUAN_EX13_27_H

#include <string>

class HasPtr {
public:
    HasPtr(const std::string& s = std::string()): ps(new std::string(s)), i(0), use(new size_t(1)) {}
    HasPtr(const HasPtr& hp): ps(hp.ps), i(hp.i), use(hp.use) { ++*use; }
    ~HasPtr();
    HasPtr& operator=(const HasPtr& rhs);

private:
    std::string *ps;
    int i;
    std::size_t *use;
};

HasPtr::~HasPtr() {
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }
}

HasPtr& HasPtr::operator=(const HasPtr& rhs) {
    ++*rhs.use;
    
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }

    i = rhs.i;
    ps = rhs.ps;
    use = rhs.use;

    return *this;
}

#endif // SYUAN_EX13_27_H