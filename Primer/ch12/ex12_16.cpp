#include <memory>


std::unique_ptr<int> clone(int p) { return std::unique_ptr<int>(new int(p)); }

std::unique_ptr<int> copy(int p) {
  std::unique_ptr<int> tmp(new int(p));
  return tmp;
}

int main() {
  std::unique_ptr<int> p1(new int(12));
  std::unique_ptr<int> q1(new int(23));

  //wrong
  // std::unique_ptr<int> p2(p1);
  // q1 = p1;

  clone(12);
  copy(23);

  return 0;
}