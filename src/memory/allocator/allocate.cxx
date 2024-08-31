#include <cstring>
#include <memory.hxx>
#include <stdint.h>

namespace ft {

template <class T>
typename allocator<T>::pointer
allocator<T>::allocate(size_type n, const void * hint) {
  (void)hint;
  uint8_t * raw = new uint8_t[sizeof(size_type) + n * sizeof(value_type)];
  std::memcpy(raw, &n, sizeof(size_type));
  return reinterpret_cast<T *>(raw + sizeof(size_type));
}

} // namespace ft
