#ifndef __S21_CONTAINERS_MULTISET_H__
#define __S21_CONTAINERS_MULTISET_H__

#include "s21_RBTree.h"

namespace s21 {
template <class Key>
class multiset : public RBTree<Key, Key> {
 public:
  // Member type
  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using const_reference = const reference;
  using iterator = typename RBTree<Key, Key>::Iterator;
  using const_iterator = const iterator;
  using size_type = size_t;

 public:
  // Member functions
  multiset() : RBTree<Key, Key>(){};
  multiset(std::initializer_list<value_type> const& items) {}
  multiset(const multiset& ms) {}
  multiset(multiset&& ms) {}
  ~multiset() {}
  multiset operator=(multiset&& ms) {}

  // Iterators
  iterator begin() { return NULL; }
  iterator end() { return NULL; }

  // Capacity
  bool empty() { return false; }
  size_type size() { return 0; }
  size_type max_size() { return 0; }

  // Modifiers
  void clear() {}
  iterator insert(const value_type& value) { return NULL; }
  void erase(iterator pos) {}
  void swap(multiset& other) {}
  void merge(multiset& other) {}

  // Lookup - просмотр мультисета
  size_type count(const Key& key) { return 0; }
  iterator find(const Key& key) { return NULL; }
  bool contains(const Key& key) { return false; }
  std::pair<iterator, iterator> equal_range(const Key& key) {
    return std::pair<iterator, iterator>(nullptr, nullptr);
  }
  iterator lower_bound(const Key& key) { return NULL; }
  iterator upper_bound(const Key& key) { return NULL; }
};
};  // namespace s21

#endif