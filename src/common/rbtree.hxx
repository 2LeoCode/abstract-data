#ifndef RBTREE_HXX
#define RBTREE_HXX

#include <algorithm>
#include <cstddef>

namespace ft {

template <class Iter> class reverse_iterator;
template <class First, class Second> struct pair;
struct bidirectional_iterator_tag;

template < // clang-format off
  class T,
  class Compare,
  class Allocator
> // clang-format on
class rbtree {
public:
  class iterator;
  class const_iterator;

  typedef T value_type;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;
  typedef Compare value_compare;
  typedef T & reference;
  typedef const T & const_reference;
  typedef typename Allocator::pointer pointer;
  typedef typename Allocator::const_pointer const_pointer;
  typedef Allocator allocator_type;
  typedef reverse_iterator<const_iterator> const_reverse_iterator;
  typedef reverse_iterator<iterator> reverse_iterator;

private:
  enum color { BLACK = false, RED = true };
  struct node {
    value_type value;
    color color;
    node * parent;
    node * left;
    node * right;

    node(node * parent);
    node(const node & other);
    ~node();

    node * sibling();
    const node * sibling() const;
    void rotateRight();
    void rotateLeft();

    node & operator=(const node & other);
    friend bool operator==(const node & lhs, const node & rhs);
    friend bool operator!=(const node & lhs, const node & rhs);
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
    friend void std::swap(const_iterator & lhs, const_iterator & rhs);

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
  rbtree(const value_compare & comp, const allocator_type & alloc);
  rbtree(const rbtree & other);
  template <class InputIt>
  rbtree(
      InputIt first,
      InputIt last,
      const value_compare & comp,
      const allocator_type & alloc
  );
  ~rbtree();

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
  void swap(rbtree & other);
  size_type count(const value_type & value) const;
  iterator find(const value_type & value);
  const_iterator find(const value_type & value) const;
  pair<iterator, iterator> equal_range(const value_type & value);
  pair<const_iterator, const_iterator> equal_range(const value_type & value
  ) const;
  iterator lower_bound(const value_type & value);
  const_iterator lower_bound(const value_type & value) const;
  iterator upper_bound(const value_type & value);
  const_iterator upper_bound(const value_type & value) const;
  value_compare value_comp() const;
  rbtree & operator=(const rbtree & other);
  friend bool operator==(const rbtree & lhs, const rbtree & rhs);
  friend bool operator!=(const rbtree & lhs, const rbtree & rhs);
  friend bool operator>(const rbtree & lhs, const rbtree & rhs);
  friend bool operator>=(const rbtree & lhs, const rbtree & rhs);
  friend bool operator<(const rbtree & lhs, const rbtree & rhs);
  friend bool operator<=(const rbtree & lhs, const rbtree & rhs);
  friend void std::swap(rbtree & lhs, rbtree & rhs);

private:
  value_compare _comp;
  node * _root;
};

} // namespace ft

#endif // !RBTREE_HXX
