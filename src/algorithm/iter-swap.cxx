#include <algorithm.hxx>

namespace ft {

template <class ForwardIt1, class ForwardIt2>
void iter_swap(ForwardIt1 lhs, ForwardIt2 rhs) {
  swap(*lhs, *rhs);
}

} // namespace ft
