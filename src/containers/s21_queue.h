#ifndef __S21_CONTAINERS_QUEUE_H__
#define __S21_CONTAINERS_QUEUE_H__

#include <iostream>
#include <utility>

namespace s21 {
template <class T>
class queue {
 public:
  // Queue Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

 public:
  // Queue Member functions
  queue() {}
  queue(std::initializer_list<value_type> const &items) {}
  queue(const queue &q) {}
  queue(queue &&q) {}
  ~queue() {}
  queue operator=(queue &&q) {}

  // Queue Element access
  const_reference front() { return 0; }
  const_reference back() { return 0; }

  // Queue Capacity
  bool empty() { return true; }
  size_type size() { return 0; }

  // Queue Modifiers
  void push(const_reference value) {}
  void pop() {}
  void swap(queue &other) {}
};
}  // namespace s21

#endif