

#include <iostream>
#include <ostream>
#include <vector>

using VecPrt = std::vector<int> *;

VecPrt populate(VecPrt vec) {
  for (int i = 0; i < 1; i++) {
    int tmp = 0;
    std::cout << "Plz enter:\n";
    std::cin >> tmp;
    vec->push_back(tmp);
  }
  return vec;
}

std::ostream &print(VecPrt vec) {
  for (int i = 0; i < vec->size(); i++) {
    std::cout << (*vec)[i] << " ";
  }
  return std::cout;
}

int main() {
  VecPrt vec = new std::vector<int>();

  vec = populate(vec);

  print(vec) << std::endl;

  delete vec;

  return 0;
}