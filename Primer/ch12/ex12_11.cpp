#include <iostream>
#include <memory>

void process(std::shared_ptr<int> p) {
  std::cout << "inside the process function: " << p.use_count() << "\n";
}

int main() {
  std::shared_ptr<int> p(new int(42));
  std::cout << "outside the process function: " << p.use_count() << "\n";

  process(std::shared_ptr<int>(p.get()));
  std::cout << "outside the process function: " << p.use_count() << "\n";

  return 0;
}