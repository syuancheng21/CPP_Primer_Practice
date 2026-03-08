#include <iostream>
#include <type_traits>

using namespace std;

int main() {

  int &&rr1 = 42;
  //   int &&rr2 = rr1;
  int &&rr3 = std::move(rr1);

  cout << "rr1: " << rr1 << endl;
  cout << "rr3: " << rr3 << endl;

  int r = 12;
  int &r1 = r;
//   int &&rr4 = r1;
  int &&rr5 = std::move(r1);

  return 0;
}