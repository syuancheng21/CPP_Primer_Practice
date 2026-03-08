#include <iostream>
#include <string>

using namespace std;

int main() {
  string s("Hello World");
  cout << "str: " << s << endl;

  string s2 = s.substr(0, 5);
  cout << "str: " << s2 << endl;

  string s3 = s.substr(6);
  cout << "str: " << s3 << endl;

  string s4 = s.substr(6, 11);
  cout << "str: " << s4 << endl;

  return 0;
}