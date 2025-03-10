#ifndef FUNCTIONAL_HXX
#define FUNCTIONAL_HXX

namespace ft {

template <class T> struct less {
  typedef bool result_type;
  typedef T first_argument_type;
  typedef T second_argument_type;

  result_type operator()(
      const first_argument_type & lhs, const second_argument_type & rhs
  ) const;
};

} // namespace ft

#endif // !FUNCTIONAL_HXX
