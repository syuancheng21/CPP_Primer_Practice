#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  // empty container
  map<string, size_t> word_count;

  // list init
  set<string> exclude = {"the", "but", "else"};

  //
  map<string, string> authors = {{"Joyce", "James"}, {"Austen", "Jane"}};

  // init pair
  pair<string, string> author{"James", "Joyce"};
  pair<string, string> p("James", "James");
  pair<string, string> p1 = {"R", "v"};
  auto p2 = make_pair("x", "y");

  return 0;
}

pair<string, int> process(vector<string> &v) {
  if (!v.empty()) {
    return {v.back(), v.back().size()};
  } else {
    return pair<string, int>();
  }
}