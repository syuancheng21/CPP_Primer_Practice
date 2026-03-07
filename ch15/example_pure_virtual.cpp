#include <iostream>

using namespace std;

class Animal {
public:
  virtual void speak() = 0;
};

class Dog : public Animal {
public:
  void speak() override { cout << "Dog speak" << endl; }
};

int main() {
  //   Animal a;  //❌ 抽象类不能实例化
  Animal *a = new Dog(); // ✅ 指针可以
  a->speak();
  return 0;
}