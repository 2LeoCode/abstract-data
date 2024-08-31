#include <memory.hxx>

namespace ft {

template <class T> allocator<T>::allocator() throw() {}

template <class T> allocator<T>::allocator(const allocator & other) throw() {
  reinterpret_cast<void>(other);
}

} // namespace ft
