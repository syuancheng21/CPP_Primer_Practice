#include <iostream>
#include <vector>

class NoDefault {
public:
    NoDefault(int n) {}
};

class C {
public:
    C():def(0) {};

private:
    NoDefault def;
};

int main() {
    // std::vector<NoDefault> vec(10);// wrong, NoDefault don't have default constructor

    std::vector<C> ved(10); // right: C have default constructor.
    return 0;
}