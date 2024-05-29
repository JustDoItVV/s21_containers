#ifndef __S21_CONTAINERS_ITERATOR_H__
#define __S21_CONTAINERS_ITERATOR_H__

#include <cstddef>
#include <iostream>
#include <utility>

// TODO: ??Возможно?? сделать базовый класс итераторов с фабричным методом и
// наследовать ArrayIterator и ListIterator от него

namespace s21 {
template <typename T>
class ArrayIterator {
 public:
  using value_type = T;
  using pointer = value_type *;
  using iterator = ArrayIterator<T>;
  using reference = value_type &;
  using difference_type =
      std::ptrdiff_t;  // TODO: убрать если не будет использоваться

  ArrayIterator(pointer ptr) : ptr_(ptr){};
  iterator &operator++();
  iterator operator++(int);
  iterator &operator--();
  iterator operator--(int);
  reference operator*() const;
  bool operator==(const iterator &it);
  bool operator!=(const iterator &it);

 private:
  pointer ptr_;
};

template <typename T>
typename ArrayIterator<T>::iterator &ArrayIterator<T>::operator++() {
  ptr_++;
  return *this;
};

template <typename T>
typename ArrayIterator<T>::iterator ArrayIterator<T>::operator++(int) {
  iterator tmp = *this;
  ptr_++;
  return tmp;
};

template <typename T>
typename ArrayIterator<T>::iterator &ArrayIterator<T>::operator--() {
  ptr_--;
  return *this;
};

template <typename T>
typename ArrayIterator<T>::iterator ArrayIterator<T>::operator--(int) {
  iterator tmp = *this;
  ptr_--;
  return tmp;
};

template <typename T>
bool ArrayIterator<T>::operator==(const iterator &it) {
  return ptr_ == it.ptr_;
};

template <typename T>
bool ArrayIterator<T>::operator!=(const iterator &it) {
  return ptr_ != it.ptr_;
};

template <typename T>
typename ArrayIterator<T>::reference ArrayIterator<T>::operator*() const {
  return *ptr_;
}

}  // namespace s21

#endif