#ifndef __S21_CONTAINERS_SET_H__
#define __S21_CONTAINERS_SET_H__

#include <iostream>
#include <utility>

namespace s21 {
template <class Key>
class set {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = value_type*;
  using const_iterator = const value_type*;
  using size_type = size_t;

 public:
  set() {}
  set(std::initializer_list<value_type> const& items) {}
  set(const set& s) {}
  set(set&& s) {}
  ~set() {}
  set operator=(set&& s) {}

  iterator begin() { return NULL; }
  iterator end() { return NULL; }

  bool empty() { return false; }
  size_type size() { return 0; }
  size_type max_size() { return 0; }

  void clear() {}
  std::pair<iterator, bool> insert(const value_type& value) {
    std::pair<iterator, bool> b(NULL, false);
    return b;
  }
  void erase(iterator pos) {}
  void swap(set& other) {}
  void merge(set& other) {}

  iterator find(const Key& key) { return NULL; }
  bool contains(const Key& key) { return false; }
};

}  // namespace s21

#endif