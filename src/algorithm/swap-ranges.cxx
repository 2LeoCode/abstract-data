#include <algorithm.hxx>

namespace ft {

template <class ForwardIt1, class ForwardIt2>
ForwardIt2 swap_ranges(ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2) {
  for (; first1 != last1; ++first1, ++first2)
    iter_swap(first1, first2);
  return first2;
}

} // namespace ft
