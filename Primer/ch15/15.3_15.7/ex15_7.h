#ifndef F4DE5CC9_47D3_42D9_8E9D_D0D5BA93D7A1
#define F4DE5CC9_47D3_42D9_8E9D_D0D5BA93D7A1

#include "ex15_3.h"
#include <cstddef>

class Weried_quote : public Quote {
public:
  Weried_quote() = default;
  double net_price(std::size_t n) const override;

private:
  size_t max_qty = 0;
  double discount = 0.0;
};

#endif /* F4DE5CC9_47D3_42D9_8E9D_D0D5BA93D7A1 */
