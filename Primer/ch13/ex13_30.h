#ifndef CP5_ex13_11_h
#define CP5_ex13_11_h


#include <string>
#include <iostream>

class HasPtr {
public:
    friend void swap(HasPtr&, HasPtr&);
  
    HasPtr(const std::string &s = std::string()) : i(0), ps(new std::string(s)) {}
    HasPtr(const HasPtr &hp) : i(hp.i), ps(new std::string(*hp.ps)) {}

    HasPtr &operator=(const HasPtr &rhs) {
      auto new_p = new std::string(*rhs.ps);

      delete ps;//必须删除原本的指向的对象， 不然就内存泄露了。

      this->i = rhs.i;
      this->ps = new_p;

      return *this;
    }

    ~HasPtr() {
      delete ps;
    }


private:
    int i;
    std::string *ps;
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
  using std::swap;
  swap(lhs.ps, rhs.ps);
  swap(lhs.i, rhs.i);

  std::cout << "call swap(HasPtr& lhs, HasPtr& rhs)" << std::endl;
}


#endif