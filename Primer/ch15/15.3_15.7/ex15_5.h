#ifndef EC926CE8_CF1B_49CB_9DB2_D7D38563C471
#define EC926CE8_CF1B_49CB_9DB2_D7D38563C471

#include "ex15_3.h"
#include <string>

class Bulk_quote : public Quote {
public:
  Bulk_quote() = default;
  Bulk_quote(std::string b, double p, size_t m, double d)
      : Quote(b, p), min_qty(m), discount(d) {}

  double net_price(std::size_t n) const override;

private:
  size_t min_qty = 0;
  double discount = 0.0;
};

#endif /* EC926CE8_CF1B_49CB_9DB2_D7D38563C471 */
