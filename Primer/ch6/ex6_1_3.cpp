#include <iostream>

using namespace std;

int fact(int val) {
  int ret = 1;
  while (val > 1) {
    // ret = ret*val;
    // val--;
    ret *= val--;
  }

  return ret;
}

int main() {

  int s = fact(5);

  cout << "result is: " << s << endl;
}