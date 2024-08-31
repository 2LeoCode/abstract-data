#ifndef ALGORITHM_HXX
#define ALGORITHM_HXX

#include <cstddef>

namespace ft {

template <class T, class U> struct pair {
  typedef T first_type;
  typedef U second_type;

  first_type first;
  second_type second;

  pair();
  pair(const pair & other);
  pair(const first_type & first, const second_type & second);
  template <class T2, class U2> pair(const pair<T2, U2> & other);

  pair & operator=(const pair & other);
  template <class T2, class U2> pair & operator=(const pair<T2, U2> & other);
  friend bool operator==(const pair & lhs, const pair & rhs);
  friend bool operator!=(const pair & lhs, const pair & rhs);
  friend bool operator<(const pair & lhs, const pair & rhs);
  friend bool operator<=(const pair & lhs, const pair & rhs);
  friend bool operator>(const pair & lhs, const pair & rhs);
  friend bool operator>=(const pair & lhs, const pair & rhs);

  template <class T2, class U2>
  friend pair<T2, U2> make_pair(T2 first, U2 second);
};

template <class ForwardIt1, class ForwardIt2>
ForwardIt2 swap_ranges(ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2);
template <class ForwardIt1, class ForwardIt2>
void iter_swap(ForwardIt1 lhs, ForwardIt2 rhs);
template <class T> void swap(T & lhs, T & rhs);
template <class T, std::size_t N> void swap(T (&lhs)[N], T (&rhs)[N]);

} // namespace ft

#endif // !ALGORITHM_HXX
