#include <memory.hxx>

namespace ft {

template <class T>
void allocator<T>::construct(pointer p, const_reference val) {
  new (p) value_type(val);
}

} // namespace ft
