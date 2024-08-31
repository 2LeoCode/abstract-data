#include <algorithm.hxx>

namespace ft {

template <class T, class U> pair<T, U>::pair() : first(), second() {}

template <class T, class U>
pair<T, U>::pair(const first_type & first, const second_type & second)
    : first(first), second(second) {}

template <class T, class U>
template <class T2, class U2>
pair<T, U>::pair(const pair<T2, U2> & other)
    : first(other.first), second(other.second) {}

} // namespace ft
