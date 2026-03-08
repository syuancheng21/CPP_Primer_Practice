#ifndef E9EE7B36_54AA_4505_9B5D_3D0284A7ED91
#define E9EE7B36_54AA_4505_9B5D_3D0284A7ED91

#include <cstddef>
#include <initializer_list>
#include <memory>
#include <string>
#include <utility>

class StrVec {
public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  StrVec(const StrVec &);
  StrVec &operator=(const StrVec &);
  StrVec(StrVec &&s) noexcept
      : elements(s.elements), first_free(s.first_free), cap(s.cap) {
    s.elements = s.first_free = s.cap = nullptr_t;
      }
  StrVec &operator=(StrVec &&);

  ~StrVec();

public:
  void push_back(const std::string &);
  void push_back(std::string &&);
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }
  std::string *begin() const { return elements; }
  std::string *end() const { return first_free; }

private:
  static std::allocator<std::string> alloc;
  void chk_n_alloc() {
    if (size() == capacity()) {
      reallocate();
    }
  }

  std::pair<std::string *, std::string *> alloc_n_copy(const std::string *,
                                                       const std::string *);

  void free();
  void reallocate();
  std::string *elements;
  std::string *first_free;
  std::string *cap;
};

#endif /* E9EE7B36_54AA_4505_9B5D_3D0284A7ED91 */
