#include <iostream>
#include <utility> // for std::move

class MyClass {
public:
  // 默认构造函数
//   MyClass() : _data(nullptr) { std::cout << "Default Constructor" << std::endl; }

  // 构造函数
  MyClass(int size) : _data(new int[size]), _size(size) {
    std::cout << "Constructor" << std::endl;
  }

  // 拷贝构造函数
  MyClass(const MyClass &other) : data(new int[other.size]), size(other.size) {
    std::cout << "Copy Constructor" << std::endl;
    std::copy(other.data, other.data + size, data);
  }

  // 移动构造函数
  MyClass(MyClass &&other) noexcept : data(other.data), size(other.size) {
    std::cout << "Move Constructor" << std::endl;
    other.data = nullptr; // 释放资源
    other.size = 0;
  }

  // 拷贝赋值运算符
  MyClass &operator=(const MyClass &other) {
    std::cout << "Copy Assignment" << std::endl;
    if (this != &other) {
      delete[] data; // 清理旧资源

      data = new int[other.size];
      size = other.size;
      std::copy(other.data, other.data + size, data);
    }
    return *this;
  }

  // 移动赋值运算符
  MyClass &operator=(MyClass &&other) noexcept {
    std::cout << "Move Assignment" << std::endl;
    if (this != &other) {
      delete[] data; // 清理旧资源

      data = other.data;
      size = other.size;

      other.data = nullptr; // 释放资源
      other.size = 0;
    }
    return *this;
  }

  // 析构函数
  ~MyClass() {
    std::cout << "Destructor" << std::endl;
    delete[] data;
  }

private:
  int *_data;
  int _size;
};

int main() {
  MyClass a(10);            // 调用构造函数
  MyClass b = std::move(a); // 调用移动构造函数

  MyClass c;
  c = std::move(b); // 调用移动赋值运算符

  return 0;
}
