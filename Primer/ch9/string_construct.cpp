#include <iostream>
#include <string>

using namespace std;

int main() {
  const char *cp = "Hello World!!";
  char noNull[] = {'H', 'i'};
  string s1(cp);
  cout << "str: " << s1 << endl;

  string s2(noNull, 2);
  cout << "str: " << s2 << endl;

  string s4(cp + 6, 5);
  cout << "str: " << s4 << endl;

  string s5(s1, 6, 5);
  cout << "str: " << s5 << endl;

  string s6(s1, 6);
  cout << "str: " << s6 << endl;

  return 0;
}