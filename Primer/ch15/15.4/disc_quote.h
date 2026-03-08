#ifndef C679AA7F_749C_4F1C_9413_C1BBAFECE4E4
#define C679AA7F_749C_4F1C_9413_C1BBAFECE4E4

#include "quote.h"
#include <string>

class Disc_quote : public Quote {
public:
  Disc_quote() = default;
  Disc_quote(const std::string &b, double p, size_t sq, double d)
      : Quote(b, p), sold_qty(sq), discount(d) {}

  double net_price(std::size_t n) const override = 0;
  void debug() const override = 0;
  //   ~Disc_quote() = default;

protected:
  size_t sold_qty = 0;
  double discount = 0.0;
};

#endif /* C679AA7F_749C_4F1C_9413_C1BBAFECE4E4 */
