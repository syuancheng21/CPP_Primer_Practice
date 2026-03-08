
#include <string>

int main() {
  constexpr unsigned sz = 42;
  int arr[10];          //含有10个整数的数组
  std::string strs[sz]; //含有42个字符串的数组
  //数组元素会被默认初始化

  //显式初始化数组元素
  const unsigned n = 3;
  int ial[sz] = {0, 1, 2};
  int a1[] = {0, 1, 2, 3};
  int a2[3] = {1, 2, 3};              //{1.2.3.0.0}
  std::string st1[3] = {"hi", "bye"}; //等价于 {"hi", "bye", ""}
  
}