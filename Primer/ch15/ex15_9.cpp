#include "ex15_3.h"
#include "ex15_5.h"

int main() {

  Bulk_quote bulk_quote("bulk_quote", 2.0, 12, 4.1);

  // 1
  Quote &q1 = bulk_quote;
  q1.net_price(100);

  // 2
  Quote *q2 = &bulk_quote;
  q2->net_price(120);

  // 3
  Quote q3 = bulk_quote;
  q3.net_price(130);

  return 0;
}