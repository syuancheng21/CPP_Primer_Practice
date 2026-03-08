#include "ex12_2.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> v1;
  v1.push_back("hello");

  const StrBlob sb1(v1);
  std::cout << sb1.front() << " " << sb1.back() << std::endl;
  sb1.back() = "tesla";
  std::cout << sb1.front() << " " << sb1.back() << std::endl;
}