#include <iostream>
#include <utility>
using namespace std;

struct X {
  X() { cout << "constructor X()" << endl; }
  X(const X &) { cout << "copy constructor X(const X&)" << endl; }

  X &operator=(const X &rhs) {
    cout << "copy assigning operator =(const X&)" << endl;
    return *this;
  }
  ~X() { cout << "destructor ~X()" << endl; }
};

void f1(X x) {}

void f2(X &x) {}

int main() {

  std::cout << "局部变量： " << std::endl;
  X x;
  cout << endl;

  cout << "非引用参数传递：" << endl;
  f1(x);
  cout << endl;

  cout << "引用参数传递：" << endl;
  f2(x);
  cout << endl;

  cout << "动态分配：" << endl;
  X *px = new X;
  cout << endl;

  cout << "添加到容器中：" << endl;
  vector<X> vx;
  vx.push_back(x);
  cout << endl;

  cout << "添加到容器中with move："
       << endl; // 没定义移动构造函数的话，还会回退到拷贝构造
  vector<X> mx;
  mx.push_back(std::move(x));
  cout << endl;

  cout << "释放动态分配对象：" << endl;
  delete px;
  cout << endl;

  cout << "间接初始化和赋值：" << endl;
  X y = x;
  cout << endl;

  cout << "程序结束：" << endl;
  return 0;
}