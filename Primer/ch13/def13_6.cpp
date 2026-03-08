#include <iostream>
#include <string>

void foo(int &lref) {
  std::cout << "Received a left value reference" << std::endl;
}

void bar(int &&rref) {
  std::cout << "Received a right value reference" << std::endl;
}

int main() {
  int x = 5;    // x 是左值
  int &&y = 10; // 10 是右值，y是左值，绑定在左值上的右值引用
  int &z = x;   // x 是左值, z是左值引用
  //   int &ab = y;
  const int &z1 = 12;  // 将z1绑定到一个右值上

  foo(x);            // 传递左值给 foo 函数
  foo(y);            // 错误！y 是右值，不能绑定到左值引用
  bar(std::move(y)); // 使用 std::move 将 y 转换为右值引用，传递给 bar 函数

  return 0;
}