#include "quote.h"
#include <iostream>
#include <string>

class Limit_quote : public Quote {
public:
  Limit_quote() = default;
  Limit_quote(std::string b, double p, size_t m, double d)
      : Quote(b, p), min_count(m), discount(d) {}

  double net_price(size_t s) const override;

  void debug() const override;

private:
  size_t min_count;
  double discount = 0.0;
};

double Limit_quote::net_price(size_t s) const {
  if (s > min_count) {
    return s * price * (1 - discount);
  }
  return s * price;
}

void Limit_quote::debug() const {
  Quote::debug();
  std::cout << "min_count= " << this->min_count
            << " ,discount= " << this->discount;
}