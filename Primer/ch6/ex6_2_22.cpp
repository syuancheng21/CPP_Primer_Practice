#include <iostream>

void swap(int *&a, int *&b) {
  int *tmp = a;
  a = b;
  b = tmp;
}

int main() {
  int m = 2, n = 7;

  int *mP = &m;
  int *nP = &n;

  std::cout << "mp=" << mP << " ,np=" << nP << std::endl;

  swap(mP, nP);

  std::cout << "mp=" << mP << " ,np=" << nP << std::endl;

  return 0;
}