#include "ex15_5.h"
#include "ex15_3.h"
#include <cstddef>
#include <iostream>
#include <ostream>

double Bulk_quote::net_price(std::size_t n) const {
  if (n > min_qty) {
    return n * (1 - discount) * price;
  }
  return n * price;
}

double print_total(std::ostream &os, const Quote &item, size_t n) {
  double ret = item.net_price(n);
  os << "ISBN:" << item.isbn() << " #sold: " << n << "total due: " << ret
     << std::endl;
  return ret;
}

int main() {
  Quote q("textbook", 10.60);
  Bulk_quote bq("textbook", 10.60, 10, 0.3);

  print_total(std::cout, q, 12);
  print_total(std::cout, bq, 12);

  return 0;
}