
#include <iostream>

template <typename T, unsigned N> void printf(T (&arr)[N]) {
  for (auto elem : arr) {
    std::cout << elem << std::endl;
  }
}

int main() {
  int i = 0, j[2] = {0, 1};
  int k[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  printf(j);
  printf(k);

  return 0;
}