#include <iostream>
#include <map>
#include <unordered_map>
using namespace ::std;

int main() {

  //   std::unordered_map<std::string, size_t> cardtype2head;
  //   size_t head = cardtype2head["ads"];
  //   cout << "opt: " << head << endl;

  std::map<int, std::string> myMap;

  // 插入一些键值对
  myMap[1] = "Value1";
  myMap[2] = "Value2";
  myMap[3] = "Value3";
  myMap[4] = "Value4";

  for (auto &[key, value] : myMap) {
    switch (key) {
    case 1:
      cout << value << endl;
      continue;
    case 2:
      cout << value << endl;
      continue;
    case 3:
      cout << value << endl;
      continue;
    default:
      cout << "default" << endl;
    }
  }

  cout << "=====" << endl;

  for (auto &[key, value] : myMap) {
    int i = 0;
    while (i < 10) {
      if (i > 3) {
        break;
      }
      i++;
    }
    cout << "after k: " << key << " v: " << value << endl;
  }

  return 0;
}