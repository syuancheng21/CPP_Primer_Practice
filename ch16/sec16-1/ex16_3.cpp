#include <iostream>

using std::string;

struct Sales_data {
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

template <typename T> int compare(const T &lhs, const T &rhs) {
  if (lhs < rhs) {
    return -1;
  }
  if (rhs < lhs) {
    return 1;
  }
  return 0;
}

int main() {
  Sales_data s1, s2;
  compare(s1, s2);

  return 0;
}