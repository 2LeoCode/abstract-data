#include <iterator.hxx>

namespace ft {

template <class Iter>
typename reverse_iterator<Iter>::iterator_type
reverse_iterator<Iter>::base() const {
  return this->current;
}

} // namespace ft
