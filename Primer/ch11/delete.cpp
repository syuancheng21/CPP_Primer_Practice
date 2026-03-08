#include <cstddef>
#include <map>
#include <string>
#include <utility>

int main() {

  std::map<std::string, size_t> word_count;
  word_count.insert(std::make_pair("He", 2));
  word_count.insert(std::pair<std::string, size_t>("She", 3));
  word_count.insert(std::map<std::string, size_t>::value_type("They", 4));

  // earse
  word_count.erase("He");
  word_count.erase(word_count.begin());
  word_count.erase(word_count.begin(), word_count.end());
  return 0;
}