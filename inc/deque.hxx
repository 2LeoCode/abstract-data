#ifndef DEQUE_HXX
#define DEQUE_HXX

#include <cstddef>

#define DEQUE_MIN_CHUNK_SIZE 4096
#define DEQUE_MIN_ELEMS_PER_CHUNK 16

#define DEQUE_CHUNK_SIZE(T)                                                    \
 (DEQUE_MIN_ELEMS_PER_CHUNK * sizeof(T) < DEQUE_MIN_CHUNK_SIZE                 \
      ? DEQUE_MIN_ELEMS_PER_CHUNK                                              \
      : DEQUE_MIN_CHUNK_SIZE / sizeof(T))

namespace ft {

template <class T> struct allocator;
template <class T> struct reverse_iterator;
template <class T, class Allocator> class list;
struct random_access_iterator_tag;

template < // clang-format off
  class T, class Allocator = allocator<T>
> // clang-format on
class deque {
public:
  class iterator;
  class const_iterator;

  typedef T value_type;
  typedef Allocator allocator_type;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;
  typedef T & reference;
  typedef const T & const_reference;
  typedef typename Allocator::pointer pointer;
  typedef typename Allocator::const_pointer const_pointer;
  typedef reverse_iterator<const_iterator> const_reverse_iterator;
  typedef reverse_iterator<iterator> reverse_iterator;

private:
  struct chunk {
    T data[DEQUE_CHUNK_SIZE(T)];
  };

  typedef typename allocator_type::template rebind<chunk> chunk_allocator_type;

public:
  class const_iterator {
  public:
    friend class deque;

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

  private:
    typedef typename list<chunk, chunk_allocator_type>::iterator chunk_iterator;

  protected:
    explicit const_iterator(
        const chunk_iterator & chunk, const pointer & cursor
    );
    chunk_iterator _chunk;
    pointer _cursor;
  };

  class iterator : public const_iterator {
  public:
    friend class deque;

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
    typedef typename const_iterator::chunk_iterator chunk_iterator;

    iterator(const chunk_iterator & chunk, pointer cursor);
  };

  deque();
  explicit deque(const allocator_type & alloc);
  explicit deque(
      size_type count,
      const_reference value = value_type(),
      const allocator_type & alloc = allocator_type()
  );
  template <class InputIt>
  deque(InputIt first, InputIt last, const allocator_type & alloc);
  deque(const deque & other);
  ~deque();

  void assign(size_type count, const_reference value);
  template <class InputIt> void assign(InputIt first, InputIt last);
  allocator_type get_allocator() const;
  reference at(size_type pos);
  const_reference at(size_type pos) const;
  reference front();
  const_reference front() const;
  reference back();
  const_reference back() const;
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
  void push_front(const_reference value);
  void pop_front();
  void resize(size_type count);
  void resize(size_type count, const_reference value);
  void swap(deque & other);

  deque & operator=(const deque & other);
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  friend bool operator==(const deque & lhs, const deque & rhs);
  friend bool operator!=(const deque & lhs, const deque & rhs);
  friend bool operator<(const deque & lhs, const deque & rhs);
  friend bool operator<=(const deque & lhs, const deque & rhs);
  friend bool operator>(const deque & lhs, const deque & rhs);
  friend bool operator>=(const deque & lhs, const deque & rhs);

  friend void swap(deque & lhs, deque & rhs);

private:
  list<chunk, chunk_allocator_type> _data;
  value_type * _begin;
  value_type * _end;
  size_type _size;
};

} // namespace ft

#endif // !DEQUE_HXX
