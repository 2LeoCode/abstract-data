#include <iterator.hxx>

namespace ft {

template <class Iter> reverse_iterator<Iter>::reverse_iterator() : current() {}

template <class Iter>
reverse_iterator<Iter>::reverse_iterator(iterator_type x) : current(x) {}

template <class Iter>
template <class Iter2>
reverse_iterator<Iter>::reverse_iterator(const reverse_iterator<Iter2> & other)
    : current(other.current) {}

} // namespace ft
