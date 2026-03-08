#include "base.h"
#include "deprived.h"
#include <iostream>

int main() {
  Base b("wlswn");
  Deprived d("sgyy", 20);

  b.print();
  d.print();

  return 0;
}