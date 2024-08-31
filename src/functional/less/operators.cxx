#include <functional.hxx>

namespace ft {

template <class T>
typename less<T>::result_type less<T>::operator()(
    const first_argument_type & lhs, const second_argument_type & rhs
) const {
  return lhs < rhs;
}

} // namespace ft
