

#include <iostream>
#include <vector>

template <typename I, typename T> I find_value(I first, I last, const T &t) {
  for (; first != last; first++) {
    if (*first != t) {
      continue;
    }
    return first;
  }
  return last;
}

int main() {

  std::vector<int> test;
  test.push_back(1);
  test.push_back(2);
  test.push_back(3);
  test.push_back(4);
  test.push_back(5);

  auto iter = find_value(test.begin(), test.end(), 3);

  std::cout << *iter;

  return 0;
}