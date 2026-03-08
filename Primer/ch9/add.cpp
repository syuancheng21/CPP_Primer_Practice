#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<string> sevc;
  sevc.push_back("hi");
  sevc.push_back("zhao");
  sevc.push_back("tang");

  cout << "before: " << sevc[0] << endl; // hi

  sevc.insert(sevc.begin(), "##");

  cout << "after: " << sevc[0] << endl; //##

  auto iter = sevc.insert(sevc.begin(), 3, "haha");

  cout << "after: " << sevc[0] << sevc[1] << sevc[2] << endl; // hahahahahaha
  cout << "iter: " << *iter << endl;

  return 0;
}