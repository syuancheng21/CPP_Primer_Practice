#include "limit_quote.h"
#include "quote.h"
#include <iostream>
#include <string>

int main() {
  Quote q("pfsj", 30.5);
  Limit_quote bq("sxwqn", 12.5, 10, 0.15);

  bq.debug();
  bq.net_price(1);

  Quote &r = q;
  r.debug();
  std::cout << "\n";
  r = bq;
  r.debug();
  std::cout << "\n";
  q.debug();
  std::cout << "\n";

  return 0;
}
