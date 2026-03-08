#include <iostream>

using std::cout;
using std::endl;


int main() {
  int i, &ri = i;
  i = 5;
  ri = 10;
  cout << i << " " << ri << endl;

  int ni = 20;
  ri = ni; 
    cout << i << " " << ri << endl;
    return 0;
}