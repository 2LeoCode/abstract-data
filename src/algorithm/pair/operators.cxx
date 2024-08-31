#include <algorithm.hxx>

namespace ft {

template <class T, class U>
pair<T, U> & pair<T, U>::operator=(const pair & other) {
  this->first = other.first;
  this->second = other.second;
}

template <class T, class U>
template <class T2, class U2>
pair<T, U> & pair<T, U>::operator=(const pair<T2, U2> & other) {
  this->first = other.first;
  this->second = other.second;
}

template <class T, class U>
bool operator==(const pair<T, U> & lhs, const pair<T, U> & rhs) {
  return !(lhs < rhs) && !(rhs < lhs);
}

template <class T, class U>
bool operator!=(const pair<T, U> & lhs, const pair<T, U> & rhs) {
  return !(lhs == rhs);
}

template <class T, class U>
bool operator<(const pair<T, U> & lhs, const pair<T, U> & rhs) {
  return lhs.first < rhs.first ||
         (rhs.first == lhs.first && lhs.second < rhs.second);
}

template <class T, class U>
bool operator<=(const pair<T, U> & lhs, const pair<T, U> & rhs) {
  return !(lhs > rhs);
}

template <class T, class U>
bool operator>(const pair<T, U> & lhs, const pair<T, U> & rhs) {
  return rhs < lhs;
}

template <class T, class U>
bool operator>=(const pair<T, U> & lhs, const pair<T, U> & rhs) {
  return !(lhs < rhs);
}

} // namespace ft
