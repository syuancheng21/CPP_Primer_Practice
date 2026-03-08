#include <iostream>
#include <ostream>

int main() {
  int ia[] = {1, 3, 5, 7, 9};
  int last = *(ia + 4);
  std::cout << last << std::endl; // 9

  int i = ia[2];
  int *p = ia;
  i = *(p + 2);

  int *q = &ia[2];
  int j = q[1];  // 7
  int k = q[-2]; // 1
}