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
    struct  ListNode {
      T value_ = T();
      ListNode* previous_ = nullptr;
      ListNode* next_ = nullptr;
      explicit ListNode(T value = T(), ListNode* previous = nullptr, 
        ListNode* next = nullptr) : 
          value_(value), previous_(previous), next_(next) {}
    };

    template <typename U>
    class ListIterator {
    public:
        using ListNode = typename s21::list<T>::ListNode<T>*;
        ListIterator(ListNode node) : current_(node) {}
        T& operator*() {
            return current_->value_;
        }
        ListIterator& operator++() {
            current_ = current_->next_;
            return *this;
        }
        ListIterator& operator--() {
            current_ = current_->previous_;
            return *this;
        }
        bool operator==(const ListIterator& other) const {
            return current_ == other.current_;
        }
        bool operator!=(const ListIterator& other) const {
            return !(*this == other);
        }
    private:
        ListNode current_;
    };

    template <typename U>
    class ListConstIterator {
    public:
        using ListNode = const typename s21::list<T>::ListNode<T>*;
        ListConstIterator(ListNode node) : current_(node) {}
        const T& operator*() const {
            return current_->value_;
        }
        ListConstIterator& operator++() {
            current_ = current_->next_;
            return *this;
        }
        ListConstIterator& operator--() {
            current_ = current_->previous_;
            return *this;
        }
        bool operator==(const ListConstIterator& other) const {
            return current_ == other.current_;
        }
        bool operator!=(const ListConstIterator& other) const {
            return !(*this == other);
        }
    private:
        ListNode current_;
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
    list(size_type n) {
      for (size_type i = 0; i < n; ++i) {
          push_back(value_type());
      }
    }
    list(std::initializer_list<value_type> const &items) {
      for (const auto &item : items) {
          push_back(item);
      }
    }
    // copy constructor
    list(const list &l) {
      for (const auto &item : l) {
          push_back(item);
      }
    }
    // move constructor
    list(list &&l) {
    if (this != &l) {
        clear();
        end_ = l.end_;
        tail_ = l.tail_;
        head_ = l.head_;
        size_ = l.size_;
        l.end_ = nullptr;
        l.tail_ = nullptr;
        l.head_ = nullptr;
        l.size_ = 0;
      }
    }
    // destructor
    ~list() {
      clear();
      delete end_;
    }
    list operator=(list &&l) {
      if (this != &l) {
          clear();
          end_ = l.end_;
          l.end_ = nullptr;
      }
      return *this;
    }

    // list element access
    const_reference front() {
      if (!empty()) {
        return begin()->value;
      }
    }
    const_reference back() {
      if (!empty()) {
        return end()->value;
      }
    }

    // list iterators
    iterator begin() {return iterator(head_);}
    iterator end() {return iterator(end_);}

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
        if (size_==1) {
          head_ = nullptr;
          tail_ = nullptr;
          delete end_->previous_;
          end_ = nullptr;
        }
        else {
          if (pos.current_->previous_==nullptr) {
            head_ = head_->next_;
            delete head_->previous_;
            head_->previous_ = nullptr;
          }
          else if(pos.current_ == end_) {
            tail_ = tail_->previous_;
            delete end_->previous_;
            end_->previous_ = tail_;
            tail_->next_ = end_;
          }
          else {
            ListNode<value_type>* new_previous_node = pos.current_->previous_;
            ListNode<value_type>* new_next_node = current_->next_;
            delete current_;
            new_previous_node->next_ = new_next_node;
            new_next_node->previous_ = new_previous_node;
          }
        }
      size_--;
      }
    }
    void push_back (const_reference value) {insert(end(), value);}
    void pop_back() {erase(iterator(tail_));}
    void push_front(const_reference value) {insert(begin(), value);}
    void pop_front() {erase(iterator(head_));}
    void swap (list& other) {
      pointer temp_head_ = other.head_;
      pointer temp_tail_ = other.tail_;
      pointer temp_end_ = other.end_;
      pointer temp_size_ = other.size_;
      other.head_ = this->head_;
      other.tail_ = this->tail_;
      other.end_ = this->end_;
      other.size_ = this->size_;
      this->head_ = temp_head_;
      this->tail_ = temp_tail_;
      this->end_ = temp_end_;
      this->size_ = temp_size_;
    }
    void merge (list& other) {}
    void splice(const_iterator pos, list& other) {}
    void reverse() {
      auto leftIterator = begin();
      auto rightIterator = end();
      // --rightIterator; - TODO: чекнуть на тестах
      for (int i = 0; i < size_ / 2; i++) {
          auto temp = *leftIterator;
          *leftIterator = *rightIterator;
          *rightIterator = temp;
          ++leftIterator;
          --rightIterator;
      }
    }
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