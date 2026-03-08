#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printVec(vector<int> &vec) {
  string res;
  for (int elem : vec) {
    res += to_string(elem);
    res += ", ";
  }
  cout << "vec=" << res << endl;
}

int main() {
  vector<int> ivec;
  cout << "ivec size: " << ivec.size() << " capacity: " << ivec.capacity()
       << endl; // 0  0
  for (vector<int>::size_type ix = 0; ix != 24; ++ix) {
    ivec.push_back(ix);
  }
  cout << "ivec size: " << ivec.size() << " capacity: " << ivec.capacity()
       << endl; // 24   32

  ivec.reserve(50); //预分配额外的空间
  cout << "ivec size: " << ivec.size() << " capacity: " << ivec.capacity()
       << endl; // 24 50

  while (ivec.size() != ivec.capacity()) {
    ivec.push_back(0);
  }

  cout << "ivec size: " << ivec.size() << " capacity: " << ivec.capacity()
       << endl; // 50    50

  ivec.push_back(42);
  cout << "ivec size: " << ivec.size() << " capacity: " << ivec.capacity()
       << endl; // 51 100
  ivec.shrink_to_fit();
  cout << "ivec size: " << ivec.size() << " capacity: " << ivec.capacity()
       << endl; // 51 51

  return 0;
}