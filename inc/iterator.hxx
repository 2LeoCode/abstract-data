#ifndef ITERATOR_HXX
#define ITERATOR_HXX

#include <cstddef>

namespace ft {

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template <class Iter> struct iterator_traits {
  typedef typename Iter::difference_type difference_type;
  typedef typename Iter::value_type value_type;
  typedef typename Iter::pointer pointer;
  typedef typename Iter::reference reference;
  typedef typename Iter::iterator_category iterator_category;
};

template <class T> struct iterator_traits<T *> {
  typedef std::ptrdiff_t difference_type;
  typedef T value_type;
  typedef T * pointer;
  typedef T & reference;
  typedef random_access_iterator_tag iterator_category;
};

template <class T> struct iterator_traits<const T *> {
  typedef std::ptrdiff_t difference_type;
  typedef T value_type;
  typedef const T * pointer;
  typedef const T & reference;
  typedef random_access_iterator_tag iterator_category;
};

template <class Iter> class reverse_iterator {
public:
  typedef Iter iterator_type;
  typedef typename iterator_traits<Iter>::iterator_category iterator_category;
  typedef typename iterator_traits<Iter>::value_type value_type;
  typedef typename iterator_traits<Iter>::difference_type difference_type;
  typedef typename iterator_traits<Iter>::pointer pointer;
  typedef typename iterator_traits<Iter>::reference reference;

  reverse_iterator();
  explicit reverse_iterator(iterator_type x);
  template <class Iter2>
  reverse_iterator(const reverse_iterator<Iter2> & other);

  iterator_type base() const;

  template <class Iter2>
  reverse_iterator & operator=(const reverse_iterator<Iter2> & other);
  reference operator*() const;
  pointer operator->() const;
  reference operator[](difference_type n) const;
  reverse_iterator & operator++();
  reverse_iterator operator++(int);
  reverse_iterator & operator--();
  reverse_iterator operator--(int);
  reverse_iterator operator+(difference_type n) const;
  reverse_iterator operator-(difference_type n) const;
  reverse_iterator & operator+=(difference_type n);
  reverse_iterator & operator-=(difference_type n);
  template <class Iter2>
  friend bool
  operator==(const reverse_iterator & lhs, const reverse_iterator<Iter2> & rhs);
  template <class Iter2>
  friend bool
  operator!=(const reverse_iterator & lhs, const reverse_iterator<Iter2> & rhs);
  template <class Iter2>
  friend bool
  operator<(const reverse_iterator & lhs, const reverse_iterator<Iter2> & rhs);
  template <class Iter2>
  friend bool
  operator<=(const reverse_iterator & lhs, const reverse_iterator<Iter2> & rhs);
  template <class Iter2>
  friend bool
  operator>(const reverse_iterator & lhs, const reverse_iterator<Iter2> & rhs);
  template <class Iter2>
  friend bool
  operator>=(const reverse_iterator & lhs, const reverse_iterator<Iter2> & rhs);
  friend reverse_iterator
  operator+(difference_type n, const reverse_iterator & it);
  template <class Iter2>
  friend typename reverse_iterator::difference_type
  operator-(const reverse_iterator & lhs, const reverse_iterator<Iter2> & rhs);

protected:
  iterator_type current;
};

} // namespace ft

#endif // !ITERATOR_HXX
