#ifndef D41758A6_CAEB_4B23_AF9D_C04FA89C2695
#define D41758A6_CAEB_4B23_AF9D_C04FA89C2695

#include <memory>
class String {
public:
  String() = default;
  String(const char *);
  String(const String &);
  //   String(String &&) NOEXCEPT;
  String &operator=(const String &);

  // TODO: add rvalue func

  ~String();
  const char *c_str() const { return elements; }
  size_t size() const { return end - elements; }
  size_t length() const { return end - elements - 1; }

public:
  char *first() const { return elements; }
  char *last() const { return end; }

private:
  std::pair<char *, char *> alloc_n_copy(const char *, const char *);
  void range_initializer(const char *, const char *);
  void free();

private:
  char *elements;
  char *end;
  std::allocator<char> alloc;
};

#endif /* D41758A6_CAEB_4B23_AF9D_C04FA89C2695 */
