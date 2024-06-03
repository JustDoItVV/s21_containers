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
        typename s21::list<T>::iterator current_;

      public:
        ListIterator(typename s21::list<T>::iterator iter) : current_(iter) {}
        ListIterator& operator++() {
            ++current_;
            return *this;
        }
        ListIterator& operator--() {
            --current_;
            return *this;
        }
        T& operator*() {
            return *current_;
        }
        bool operator==(const ListIterator& other) const {
            return current_ == other.current_;
        }
        bool operator!=(const ListIterator& other) const {
            return current_ != other.current_;
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
    size_type max_size() {return std::numeric_limits<size_type>::max();}

    // list modifiers
    void clear() {
      while (size_!=0) {
        pop_back();
      }
      head_ = nullptr;
      tail_ = nullptr;
      end_->previous_ = nullptr;
    }
    // TODO: зарефакторить insert, вынести в несколько приватных методов
    iterator insert(iterator pos, const_reference value) {
      iterator result_iterator = iterator();
      if (pos.next_ == end_) {
        if (pos.tail_ == nullptr) {
          tail_ = new ListNode<value_type>(value);
          head_ = tail_;
          result_iterator = iterator(tail_);
        }
        else {
          tail_ = new ListNode<value_type>(value);
          tail_->previous_->next_ = tail_;
          result_iterator = iterator(tail_);
        }
        tail_->next_ = end_;
        end_->previous_ = tail_;

      }
      else if (pos.current_->previous_==nullptr) {
        head_ = new ListNode<value_type>(value, nullptr, head_);
        head_->next_->previous = head_;
        result_iterator = iterator(head_);
      }
      else {
        ListNode<value_type>* new_node = new ListNode<value_type>(value, pos.current_->previous_, pos.current_);
        new_node->previous_->next_ = new_node;
        new_node->next_->previous_ = new_node;
        result_iterator = iterator(new_node);
      }
      size_++;
      return result_iterator;
    }
    // TODO: зарефакторить erase, вынести в несколько приватных методов
    void erase (iterator pos) {
      if (!empty()) {
        if (size==1) {
          head_ = nullptr;
          tail_ = nullptr;
          delete end_->previous_;
          end_ = nullptr;
        }
        else {
          if (pos.current_->previous_==nullptr) {
            head_ = head_->next_;
            delete head_->previous_;
            next_->previous = nullptr;
          }
          else if(pos.current_ == end_) {
            tail_ = tail_->previous_;
            delete end_->previous_;
            end_->previous_ = tail_;
            tail_->next_ = end_;
          }
          else {
            ListNode<value_type>* new_previous_node = current_->previous_;
            ListNode<value_type>* new_next_node = current_->next_;
            delete current_;
            new_previous_node->next_ = new_next_node;
            new_next_node->previous_ = new_previous_node;
          }
        }
      size_--;
      }
    }
    void push_back (const_reference value) {
      insert(iterator(tail_), value);
    }
    void pop_back() {}
    void push_front(const_reference value) {
      insert(iterator(head_), value);
    }
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