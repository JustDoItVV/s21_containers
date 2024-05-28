#ifndef __S21_CONTAINERS_ITERATOR_H__
#define __S21_CONTAINERS_ITERATOR_H__

#include <iostream>
#include <utility>

namespace s21 {
template <typename T>
class Iterator {
 public:
  using pointer = T *;
  using size_type = std::size_t;
  using distance = std::ptrdiff_t;

  Iterator();

 private:
  pointer ptr_;
  pointer start_;
  size_type size_;
};

}  // namespace s21

#endif