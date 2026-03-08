#ifndef CP5_ex13_11_h
#define CP5_ex13_11_h

#include <iostream>
#include <string>

class HasPtr {
public:
  friend void swap(HasPtr &, HasPtr &);
  friend bool operator<(const HasPtr &, const HasPtr &);

  HasPtr(const std::string &s = std::string()) : i(0), ps(new std::string(s)) {}
  HasPtr(const HasPtr &hp) : i(hp.i), ps(new std::string(*hp.ps)) {}

  HasPtr &operator=(HasPtr tmp) {
    this->swap(tmp);
    return *this;
  }

  ~HasPtr() { delete ps; }

  void swap(HasPtr &rhs) {
    using std::swap;
    swap(ps, rhs.ps);
    swap(i, rhs.i);

    std::cout << "31: call swap(HasPtr& rhs)" << std::endl;
  }

  void show() const { std::cout << *ps << std::endl; }

private:
  int i;
  std::string *ps;
};

void swap(HasPtr &lhs, HasPtr &rhs) { lhs.swap(rhs); }

bool operator<(const HasPtr &lhs, const HasPtr &rhs) {
  std::cout << "31: operator<(const HasPtr &lhs, const HasPtr &rhs)"
            << std::endl;
  return *lhs.ps < *rhs.ps;
}

#endif