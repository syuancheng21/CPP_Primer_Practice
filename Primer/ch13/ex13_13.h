#ifndef SYUAN_EX13_13_H
#define SYUAN_EX13_13_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;

struct X {
  X() { cout << "X()" << endl; }
  X(const X &) { cout << "X(const X&)" << endl; }

  X &operator=(const X &) {
    cout << "operator=" << endl;

    return *this;
  }

  ~X() { cout << "~X()" << endl; }
};

struct Y {
  Y(std::string) { cout << "Y()" << endl; }
  Y(const Y &) { cout << "Y(const Y&)" << endl; }

  Y &operator=(const Y &) {
    cout << "operator=" << endl;

    return *this;
  }

  ~Y() { cout << "~Y()" << endl; }

  std::string vlaue;
};

#endif // SYUAN_EX13_13_H