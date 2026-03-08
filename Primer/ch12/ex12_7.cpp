

#include <iostream>
#include <istream>
#include <memory>
#include <ostream>
#include <vector>

using VecPtr = std::shared_ptr<std::vector<int>>;

VecPtr populate(VecPtr vec) {
  vec->push_back(3);
  vec->push_back(6);
  vec->push_back(9);

  return vec;
}

std::ostream &print(VecPtr vec) {
  for (int i = 0; i < vec->size(); i++) {
    std::cout << i << " ";
  }
  return std::cout;
}

int main() {
  auto vec = std::make_shared<std::vector<int>>();
  vec = populate(vec);
  print(vec) << std::endl;

  return 0;
}