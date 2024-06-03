#ifndef __S21_CONTAINERS_LIST_H__
#define __S21_CONTAINERS_LIST_H__

// TODO: удалить данный документ после того, как Кирюша напишет свою реализацию

#include <iostream>
#include <utility>
#include <limits>

namespace s21 {
  template <class T>
  class list {
  
  public:
    template <typename U>
    class ListIterator {
      private:
        typename s21::list<T>::iterator current;

      public:
        ListIterator(typename s21::list<T>::iterator iter) : current(iter) {}
        ListIterator& operator++() {
            ++current;
            return *this;
        }
        ListIterator& operator--() {
            --current;
            return *this;
        }
        T& operator*() {
            return *current;
        }
        bool operator==(const ListIterator& other) const {
            return current == other.current;
        }
        bool operator!=(const ListIterator& other) const {
            return current != other.current;
        }
    };
    template <typename U>
    class ListConstIterator{};
    template <typename U>
    struct  ListNode {
      T value_ = T();
      ListNode* previous_ = nullptr;
      ListNode* next_ = nullptr;
      explicit ListNode(T value = T(), ListNode* previous = nullptr, 
        ListNode* next = nullptr) : 
          value_(value), previous_(previous), next_(next) {}
    };


    
    // list member type
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using size_type = size_t;
    using iterator = ListIterator<T>;
    using const_iterator = ListConstIterator<T>;
    using pointer = ListNode<T>*;

    // list functions
    list() : end_(new ListNode(value_type())) {}
    list(size_type n) {}
    list(std::initializer_list<value_type> const &items) {}
    list(const list &l) {}
    list(list &&l) {}
    ~list() {}
    list operator=(list &&l) {}

    // list element access
    const_reference front() {}
    const_reference back() {}

    // list iterators
    iterator begin() {return head_;}
    iterator end() {return end_;}

    // list capacity
    bool empty() {return size_ == 0;}
    size_type size() {return size_;}
    size_type max_size() {return std::numeric_limits<size_type>::max()*0.75;}

    // list modifiers
    void clear() {
      while (size_!=0) {
        pop_back();
      }
      head_ = nullptr;
      tail_ = nullptr;
      end_->previous_ = nullptr;
    }
    iterator insert(iterator pos, const_reference value) {return NULL;}
    void erase (iterator pos) {}
    void push_back (const_reference value) {
    }
    void pop_back() {}
    void push_front(const_reference value) {}
    void pop_front() {}
    void swap (list& other) {}
    void merge (list& other) {}
    void splice(const_iterator pos, list& other) {}
    void reverse() {}
    void unique() {}
    void sort() {}

  private:
  pointer head_ = nullptr;
  pointer tail_ = nullptr;
  pointer end_ = nullptr;
  size_type size_ = 0;

  };

};  // namespace s21

#endif