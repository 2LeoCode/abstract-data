#ifndef LIST_HXX
#define LIST_HXX

#include <cstddef>

namespace ft {

template <class T> class reverse_iterator;
template <class T> struct allocator;
struct bidirectional_iterator_tag;

template < // clang-format off
  class T, class Allocator = allocator<T>
> // clang-format on
class list {
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
  struct node {
    value_type value;
    node * next;
    node * prev;
  };
  typedef typename allocator_type::template rebind<node> node_allocator_type;

public:
  class const_iterator {
  public:
    typedef const value_type value_type;
    typedef const_reference reference;
    typedef const_pointer pointer;
    typedef difference_type difference_type;
    typedef bidirectional_iterator_tag iterator_category;

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
    friend bool
    operator==(const const_iterator & lhs, const const_iterator & rhs);
    friend bool
    operator!=(const const_iterator & lhs, const const_iterator & rhs);
    friend void swap(const_iterator & lhs, const_iterator & rhs);

  protected:
    explicit const_iterator(node * node);
    node * _node;
  };

  class iterator : public const_iterator {
  public:
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

  private:
    iterator(node * node);
  };

  list();
  explicit list(const allocator_type & alloc);
  explicit list(
      size_type count,
      const_reference value = value_type(),
      const allocator_type & alloc = allocator_type()
  );
  template <class InputIt>
  list(InputIt first, InputIt last, const allocator_type & alloc = Allocator());
  list(const list & other);
  ~list();

  void assign(size_type count, const_reference value);
  template <class InputIt> void assign(InputIt first, InputIt last);
  allocator_type get_allocator() const;
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
  void swap(list & other);
  void merge(list & other);
  template <class Compare> void merge(list & other, Compare comp);
  void splice(const_iterator pos, list & other);
  void splice(const_iterator pos, list & other, const_iterator it);
  void splice(
      const_iterator pos,
      list & other,
      const_iterator first,
      const_iterator last
  );
  void remove(const_reference value);
  template <class UnaryPredicate> void remove_if(UnaryPredicate p);
  void reverse();
  void unique();
  template <class BinaryPredicate> void unique(BinaryPredicate p);
  void sort();
  template <class Compare> void sort(Compare comp);

  list & operator=(const list & other);
  friend bool operator==(const list & lhs, const list & rhs);
  friend bool operator!=(const list & lhs, const list & rhs);
  friend bool operator<(const list & lhs, const list & rhs);
  friend bool operator<=(const list & lhs, const list & rhs);
  friend bool operator>(const list & lhs, const list & rhs);
  friend bool operator>=(const list & lhs, const list & rhs);

  friend void swap(list & lhs, list & rhs);

private:
  const node_allocator_type _alloc;
  size_type _size;
  node * _head;
  node * _tail;
};

} // namespace ft

#endif // !LIST_HXX
