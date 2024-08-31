#include <memory.hxx>

namespace ft {

template <class T> void allocator<T>::destroy(pointer p) { p->~value_type(); }

} // namespace ft
