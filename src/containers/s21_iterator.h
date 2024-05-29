#ifndef __S21_CONTAINERS_ITERATOR_H__
#define __S21_CONTAINERS_ITERATOR_H__

#include <cstddef>
#include <iostream>
#include <utility>

// TODO: ??Возможно?? сделать базовый класс итераторов с фабричным методом и
// наследовать ArrayIterator и ListIterator от него

namespace s21 {
template <typename T, size_t N>
class ArrayIterator {
 public:
  using value_type = T;
  using pointer = value_type *;
  using iterator = ArrayIterator<T, N>;
  using reference = value_type &;
  using difference_type =
      std::ptrdiff_t;  // TODO: убрать если не будет использоваться

  ArrayIterator(pointer ptr) : ptr_(ptr), start_(ptr){};

  iterator &operator++();
  iterator operator++(int);
  iterator &operator--();
  iterator operator--(int);
  reference operator*() const;
  bool operator==(const iterator &it);
  bool operator!=(const iterator &it);

  pointer begin();
  pointer end();

 private:
  pointer start_;
  pointer ptr_;
};

template <typename T, size_t N>
typename ArrayIterator<T, N>::iterator &ArrayIterator<T, N>::operator++() {
  ptr_++;
  return *this;
};

template <typename T, size_t N>
typename ArrayIterator<T, N>::iterator ArrayIterator<T, N>::operator++(int) {
  iterator tmp = *this;
  ptr_++;
  return tmp;
};

template <typename T, size_t N>
typename ArrayIterator<T, N>::iterator &ArrayIterator<T, N>::operator--() {
  ptr_--;
  return *this;
};

template <typename T, size_t N>
typename ArrayIterator<T, N>::iterator ArrayIterator<T, N>::operator--(int) {
  iterator tmp = *this;
  ptr_--;
  return tmp;
};

template <typename T, size_t N>
bool ArrayIterator<T, N>::operator==(const iterator &it) {
  return ptr_ == it.ptr_;
};

template <typename T, size_t N>
bool ArrayIterator<T, N>::operator!=(const iterator &it) {
  return ptr_ != it.ptr_;
}

template <typename T, size_t N>
typename ArrayIterator<T, N>::pointer ArrayIterator<T, N>::begin() {
  return start_;
}

template <typename T, size_t N>
typename ArrayIterator<T, N>::pointer ArrayIterator<T, N>::end() {
  return start_ + N;
}

template <typename T, size_t N>
typename ArrayIterator<T, N>::reference ArrayIterator<T, N>::operator*() const {
  return *ptr_;
}

}  // namespace s21

#endif