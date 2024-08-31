#include <iterator.hxx>
#include <memory.hxx>

namespace ft {

template <class Iter>
template <class Iter2>
reverse_iterator<Iter> &
reverse_iterator<Iter>::operator=(const reverse_iterator<Iter2> & other) {
  this->current = other.current;
}

template <class Iter>
typename reverse_iterator<Iter>::reference
reverse_iterator<Iter>::operator*() const {
  Iter tmp(this->current);
  return *--tmp;
}

template <class Iter>
typename reverse_iterator<Iter>::pointer
reverse_iterator<Iter>::operator->() const {
  return addressof(**this);
}

template <class Iter>
typename reverse_iterator<Iter>::reference
reverse_iterator<Iter>::operator[](difference_type n) const {
  return this->current[-n - 1];
}

template <class Iter>
reverse_iterator<Iter> & reverse_iterator<Iter>::operator++() {
  --this->current;
  return *this;
}

template <class Iter>
reverse_iterator<Iter> reverse_iterator<Iter>::operator++(int) {
  reverse_iterator tmp(*this);
  --this->current;
  return tmp;
}

template <class Iter>
reverse_iterator<Iter> & reverse_iterator<Iter>::operator--() {
  ++this->current;
  return *this;
}

template <class Iter>
reverse_iterator<Iter> reverse_iterator<Iter>::operator--(int) {
  reverse_iterator tmp(*this);
  ++this->current;
  return tmp;
}

template <class Iter>
reverse_iterator<Iter> reverse_iterator<Iter>::operator+(difference_type n
) const {
  return reverse_iterator(this->current - n);
}

template <class Iter>
reverse_iterator<Iter> reverse_iterator<Iter>::operator-(difference_type n
) const {
  return reverse_iterator(this->current + n);
}

template <class Iter>
reverse_iterator<Iter> & reverse_iterator<Iter>::operator+=(difference_type n) {
  this->current -= n;
  return *this;
}

template <class Iter>
reverse_iterator<Iter> & reverse_iterator<Iter>::operator-=(difference_type n) {
  this->current += n;
  return *this;
}

template <class Iter1, class Iter2>
bool operator==(
    const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs
) {
  return lhs.current == rhs.current;
}

template <class Iter1, class Iter2>
bool operator!=(
    const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs
) {
  return lhs.current != rhs.current;
}

template <class Iter1, class Iter2>
bool operator<(
    const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs
) {
  return lhs.current > rhs.current;
}

template <class Iter1, class Iter2>
bool operator<=(
    const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs
) {
  return lhs.current >= rhs.current;
}

template <class Iter1, class Iter2>
bool operator>(
    const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs
) {
  return lhs.current < rhs.current;
}

template <class Iter1, class Iter2>
bool operator>=(
    const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs
) {
  return lhs.current <= rhs.current;
}

template <class Iter>
reverse_iterator<Iter> operator+(
    typename reverse_iterator<Iter>::difference_type n,
    const reverse_iterator<Iter> & rhs
) {
  return rhs + n;
}

template <class Iter1, class Iter2>
typename reverse_iterator<Iter1>::difference_type operator-(
    const reverse_iterator<Iter1> & lhs, const reverse_iterator<Iter2> & rhs
) {
  return rhs.current - lhs.current;
}

} // namespace ft
