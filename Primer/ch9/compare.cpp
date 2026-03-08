#include <string>
#include <vector>

#include <iostream>

using namespace std;

int main() {
  vector<int> v1(5, 1);
  vector<int> v2(5, 2);
  vector<int> v3(7, 1);

  bool res = v1 < v2;
  cout << res << endl; // true 1

  bool res1 = v3 < v1;

  cout << res1 << endl; // false 0

  bool res2 = v3 < v2;

  cout << res2 << endl; // true 1

  return 0;
}