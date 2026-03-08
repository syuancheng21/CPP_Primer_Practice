#include <cstddef>
#include <iostream>
#include <string>

using std::string;

int main() {
  string s;
  std::cin >> s;//将string对象读入s，遇到空白停止。
  bool isEmpty = s.empty();
  size_t num = s.size(); // s中包含的字符数
  s[1];                  //返回s中第1个字符的引用
  string s1 = "cheng ";
  string s2 = "siyuan";
  string s3 = s1 + s2; //拼接s1和s2.
  s1 = s2; //用s2的副本代替s1中原来的字符。
}