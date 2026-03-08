#include "ex13_31.h"
#include <algorithm>
#include <vector>

int main(void) {
  HasPtr s("s"), a("a"), c("c");

  std::vector<HasPtr> vec;
  vec.push_back(s);
  vec.push_back(a);
  vec.push_back(c);

  std::sort(vec.begin(), vec.end());

  for (auto const &elem : vec) {
    elem.show();
  }

  return 0;
}