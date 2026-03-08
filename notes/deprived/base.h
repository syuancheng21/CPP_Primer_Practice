#ifndef E36BEB77_C63C_4F5F_BB97_5E0EE22293AF
#define E36BEB77_C63C_4F5F_BB97_5E0EE22293AF

#include <iostream>
#include <string>

class Base {
public:
  Base() = default;
  Base(std::string n) : name(n) {}

  virtual void print() const;

  virtual ~Base() = default;

protected:
  std::string name;
};

void Base::print() const { std::cout << "base= " << name << "\n"; }

#endif /* E36BEB77_C63C_4F5F_BB97_5E0EE22293AF */
