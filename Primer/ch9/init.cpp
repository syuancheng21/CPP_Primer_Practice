#include <deque>
#include <list>
#include <vector>

using namespace std;

int main() {
  vector<int> ivec(10, -1);
  list<string> svec(10, "hi");
  deque<string> svec(10); // 10个元素， 每个都是空string

  return 0;
}