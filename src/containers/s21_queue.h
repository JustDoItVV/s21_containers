#ifndef __S21_CONTAINERS_QUEUE_H__
#define __S21_CONTAINERS_QUEUE_H__

#include <iostream>
#include <list>  //TODO: убрать после того, как будет завершен наш лист
#include <utility>
// #include "s21_list.h"

namespace s21 {
template <class T, class ConteinerList = std::list<T>>
class queue {
 public:
  // Queue Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

 public:
  // Queue Member functions
  queue() : data_() {}

  queue(std::initializer_list<value_type> const &items) : data_(items) {}

  queue(const queue &q) : data_(q.data_) {}

  queue(queue &&q) : data_(q.data_) {}

  ~queue() {}

  queue &operator=(queue &q) {
    if (this != &q) {
      data_ = q.data_;
    }
    return *this;
  }

  queue &operator=(queue &&q) {
    if (this != &q) {
      data_ = std::move(q.data_);
    }
    return *this;
  }

  // Queue Element access
  const_reference front() const { return data_.front(); }
  reference front() { return data_.front(); }
  const_reference back() const { return data_.back(); }
  reference back() { return data_.back(); }

  // Queue Capacity
  bool empty() const { return data_.empty(); }
  size_type size() const { return data_.size(); }

  // Queue Modifiers
  void push(const_reference value) { data_.push_back(value); }
  void pop() { data_.pop_front(); }
  void swap(queue &other) { data_.swap(other.data_); }

 private:
  ConteinerList data_;

};  // class queue
}  // namespace s21

#endif