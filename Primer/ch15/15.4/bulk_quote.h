#ifndef A81A19CB_66EE_4B1B_ADE4_0187626308A1
#define A81A19CB_66EE_4B1B_ADE4_0187626308A1

#include "disc_quote.h"
#include <string>

class Bulk_quote : public Disc_quote {
public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &b, double p, size_t sp, double d)
      : Disc_quote(b, p, sp, d) {}

  double net_price(std::size_t n) const override;

  void debug() const override;
};

#endif /* A81A19CB_66EE_4B1B_ADE4_0187626308A1 */
