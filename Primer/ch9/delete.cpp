#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printVec(vector<string> &vec) {
  string res;
  for (const string &elem : vec) {
    res += elem;
    res += ", ";
  }
  cout << "vec=" << res << endl;
}

int main() {
  vector<string> sevc;
  sevc.push_back("hi");
  sevc.push_back("zhao");
  sevc.push_back("tang");
  printVec(sevc); // vec=hi, zhao, tang,

  sevc.pop_back();
  printVec(sevc); // vec=hi, zhao,

  sevc.erase(sevc.begin(), sevc.begin() + 2); //[begin, begin+2)
  printVec(sevc);                             // vec=

  return 0;
}