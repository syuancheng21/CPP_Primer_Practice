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
  vector<int> vi;
  for (int i = 0; i < 10; i++) {
    vi.push_back(i);
  }
  printVec(vi);

  auto iter = vi.begin();
  while (iter != vi.end()) {
    if (*iter % 2) {
      iter = vi.insert(iter, *iter); //添加在前面， 然后返回新添加的元素
      iter += 2;
    } else {
      iter = vi.erase(iter);
    }
  }

  printVec(vi);

  return 0;
}