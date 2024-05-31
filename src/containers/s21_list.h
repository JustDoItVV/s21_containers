#ifndef __S21_CONTAINERS_LIST_H__
#define __S21_CONTAINERS_LIST_H__

// TODO: удалить данный документ после того, как Саша напишет свою реализацию

#include <iostream>
#include <utility>

namespace s21 {
  template <class T>
  class list {
  public:
    // list member type
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using size_type = size_t;
    using iterator = ListIterator<T>;
    using const_iterator = ListConstIterator<T>;

    // list functions
    list() {}
    list(size_type n) {}
    list(std::initializer_list<value_type> const &items) {}
    list(const list &l) {}
    list(list &&l) {}
    ~list() {}
    list operator=(list &&l) {}

    // list iterators
    iterator begin() {return NULL;}
    iterator end() {return NULL;}

    // list capacity
    bool empty() {return true;}
    size_type size() {return 0;}
    size_type maxsize() {return 0;}

    // list modifiers
    void clear() {}
    iterator insert(iterator pos, const_reference value) {return NULL;}
    void erase (iterator pos) {}
    void push_back (const_reference value) {}
    void pop_back() {}
    void push_front(const_reference value) {}
    void pop_front() {}
    void swap (list& other) {}
    void merge (list& other) {}
    void splice(const_iterator pos, list& other) {}
    void reverse() {}
    void unique() {}
    void sort() {}
  };

};  // namespace s21

#endif