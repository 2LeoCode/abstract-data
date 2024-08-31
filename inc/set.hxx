#ifndef SET_HXX
#define SET_HXX

namespace ft {

template <class T> struct allocator;
template <class T> struct less;
template <class First, class Second> struct pair;
template <class T, class Compare, class Allocator> class rbtree;
template <class Iter> class reverse_iterator;
template <class T, class Allocator> class list;

template < // clang-format off
  class Key,
  class Compare = less<Key>,
  class Allocator = allocator<Key>
> // clang-format on
class set {
public:
  typedef Key key_type;
  typedef Key value_type;
  typedef Compare key_compare;
  typedef Compare value_compare;
  typedef Allocator allocator_type;
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

  set();
  explicit set(
      const value_compare & comp,
      const allocator_type & alloc = allocator_type()
  );
  template <class InputIt>
  set(InputIt first,
      InputIt last,
      const value_compare & comp = value_compare(),
      const allocator_type & alloc = allocator_type());
  set(const set & other);
  ~set();

  allocator_type get_allocator() const;
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
  template <class InputIt> void insert(InputIt first, InputIt last);
  iterator erase(iterator pos);
  size_type erase(const key_type & key);
  void swap(set & other);
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

  set & operator=(const set & other);
  friend bool operator==(const set & lhs, const set & rhs);
  friend bool operator!=(const set & lhs, const set & rhs);
  friend bool operator>(const set & lhs, const set & rhs);
  friend bool operator>=(const set & lhs, const set & rhs);
  friend bool operator<(const set & lhs, const set & rhs);
  friend bool operator<=(const set & lhs, const set & rhs);
  friend void swap(set & lhs, set & rhs);

private:
  rbtree<value_type, value_compare, allocator_type> _tree;
};

template < // clang-format off
  class Key,
  class Compare = less<Key>,
  class Allocator = allocator<Key>
> // clang-format on
class multiset {
public:
  typedef Key key_type;
  typedef Key value_type;
  typedef Compare key_compare;
  typedef Compare value_compare;
  typedef Allocator allocator_type;
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

  multiset();
  explicit multiset(
      const value_compare & comp,
      const allocator_type & alloc = allocator_type()
  );
  template <class InputIt>
  multiset(
      InputIt first,
      InputIt last,
      const value_compare & comp = value_compare(),
      const allocator_type & alloc = allocator_type()
  );
  multiset(const multiset & other);
  ~multiset();

  allocator_type get_allocator() const;
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
  template <class InputIt> void insert(InputIt first, InputIt last);
  iterator erase(iterator pos);
  size_type erase(const key_type & key);
  void swap(multiset & other);
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

  multiset & operator=(const multiset & other);
  friend bool operator==(const multiset & lhs, const multiset & rhs);
  friend bool operator!=(const multiset & lhs, const multiset & rhs);
  friend bool operator>(const multiset & lhs, const multiset & rhs);
  friend bool operator>=(const multiset & lhs, const multiset & rhs);
  friend bool operator<(const multiset & lhs, const multiset & rhs);
  friend bool operator<=(const multiset & lhs, const multiset & rhs);
  friend void swap(multiset & lhs, multiset & rhs);

private:
  size_type _size;
  rbtree<list<value_type, allocator_type>, value_compare, allocator_type> _tree;
};

} // namespace ft

#endif // !SET_HXX
