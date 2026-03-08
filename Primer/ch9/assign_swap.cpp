#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main() {
  std::vector<int> v(5, 3);
  std::vector<int> p(5, 6);

  auto &pv = v[0];

  auto iter = v.begin();

  std::cout << "before: " << *iter << std::endl; // 3
  std::cout << "before2: " << pv << std::endl;   // 3

    v.swap(p);
    std::cout << "after: " << *iter << std::endl; // 3  指向容器的迭代器，引用和指针在swap后不会失效，还是3.
    std::cout << "after1: " << *v.begin() << std::endl; // 6
    std::cout << "after2: " << pv << std::endl;  //3

//   v = p;
//   std::cout << "after: " << *iter << std::endl;       // 6
//   std::cout << "after1: " << *v.begin() << std::endl; // 6
//   std::cout << "after2: " << pv << std::endl;         // 6

  return 0;
}