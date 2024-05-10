#ifndef __S21_CONTAINERS_LIST_H__
#define __S21_CONTAINERS_LIST_H__

// TODO: удалить данный документ после того, как Саша напишет свою реализацию

#include <iostream>
#include <utility>

namespace s21 {
template <class T>
class list {
 public:
  // Queue Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  // using iterator = ListIterator<T>;
  // using const_iterator = ListConstIterator<T>;

 public:
  list() {}
  list(size_type n) {}
  list(std::initializer_list<value_type> const &items) {}
  list(const list &l) {}
  list(list &&l) {}
  ~list() {}
  list operator=(list &&l) {}
};

};  // namespace s21

#endif