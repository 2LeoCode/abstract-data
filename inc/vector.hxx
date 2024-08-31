#ifndef VECTOR_HXX
#define VECTOR_HXX

#include <cstddef>
#include <stdint.h>

namespace ft {

template <class T> struct allocator;
template <class T> class reverse_iterator;
struct random_access_iterator_tag;

template < // clang-format off
  class T, class Allocator = allocator<T>
> // clang-format on
class vector {
public:
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;
  typedef T & reference;
  typedef const T & const_reference;
  typedef typename Allocator::pointer pointer;
  typedef typename Allocator::const_pointer const_pointer;
  typedef T * iterator;
  typedef const T * const_iterator;
  typedef reverse_iterator<const_iterator> const_reverse_iterator;
  typedef reverse_iterator<iterator> reverse_iterator;

  vector();
  explicit vector(const allocator_type & alloc);
  explicit vector(
      size_type count,
      const_reference value = value_type(),
      const allocator_type & alloc = allocator_type()
  );
  template <class InputIt>
  vector(
      InputIt first,
      InputIt last,
      const allocator_type & alloc = allocator_type()
  );
  vector(const vector & other);
  ~vector();

  void assign(size_type count, const_reference value);
  template <class InputIt> void assign(InputIt first, InputIt last);
  allocator_type get_allocator() const;
  reference at(size_type pos);
  const_reference at(size_type pos) const;
  reference front();
  const_reference front() const;
  reference back();
  const_reference back() const;
  pointer data();
  const_pointer data() const;
  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;
  reverse_iterator rbegin();
  const_reverse_iterator rbegin() const;
  reverse_iterator rend();
  const_reverse_iterator rend() const;
  bool empty() const;
  size_type size() const;
  size_type max_size() const;
  void reserve(size_type newCap);
  size_type capacity() const;
  void shrink_to_fit();
  void clear();
  iterator insert(const_iterator pos, const_reference value);
  iterator insert(const_iterator pos, size_type count, const_reference value);
  template <class InputIt>
  iterator insert(const_iterator pos, InputIt first, InputIt last);
  iterator erase(iterator pos);
  iterator erase(iterator first, iterator last);
  void push_back(const_reference value);
  void pop_back();
  void resize(size_type count);
  void resize(size_type count, const_reference value);
  void swap(vector & other);

  vector & operator=(const vector & other);
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  friend bool operator==(const vector & lhs, const vector & rhs);
  friend bool operator!=(const vector & lhs, const vector & rhs);
  friend bool operator<(const vector & lhs, const vector & rhs);
  friend bool operator<=(const vector & lhs, const vector & rhs);
  friend bool operator>(const vector & lhs, const vector & rhs);
  friend bool operator>=(const vector & lhs, const vector & rhs);

