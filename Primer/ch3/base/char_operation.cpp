#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
  string str("some string");
  for (auto c : str) { // str的字符是被拷贝给了循环变量c
    cout << c << endl;
  }

  string s("Hello World!!!");
  decltype(s.size()) punct_cnt = 0;
  //小写转大写, 循环变量必须是引用类型
  for (auto &c : s) { 
    c = toupper(c); // c是引用，因此赋值语句将会改变s中的字符的值
  }
  cout << s << endl;
}