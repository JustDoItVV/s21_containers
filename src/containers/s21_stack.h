#ifndef __S21_CONTAINERS_Stack_H__
#define __S21_CONTAINERS_Stack_H__

#include <initializer_list>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

namespace s21 {
template <class Key>
class Stack {
 public:
  // Member functions
  Stack() : vect() { vect = vector<Key>(); }
  Stack(initializer_list<Key> const &items) { vect = vector<Key>(items); }
  Stack(const Stack &s) {
    vect = vector<Key>(s.vect.size());
    for (size_t i = 0; i < s.vect.size(); i++) {
      vect[i] = s.vect[i];
    }
  }
  Stack(Stack &&s) : vect(std::move(s.vect)) {}
  Stack &operator=(Stack &&s) {
    this->vect = std::move(s.vect);
    return *this;
  }

  // Element access
  Key const &top() { return vect.back(); };

  // SCapacity
  bool empty() { return vect.empty(); };
  size_t size() { return vect.size(); };

  // Modifiers
  void push(const Key &value) { this->vect.push_back(value); }
  void pop() { this->vect.pop_back(); }
  void swap(Stack &other) { this->vect.swap(other.vect); }

 private:
  vector<Key> vect;
};

}  // namespace s21

#endif
