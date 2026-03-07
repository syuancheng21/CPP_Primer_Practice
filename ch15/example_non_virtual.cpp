#include <iostream>

using namespace std;

class Animal {
public:
  void breathe() { cout << "Animal breathe" << endl; }
};

class Dog : public Animal {
public:
  void breathe() { // 隐藏父类，不是覆盖
    cout << "Dog breathe" << endl;
  }
};

int main() {
  // 看指针类型

  Animal *a = new Dog(); // Animal breathe
  a->breathe();

  Animal *a2 = new Animal();
  a2->breathe(); // Animal breathe

  Dog *d = new Dog();
  d->breathe(); // Dog breathe
}