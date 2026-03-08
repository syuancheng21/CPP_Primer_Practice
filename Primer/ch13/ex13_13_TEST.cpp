#include "ex13_13.h"
#include <cstdio>
#include <string>
#include <vector>

void f(const X &rx, X x) {
  std::vector<X> vec;
  vec.reserve(2);
  vec.push_back(rx);
  vec.push_back(x);
}

int main() {
  X *px = new X;
  f(*px, *px);
  delete px;

  printf("=========\n");

  Y qx("a");

  // std::string tmp = "b";
  Y qy = qx;

  return 0;
}