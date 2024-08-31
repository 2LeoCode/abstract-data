#include <limits>
#include <memory.hxx>

namespace ft {

template <class T>
typename allocator<T>::size_type allocator<T>::max_size() const throw() {
  return std::numeric_limits<size_type>::max() / sizeof(value_type);
}

} // namespace ft
