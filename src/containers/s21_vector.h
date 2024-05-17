#ifndef __S21_CONTAINERS_VECTOR_H__
#define __S21_CONTAINERS_VECTOR_H__

#include <initializer_list>
#include <iostream>
#include <iterator>
#include <memory>
#include <utility>

namespace s21 {
template <class T>
class vector {
 public:
  // Vector member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

 public:
  // Vector Member functions
  vector() : sz(0), cap(5), arr(new value_type[cap]) {}

  vector(size_type n) : vector() {
    sz = n;
    cap = n;
    if (sz > 0) {
      arr = new value_type[n];
    }
  }

  vector(std::initializer_list<value_type> const &items)
      : sz(items.size()), cap(items.size()), arr(new value_type[cap]) {
    std::copy(items.begin(), items.end(), arr);
  }

  vector(const vector &v) : sz(v.sz), cap(v.cap), arr(new value_type[cap]) {
    std::copy(v.begin(), v.end(), arr);
  }

  vector(vector &&v) : sz(v.sz), cap(v.cap), arr(v.arr) {
    v.sz = 0;
    v.cap = 0;
    v.arr = nullptr;
  }

  ~vector() {
    if (arr) delete arr;
  }

  vector operator=(vector &&v) {}

  // Vector Element access
  reference at(size_type pos) {
    if (pos >= sz) {
      throw std::out_of_range("Memory error: no such element");
    }
    return arr[pos];
  }

  const_reference at(size_type pos) const {
    if (pos >= sz) {
      throw std::out_of_range("Memory error: no such element");
    }
    return arr[pos];
  }

  reference operator[](size_type pos) { return arr[pos]; }

  const_reference front() const { return arr[0]; }

  const_reference back() const { return arr[sz - 1]; }

  T *data() { return arr; }

  // Vector Iterators
  iterator begin() { return arr; }
  iterator end() { return arr + sz; }
  const_iterator begin() const { return arr; }
  const_iterator end() const { return arr + sz; }

  // Capacity
  size_type size() { return sz; }

  bool empty() { return sz == 0; }

  size_type max_size() {
    return std::numeric_limits<size_type>::max() / sizeof(size_type);
  }

  void reserve(size_type size) {
    if (size > max_size()) {
      std::length_error("Reserve Error: max size exceeded");
    }
    if (size > cap) {
      iterator tmp = arr;
      arr = new value_type[size];
      for (size_type i = 0; i < size; ++i) {
        arr[i] = tmp[i];
      }
      delete tmp;
      cap = size;
    }
  }

  size_type capacity() { return cap; }

  void shrink_to_fit() {
    if (sz < cap) {
      iterator tmp = arr;
      arr = new value_type[sz];
      for (size_type i = 0; i < sz; ++i) {
        arr[i] = tmp[i];
      }
      delete tmp;
      cap = sz;
    }
  }

  // Vector Modifiers
  void clear() { sz = 0; }

  iterator insert(iterator pos, const_reference value) {
    if (cap == sz) {
      size_type index = pos - begin();  // вычисляем индекс
      reserve(cap * 2);
      pos = begin() + index;  // находим новый итератор
    }
    value_type prev = value;
    for (iterator it = pos; it <= end(); ++it) {
      if (it < end()) {
        value_type curr = *it;
        *it = prev;
        prev = curr;
      } else {
        *it = prev;
      }
    }
    sz++;
    return pos;
  }

  void erase(iterator pos) {
    if (pos >= begin() && pos < end()) {
      for (iterator it = pos; it < end() - 1; ++it) {
        *it = *(it + 1);
      }
      sz--;
    }
  }

  void push_back(const_reference value) {
    if (sz == cap) {
      reserve(cap * 2);
    }
    arr[sz] = value;
    sz++;
  }

  void pop_back() {
    if (sz) sz--;
  }

  void swap(vector &other) {
    std::swap(sz, other.sz);
    std::swap(cap, other.cap);
    std::swap(arr, other.arr);
  }

 private:
  size_type sz;
  size_type cap;
  iterator arr;
};
};  // namespace s21

#endif  // __S21_CONTAINERS_VECTOR_H__