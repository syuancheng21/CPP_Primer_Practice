#include <iostream>
#include <string>

using namespace std;

template <typename T> int compare(const T &v1, const T &v2) {
  if (v1 < v2) {
    return -1;
  }
  if (v2 < v1) {
    return 1;
  }
  return 0;
}

int main() {
  int v1 = 12;
  int v2 = 34;
  cout << compare(v1, v2) << endl;

  string s1 = "syuan";
  string s2 = "cheng";
  cout << compare(s1, s2) << endl;
}