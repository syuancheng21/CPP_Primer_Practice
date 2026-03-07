#include <iostream>

using namespace std;

class Animal {
public:
  virtual void speak() { cout << "Animal speak" << endl; }
};

class Dog : public Animal {
public:
  void speak() override { // 覆盖父类
    cout << "Dog speak" << endl;
  }
};

class Cat : public Animal {
  // 不覆盖，使用父类默认实现
};

int main() {
  Animal *a = new Dog();
  a->speak(); // Dog speak, 看实际对象类型。运行时多态，子类可选择是否覆盖

  Animal *a1 = new Cat();
  a1->speak(); // 输出 "Animal speak" ✅

  return 0;
}