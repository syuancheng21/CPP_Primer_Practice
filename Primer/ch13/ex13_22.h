#ifndef SYUAN_EX13_22_H
#define SYUAN_EX13_22_H

//Exercise 13.24:
//Q: What would happen if the version of HasPtr in this section didn’t define a destructor? 
//What if HasPtr didn’t define the copy constructor?
//A: If HasPtr didn't define a destructor, a memory leak would occur, compiler synthesized destructor does not manage dynamic memory. 
//If HasPtr didn't define the copy constructor, we would get pointer-like copy behaviour. 
//The ps pointer would be copied to the left hand side, but ps in the lhs and the rhs would still point to the same string on the heap.

#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()): i(0), ps(new std::string(s)) {}
    HasPtr(const HasPtr& hp): i(hp.i), ps(new std::string(*hp.ps)) {}

    HasPtr& operator=(const HasPtr& rhs) {
        auto new_p = new std::string(*rhs.ps);
        delete ps; //必须删除原本的指向的对象， 不然就内存泄露了。

        i = rhs.i;
        ps = new_p;

        return *this;
    }

    ~HasPtr() {
        delete ps;
    }

private:
    int i;
    std::string *ps;
};

#endif // SYUAN_EX13_22_H