#include <algorithm.hxx>

namespace ft {

template <class T> void swap(T & lhs, T & rhs) {
  T tmp(lhs);
  lhs = rhs;
  rhs = tmp;
}

template <class T, std::size_t N> void swap(T (&lhs)[N], T (&rhs)[N]) {
  swap_ranges(lhs, lhs + N, rhs);
}

} // namespace ft
