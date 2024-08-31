#include <memory.hxx>
#include <stdexcept>
#include <stdint.h>

namespace ft {

template <class T> void allocator<T>::deallocate(pointer p, size_type n) {
  uint8_t * raw = reinterpret_cast<uint8_t *>(p) - sizeof(size_type);
  const size_type blockSize = *reinterpret_cast<size_type *>(raw);

  if (n != blockSize)
    throw std::invalid_argument(
        "`n` is not equal to the original size passed to `allocate`"
    );
  delete[] raw;
}

} // namespace ft
