#include <memory.hxx>

namespace ft {

template <class T> T * addressof(T & arg) throw() {
  return reinterpret_cast<T *>(
      &const_cast<char &>(reinterpret_cast<const volatile char &>(arg))
  );
}

} // namespace ft
