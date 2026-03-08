#include <algorithm>
#include <vector>
class Foo {
public:
  Foo sorted() &&;
  Foo sorted() const &;

private:
  std::vector<int> data;
};

//右值，因此可以原址排序
Foo Foo::sorted() && {
  std::sort(data.begin(), data.end());
  return *this;
}
//是const或左值，不能进行原址排序
Foo Foo::sorted() const & {
  Foo ret(*this);
  std::sort(ret.data.begin(), ret.data.end());
  return ret;
}