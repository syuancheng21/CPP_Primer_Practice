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
  
  Animal *a = new Dog(); // ✅ 指针可以
  a->speak();

//   Animal *a2 = new Animal();//❌ 抽象类不能实例化
  
  return 0;
}