#include <iostream>

class A {
public:
  void foo(A &&other) { val(other); }

  void val(A &) { std::cout << "1" << std::endl; }
  void val(A &&) { std::cout << "2" << std::endl; }
};

int main() {
  A a, b;
  a.foo(std::move(b)); //output: 1
}