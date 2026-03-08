#include <iostream>
#include <string>

using namespace std;

int main() {
  string s("Hello World");

  s.insert(s.size(), 5, '!');
  cout << "str: " << s << endl;

  s.erase(s.size() - 5, 5);
  cout << "str: " << s << endl;

  const char *cp = "Stately, plump Buck";
  s.assign(cp, 7);
  cout << "str: " << s << endl;
  s.insert(s.size(), cp + 7);
  cout << "str: " << s << endl;

  string s1 = "some string", s2 = "some other string";
  s1.insert(0, s2);
  cout << "str: " << s1 << endl;
  s1.insert(0, s2, 0, s2.size());
  cout << "str: " << s1 << endl;

  string s3("C++ Primer"), s4 = s3;
  s3.insert(s3.size(), " 4th Ed.");
  cout << "str: " << s3 << endl;

  s4.append(" 4th Ed.");
  cout << "str: " << s4 << endl;

  s3.erase(11, 3);
  cout << "str: " << s3 << endl;
  s3.insert(11, "5th");
  cout << "str: " << s3 << endl;

  s4.replace(11, 3, "5th");
  cout << "str: " << s4 << endl;

  s4.replace(11, 3, "Fifth");
  cout << "str: " << s4 << endl;

  return 0;
}