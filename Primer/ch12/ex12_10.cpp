#include <iostream>
#include <memory>

void process(std::shared_ptr<int> p) {
  std::cout << "inside the process function: " << p.use_count() << "\n";
}

int main() {
  std::shared_ptr<int> p(new int(42));
  std::cout << "outside the process function: " << p.use_count() << "\n";

  //   auto p1 = std::shared_ptr<int>(p);
  //   process(p1);//3

  process(std::shared_ptr<int>(p)); // 2
  std::cout << "outside the process function: " << p.use_count() << "\n";

  return 0;
}