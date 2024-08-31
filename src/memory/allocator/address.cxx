#include <memory.hxx>

namespace ft {

template <class T>
typename allocator<T>::pointer allocator<T>::address(reference x) const {
  return addressof(x);
}

template <class T>
typename allocator<T>::const_pointer allocator<T>::address(const_reference x
) const {
  return addressof(x);
}

} // namespace ft
