#include <iostream>
#include <vector>

int main() {
  std::vector<int> v(10, 8);
  for (auto &i : v) {
    i *= i;
  }
  for (auto i : v) {
    std::cout << i << std::endl;
  }
}