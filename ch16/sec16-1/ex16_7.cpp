

template <typename T, unsigned N> constexpr unsigned size(T (&arr)[N]) {
  return N;
}