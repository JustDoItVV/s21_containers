#ifndef __S21_CONTAINERS_Stack_H__
#define __S21_CONTAINERS_Stack_H__

#include <initializer_list>
#include <iostream>
#include <list>
#include <utility>

namespace s21 {
template <class T>
class stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  // Member functions
  stack() : l() { l = std::list<value_type>(); }
  stack(std::initializer_list<value_type> const &items) {
    for (auto it : items) l.push_front(it);
  }
  stack(const stack &s) {
    l = std::list<value_type>(s.l.size());
    auto itL = l.begin();
    for (auto it = s.l.begin(), end = s.l.end(); it != end; it++) {
      *itL = *it;
      itL++;
    }
  }
  stack(stack &&s) : l(std::move(s.l)) {}
  stack &operator=(stack &&s) {
    this->l = std::move(s.l);
    return *this;
  }

  // Element access
  const_reference top() { return l.front(); };

  // SCapacity
  bool empty() { return l.empty(); };
  size_t size() { return l.size(); };

  // Modifiers
  void push(const_reference &value) { this->l.push_front(value); }
  void pop() { this->l.pop_front(); }
  void swap(stack &other) { this->l.swap(other.l); }

  template <typename... Args>
  void insert_many_front(Args &&...args) {
    (push(std::forward<Args>(args)), ...);
  }

 private:
  std::list<value_type> l;
};
};  // namespace s21
#endif