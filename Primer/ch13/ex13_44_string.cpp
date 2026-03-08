#include "ex13_44_string.h"
#include <memory>
#include <utility>

std::pair<char *, char *> String::alloc_n_copy(const char *b, const char *e) {
  auto newstart = alloc.allocate(e - b);
  return std::make_pair(newstart, std::uninitialized_copy(b, e, newstart));
}

void String::range_initializer(const char *first, const char *last) {
  auto newstr = alloc_n_copy(first, last);
  elements = newstr.first;
  end = newstr.second;
}

void String::free() {
  if (elements) {
    for (auto p = end; p != elements;) {
      alloc.destroy(--p);
    }
    alloc.deallocate(elements, end - elements);
  }
}

String::~String() { free(); }

String::String(const char *s) {
  char *sl = const_cast<char *>(s);
  while (*sl)
    ++sl;
  range_initializer(s, ++sl);
}

String::String(const String &s) { range_initializer(s.first(), s.last()); }

String &String::operator=(const String &rhs) {
  auto data = alloc_n_copy(rhs.first(), rhs.last());
  free();
  elements = data.first;
  end = data.second;
  return *this;
}
