#ifndef __S21_CONTAINERS_MAP_H__
#define __S21_CONTAINERS_MAP_H__

#include "s21_RBTree.h"

namespace s21 {
template <typename Key, typename T>
class map : public RBTree<Key, T> {
 public:
  // Member types
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const Key, T>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename RBTree<Key, T>::Iterator;
  using const_iterator = typename RBTree<Key, T>::ConstIterator;
  using size_type = size_t;

  // Member functions
  map() : RBTree<Key, T>(){};
  map(std::initializer_list<value_type> const &items) : RBTree<Key, T>(items){};
  map(const map &m) : RBTree<Key, T>(m){};
  map(map &&m) : RBTree<Key, T>(std::move(m)){};
  ~map() = default;
  map &operator=(map &&m) = default;

  // Element access
  T &at(const Key &key);
  T &operator[](const Key &key);

  // // Iterators
  // iterator begin();
  // iterator end();

  // // Capacity
  // bool empty() : RBTree<Key, T>::empty(){};
  // size_type size() : RBTree<Key, T>::size(){};

  // Modifiers
  std::pair<iterator, bool> insert(const Key &key, const T &obj);
  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj);
};

}  // namespace s21

#endif