  friend void swap(vector & lhs, vector & rhs);

private:
  pointer _data;
  size_type _size;
  size_type _capacity;
};

template <class Allocator> struct vector<bool, Allocator> {
  class reference;
  class pointer;
  class iterator;
  class const_iterator;

  typedef bool value_type;
  typedef Allocator allocator_type;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;
  typedef bool const_reference;
  typedef const bool * const_pointer;
  typedef reverse_iterator<const_iterator> const_reverse_iterator;
  typedef reverse_iterator<iterator> reverse_iterator;

  class reference {
  public:
    friend struct vector<bool, Allocator>;

    ~reference();

    void flip();

    reference & operator=(const reference & other);
    reference & operator=(bool x);
    pointer operator&();
    const_pointer operator&() const;
    operator bool() const;

  private:
    reference(uint64_t * begin, size_type bit);

    uint64_t * begin;
    uint8_t bit;
  };

  class pointer {
  public:
    friend struct vector<bool, Allocator>;

    ~pointer();

    pointer & operator=(const pointer & other);
    reference operator*();
    const_reference operator*() const;
    reference * operator->();
    const_reference * operator->() const;
    pointer & operator++();
    pointer operator++(int);
    pointer & operator--();
    pointer operator--(int);
    pointer & operator+=(difference_type n);
    pointer & operator-=(difference_type n);
    friend pointer operator+(pointer & it, difference_type n);
    friend pointer operator+(difference_type n, pointer & it);
    friend pointer operator-(pointer & it, difference_type n);
    friend pointer operator-(difference_type n, pointer & it);
    friend bool operator==(const pointer & lhs, const pointer & rhs);
    friend bool operator!=(const pointer & lhs, const pointer & rhs);
    friend bool operator<(const pointer & lhs, const pointer & rhs);
    friend bool operator<=(const pointer & lhs, const pointer & rhs);
    friend bool operator>(const pointer & lhs, const pointer & rhs);
    friend bool operator>=(const pointer & lhs, const pointer & rhs);

    friend void swap(pointer & lhs, pointer & rhs);

  private:
    explicit pointer(uint64_t * begin, size_type bit);
    explicit pointer(const reference & ref);

    reference _ref;
  };

  class const_iterator {
  public:
    friend class vector<bool, Allocator>;

    typedef value_type const value_type;
    typedef reference const_reference;
    typedef pointer const_pointer;
    typedef difference_type difference_type;
    typedef random_access_iterator_tag iterator_category;

    const_iterator();
    const_iterator(const const_iterator & other);
    const_iterator(const iterator & other);
    ~const_iterator();

    const_iterator & operator=(const const_iterator & other);
    const_iterator & operator=(const iterator & other);
    reference operator*() const;
    pointer operator->() const;
    const_iterator & operator++();
    const_iterator operator++(int);
    const_iterator & operator--();
    const_iterator operator--(int);
    const_iterator & operator+=(difference_type n);
    const_iterator & operator-=(difference_type n);
    friend const_iterator operator+(const_iterator & it, difference_type n);
    friend const_iterator operator+(difference_type n, const_iterator & it);
    friend const_iterator operator-(const_iterator & it, difference_type n);
    friend const_iterator operator-(difference_type n, const_iterator & it);
    friend bool
    operator==(const const_iterator & lhs, const const_iterator & rhs);
    friend bool
    operator!=(const const_iterator & lhs, const const_iterator & rhs);
    friend bool
    operator<(const const_iterator & lhs, const const_iterator & rhs);
    friend bool
    operator<=(const const_iterator & lhs, const const_iterator & rhs);
    friend bool
    operator>(const const_iterator & lhs, const const_iterator & rhs);
    friend bool
    operator>=(const const_iterator & lhs, const const_iterator & rhs);

    friend void swap(const_iterator & lhs, const_iterator & rhs);

  protected:
    const_iterator(uint64_t * begin, size_type bit);
    const_iterator(const reference & ref);

    reference _ref;
  };

  class iterator : public const_iterator {
  public:
    friend class vector<bool, Allocator>;

    typedef value_type value_type;
    typedef reference reference;
    typedef pointer pointer;

    iterator();
    iterator(const iterator & other);
    ~iterator();

    iterator & operator=(const iterator & other);
    reference operator*();
    pointer operator->();
    iterator & operator++();
    iterator operator++(int);
    iterator & operator--();
    iterator operator--(int);
    iterator & operator+=(difference_type n);
    iterator & operator-=(difference_type n);
    friend iterator operator+(iterator & it, difference_type n);
    friend iterator operator+(difference_type n, iterator & it);
    friend iterator operator-(iterator & it, difference_type n);
    friend iterator operator-(difference_type n, iterator & it);

  private:
    iterator(uint64_t * begin, size_type bit);
    iterator(const reference & ref);
  };

  vector();
  explicit vector(const allocator_type & alloc);
  explicit vector(
      size_type count,
      const_reference value = value_type(),
      const allocator_type & alloc = allocator_type()
  );
  template <class InputIt>
  vector(
      InputIt first,
      InputIt last,
      const allocator_type & alloc = allocator_type()
  );
  vector(const vector & other);
  ~vector();

  void assign(size_type count, const_reference value);
  template <class InputIt> void assign(InputIt first, InputIt last);
  allocator_type get_allocator() const;
  reference at(size_type pos);
  const_reference at(size_type pos) const;
  reference front();
  const_reference front() const;
  reference back();
  const_reference back() const;
  pointer data();
  const_pointer data() const;
  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;
  reverse_iterator rbegin();
  const_reverse_iterator rbegin() const;
  reverse_iterator rend();
  const_reverse_iterator rend() const;
  bool empty() const;
  size_type size() const;
  size_type max_size() const;
  void reserve(size_type newCap);
  size_type capacity() const;
  void shrink_to_fit();
  void clear();
  iterator insert(const_iterator pos, const_reference value);
  iterator insert(const_iterator pos, size_type count, const_reference value);
  template <class InputIt>
  iterator insert(const_iterator pos, InputIt first, InputIt last);
  iterator erase(iterator pos);
  iterator erase(iterator first, iterator last);
  void push_back(const_reference value);
  void pop_back();
  void resize(size_type count);
  void resize(size_type count, const_reference value);
  void swap(vector & other);

  void flip();
  static void swap(reference lhs, reference rhs);

  vector & operator=(const vector & other);
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  friend bool operator==(const vector & lhs, const vector & rhs);
  friend bool operator!=(const vector & lhs, const vector & rhs);
  friend bool operator<(const vector & lhs, const vector & rhs);
  friend bool operator<=(const vector & lhs, const vector & rhs);
  friend bool operator>(const vector & lhs, const vector & rhs);
  friend bool operator>=(const vector & lhs, const vector & rhs);

  friend void swap(vector & lhs, vector & rhs);

private:
  uint64_t * _data;
  value_type * _begin;
  value_type * _end;
  size_type _size;
};

} // namespace ft

#endif // !VECTOR_HXX
