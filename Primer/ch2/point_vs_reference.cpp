#include <iostream>

void increment(int *&ptr) {
  std::cout << "Increment Point: " << &ptr << std::endl;

  (*ptr)++; // 通过引用修改指针指向的值
}

void increment2(int *ptr) {
  std::cout << "Increment2 Point: " << &ptr << std::endl;
  (*ptr)++;
}

int main() {
  int x = 10;
  int *ptr = &x; // 指针指向 x

  std::cout << "Before increment: " << *ptr << std::endl;
  std::cout << "Before Increment Point: " << &ptr << std::endl;

  increment(ptr); // 传递指针的引用

  std::cout << "After increment: " << *ptr << std::endl;

  increment2(ptr); //传递指针

  std::cout << "After increment2: " << *ptr << std::endl;

  return 0;
}
