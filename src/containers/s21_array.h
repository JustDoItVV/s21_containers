#ifndef __S21_CONTAINERS_ARRAY_H__
#define __S21_CONTAINERS_ARRAY_H__

#include <iostream>
#include <utility>

#include "s21_iterator.h"

namespace s21 {
template <typename T, size_t N>
class array {
 public:
  // Member type
  using value_type = T;
  using reference = value_type &;
  using const_reference = const reference;
  using iterator = value_type *;
  using cons_iterator = const iterator;
  using size_type = size_t;

  // Member functions
  array();
  array(std::initializer_list<value_type> const &items);
  array(const array &a);
  array(array &&a);
  ~array() = default;
  operator=(array &&a);

  // Element access
  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  iterator data();

  // Iterators
  iterator begin();
  iterator end();

  // Capacity
  bool empty();
  size_type size();
  size_type max_size();

  // Modifiers
  void swap(array &other);
  void fill(const_reference value);

 private:
  value_type data_[N];
  size_type size_ = N;
  Iterator ptr_;
};

template <typename T, size_t N>
array<T, N>::array() : ptr_(Iterator(&data_, size_)){};

template <typename T, size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items)
    : ptr_(Iterator(this, size_)){

      };

}  // namespace s21

#endif