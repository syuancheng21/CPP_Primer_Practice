#include <string>
#include <vector>

int main() {
  std::vector<int> v1;
  std::vector<int> v2(v1);
  std::vector<int> v3 = v1;
  std::vector<int> v4(10, 8);
  std::vector<int> v5(10);
//   std::vector<int> v6{1, 2, 3};
//   std::vector<int> v7 = {1, 2, 3};
}