#ifndef MAP_HXX
#define MAP_HXX

namespace ft {

template <class T> struct less;
template <class T> struct allocator;
template <class T, class U> struct pair;
template <class Iter> class reverse_iterator;
template <class T, class Compare, class Allocator> class rbtree;
template <class T, class Allocator> class list;
struct bidirectional_iterator_tag;

template < // clang-format off
  class K,
  class T,
  class Compare = less<K>,
  class Allocator = allocator<
    pair<
      const K,
      T
    >
  >
> // clang-format on
class map {
public:
  class value_compare;

  typedef K key_type;
  typedef T mapped_type;
  typedef pair<const K, T> value_type;
  typedef Allocator allocator_type;
  typedef Compare key_compare;
  typedef typename rbtree<value_type, value_compare, allocator_type>::size_type
      size_type;
  typedef typename rbtree<value_type, value_compare, allocator_type>::
      difference_type difference_type;
  typedef value_type & reference;
  typedef const value_type & const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef typename rbtree<value_type, value_compare, allocator_type>::iterator
      iterator;
  typedef
      typename rbtree<value_type, value_compare, allocator_type>::const_iterator
          const_iterator;
  typedef reverse_iterator<const_iterator> const_reverse_iterator;
  typedef reverse_iterator<iterator> reverse_iterator;

  class value_compare {
  public:
    friend class map;

    typedef bool result_type;
    typedef value_type first_argument_type;
    typedef value_type second_argument_type;

    result_type operator()(
        const first_argument_type & lhs, const second_argument_type & rhs
    );

  protected:
    value_compare(const Compare & comp);
    Compare comp;
  };

  map();
  explicit map(
      const key_compare & comp, const allocator_type & alloc = allocator_type()
  );
  template <class InputIt>
  map(InputIt first,
      InputIt last,
      const key_compare & comp = key_compare(),
      const allocator_type & alloc = allocator_type());
  map(const map & other);
  ~map();

  allocator_type get_allocator() const;
  mapped_type & at(const key_type & key);
  const mapped_type & at(const key_type & key) const;
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
  pair<iterator, bool> insert(const value_type & value);
  iterator insert(iterator pos, const value_type & value);
  template <class InputIt> iterator insert(InputIt first, InputIt last);
  iterator erase(iterator pos);
  size_type erase(const key_type & key);
  void swap(map & other);
  size_type count(const key_type & key) const;
  iterator find(const key_type & key);
  const_iterator find(const key_type & key) const;
  pair<iterator, iterator> equal_range(const key_type & key);
  pair<const_iterator, const_iterator> equal_range(const key_type & key) const;
  iterator lower_bound(const key_type & key);
  const_iterator lower_bound(const key_type & key) const;
  iterator upper_bound(const key_type & key);
  const_iterator upper_bound(const key_type & key) const;
  key_compare key_comp() const;
  value_compare value_comp() const;

  map & operator=(const map & other);
  friend bool operator==(const map & lhs, const map & rhs);
  friend bool operator!=(const map & lhs, const map & rhs);
  friend bool operator>(const map & lhs, const map & rhs);
  friend bool operator>=(const map & lhs, const map & rhs);
  friend bool operator<(const map & lhs, const map & rhs);
  friend bool operator<=(const map & lhs, const map & rhs);
  friend void swap(map & lhs, map & rhs);

private:
  rbtree<value_type, value_compare, allocator_type> _tree;
};

template < // clang-format off
  class K,
  class T,
  class Compare = less<K>,
  class Allocator = allocator<
    pair<
      const K,
      T
    >
  >
> // clang-format on
class multimap {
public:
  class value_compare;
  class iterator;
  class const_iterator;

  typedef K key_type;
  typedef T mapped_type;
  typedef pair<const K, T> value_type;
  typedef Allocator allocator_type;
  typedef Compare key_compare;
  typedef typename rbtree<value_type, value_compare, allocator_type>::size_type
      size_type;
  typedef typename rbtree<value_type, value_compare, allocator_type>::
      difference_type difference_type;
  typedef value_type & reference;
  typedef const value_type & const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef reverse_iterator<const_iterator> const_reverse_iterator;
  typedef reverse_iterator<iterator> reverse_iterator;

  class value_compare {
  public:
    friend class multimap;

    typedef bool result_type;
    typedef value_type first_argument_type;
    typedef value_type second_argument_type;

    result_type operator()(
        const first_argument_type & lhs, const second_argument_type & rhs
    );

  protected:
    value_compare(const Compare & comp);
    Compare comp;
  };

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

  private:
    typedef typename rbtree<
        list<value_type, allocator_type>,
        value_compare,
        allocator_type>::iterator rbtree_iterator;
    typedef typename list<value_type, allocator_type>::iterator
        rbtree_node_iterator;

  protected:
    const_iterator(
        const rbtree_iterator & treeIter, const rbtree_node_iterator & nodeIter
    );

    rbtree_iterator _treeIter;
    rbtree_node_iterator _nodeIter;
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
    typedef typename const_iterator::rbtree_iterator rbtree_iterator;
    typedef typename const_iterator::rbtree_node_iterator rbtree_node_iterator;

    iterator(
        const rbtree_iterator & treeIter, const rbtree_node_iterator & nodeIter
    );
  };

  multimap();
  explicit multimap(
      const key_compare & comp, const allocator_type & alloc = allocator_type()
  );
  template <class InputIt>
  multimap(
      InputIt first,
      InputIt last,
      const key_compare & comp = key_compare(),
      const allocator_type & alloc = allocator_type()
  );
  multimap(const multimap & other);
  ~multimap();

  allocator_type get_allocator() const;
  mapped_type & at(const key_type & key);
  const mapped_type & at(const key_type & key) const;
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
  pair<iterator, bool> insert(const value_type & value);
  iterator insert(iterator pos, const value_type & value);
  template <class InputIt> iterator insert(InputIt first, InputIt last);
  iterator erase(iterator pos);
  size_type erase(const key_type & key);
  void swap(multimap & other);
  size_type count(const key_type & key) const;
  iterator find(const key_type & key);
  const_iterator find(const key_type & key) const;
  pair<iterator, iterator> equal_range(const key_type & key);
  pair<const_iterator, const_iterator> equal_range(const key_type & key) const;
  iterator lower_bound(const key_type & key);
  const_iterator lower_bound(const key_type & key) const;
  iterator upper_bound(const key_type & key);
  const_iterator upper_bound(const key_type & key) const;
  key_compare key_comp() const;
  value_compare value_comp() const;

  multimap & operator=(const multimap & other);
  friend bool operator==(const multimap & lhs, const multimap & rhs);
  friend bool operator!=(const multimap & lhs, const multimap & rhs);
  friend bool operator>(const multimap & lhs, const multimap & rhs);
  friend bool operator>=(const multimap & lhs, const multimap & rhs);
  friend bool operator<(const multimap & lhs, const multimap & rhs);
  friend bool operator<=(const multimap & lhs, const multimap & rhs);
  friend void swap(multimap & lhs, multimap & rhs);

private:
  size_type _size;
  rbtree<list<value_type, allocator_type>, value_compare, allocator_type> _tree;
};

} // namespace ft

#endif // !MAP_HXX
