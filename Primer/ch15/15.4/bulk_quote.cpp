#include "bulk_quote.h"
#include "disc_quote.h"
#include <iostream>

double Bulk_quote::net_price(std::size_t n) const {
  if (n <= sold_qty) {
    return n * price * (1 - discount);
  }
  return n * price;
}

void Bulk_quote::debug() const {
  std::cout << "data members of this class:\n"
            << "qty= " << this->sold_qty << " "
            << "discount= " << this->discount << " ";
}

double print_total(std::ostream &os, const Quote &item, size_t n) {
  double ret = item.net_price(n);
  os << "ISBN:" << item.isbn() << " #sold: " << n << "total due: " << ret
     << std::endl;
  return ret;
}

int main() {
  Bulk_quote dp("sss", 12.9, 10, 0.1);
  print_total(std::cout, dp, 100);
  //   Disc_quote d;

  return 0;
}
