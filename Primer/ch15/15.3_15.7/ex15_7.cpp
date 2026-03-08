#include "ex15_7.h"

double Weried_quote::net_price(std::size_t n) const {
  if (n < max_qty) {
    return n * price * (1 - discount);
  }
}