#include <iostream>
#include <string>
#include <vector>

using std::sort;
using std::vector;

class Foo {
public:
  Foo sorted() &&;
  Foo sorted() const &;

private:
  vector<int> data;
};

Foo Foo::sorted() && {
  sort(data.begin(), data.end());
  std::cout << "&&" << std::endl; // debug

  return *this;
}

Foo Foo::sorted() const & {
  std::cout << "const &" << std::endl; // debug

  //   Foo ret(*this);
  //   sort(ret.data.begin(), ret.data.end());
  return Foo(*this).sorted();
}

int main() {
  Foo().sorted(); //&&

  Foo f;
  f.sorted(); // const
}
