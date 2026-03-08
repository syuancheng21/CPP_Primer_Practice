#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<string> sevc;
  sevc.push_back("hi");
  sevc.push_back("zhao");
  sevc.push_back("tang");

  string &a1 = sevc.back();
  cout << "1: " << a1 << endl; // tang
  string &a2 = sevc.front();
  cout << "2: " << a2 << endl; // hi
  string &a3 = sevc.at(1);
  cout << "3: " << a3 << endl; // zhao
  string &a4 = sevc[1];
  cout << "4: " << a4 << endl; // zhao

  return 0;
}