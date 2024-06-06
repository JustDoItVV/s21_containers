#ifndef __S21_CONTAINERS_Stack_H__
#define __S21_CONTAINERS_Stack_H__

#include <initializer_list>
#include <iostream>
#include <list>
#include <utility>

using namespace std;

namespace s21 {
template <class T>
class Stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  // Member functions
  Stack() : l() { l = list<value_type>(); }
  Stack(initializer_list<value_type> const &items) {
    l = list<value_type>(items);
  }
  Stack(const Stack &s) {
    l = list<value_type>(s.l.size());
    for (size_t i = 0; i < s.l.size(); i++) {
      l[i] = s.l[i];
    }
  }
  Stack(Stack &&s) : l(std::move(s.l)) {}
  Stack &operator=(Stack &&s) {
    this->l = std::move(s.l);
    return *this;
  }

  // Element access
  const_reference top() { return l.back(); };

  // SCapacity
  bool empty() { return l.empty(); };
  size_t size() { return l.size(); };

  // Modifiers
  void push(const_reference &value) { this->l.push_back(value); }
  void pop() { this->l.pop_back(); }
  void swap(Stack &other) { this->l.swap(other.l); }

 private:
  list<value_type> l;
};

}  // namespace s21

#endif
