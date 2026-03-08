#include <string>

using std::string;

int main() {
  string s1;         //默认初始化，是空字符串
  string s2(s1);     // s2是s1的副本
  string s3 = s2;    // 等价与s2
  string s4 = "abc"; // s4是字面值的副本
  string s5("abc");  //和s4一样
  string s6(6, 'n'); // s6初始化为 由连续6个字符n组成的串
}