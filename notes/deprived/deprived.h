#ifndef A6FDC25C_C4B8_4359_843E_8C84B7B35283
#define A6FDC25C_C4B8_4359_843E_8C84B7B35283

#include "base.h"
#include <cstddef>
#include <iostream>
#include <string>

class Deprived : public Base {
public:
  Deprived() = default;
  Deprived(std::string n, size_t m) : Base(n), num(m) {}

  void print() const override;

private:
  std::size_t num = 0;
};

void Deprived::print() const {
  std::cout << "deprived= " << name << "num= " << num << "\n";
}

#endif /* A6FDC25C_C4B8_4359_843E_8C84B7B35283 */
