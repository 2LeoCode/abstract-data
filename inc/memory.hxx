#ifndef MEMORY_HXX
#define MEMORY_HXX

#include <cstddef>

namespace ft {

template <class T> struct allocator {
  typedef T value_type;
  typedef T * pointer;
  typedef const T * const_pointer;
  typedef T & reference;
  typedef const T & const_reference;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;

  template <class U> struct rebind { typedef allocator<U> other; };

  allocator() throw();
  allocator(const allocator & other) throw();

  ~allocator();

  pointer address(reference x) const;
  const_pointer address(const_reference x) const;
  pointer allocate(size_type n, const void * hint = NULL);
  void deallocate(pointer p, size_type n);
  size_type max_size() const throw();
  void construct(pointer p, const_reference val);
  void destroy(pointer p);
};

template <> struct allocator<void> {
  typedef void value_type;
  typedef void * pointer;
  typedef const void * const_pointer;

  template <class U> struct rebind { typedef allocator<U> other; };
};

template <class T> T * addressof(T & arg) throw();

} // namespace ft

#endif // !MEMORY_HXX
