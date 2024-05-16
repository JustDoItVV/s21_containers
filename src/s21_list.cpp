#ifndef __S21_CONTAINERS_LIST_H__
#define __S21_CONTAINERS_LIST_H__

// TODO: удалить данный документ после того, как Саша напишет свою реализацию

#include <iostream>
#include <utility>
#include <vector>

// namespace s21 {
// template <class T>
// class list {
//  public:
//   // List Member type
//   using value_type = T;
//   using reference = T &;
//   using const_reference = const T &;
//   using size_type = size_t;

//   // using iterator = ListIterator<T>;
//   // using const_iterator = ListConstIterator<T>;

//  private:
//   struct Node {
//     Node *pnext;
//     Node *pprev;
//     value_type val;

//     Node(const_reference data) : pnext(nullptr), pprev(nullptr), val(data) {}
//   };

//   Node *head;
//   Node *tail;
//   size_type sz;

//  public:
//   list() : head(nullptr), tail(nullptr), sz(0) {}

//   list(size_type n) : list() {
//     for (size_type i = 0; i < n; ++i) {
//       push_back(value_type());  // передаю значение по умолчанию согласно нашему
//                                 // типу данных
//     }
//   }

//   list(std::initializer_list<value_type> const &items) : list() {
//     for (const_reference elem : items) {
//       push_back(elem);
//     }  // const value_type & = const_reference !!!
//   }

// // //Первый вариант конструктора копирования
// //   list(const list &l) : list() {
// //     Node* curr = l.head;
// //     for(size_type i = 0; i < l.sz; ++i) {
// //       push_back(curr->val);
// //       curr = curr->pnext;
// //     }
// //   }

// //Второй вариант конструктора копирования
//   list(const list &l) : list() {
//     Node* curr = l.head;
//     while (curr) {         // = curr != nullptr
//       push_back(curr->val);
//       curr = curr->pnext;
//     }
//   }

//   list(list &&l) : list() {
//     head = l.head;
//     tail = l.tail; 
//     sz = l.sz;

//     l.head = nullptr;
//     l.tail = nullptr;
//     l.sz = 0; 
//   }

//   ~list() {
//     for (size_type i = 0; i < sz; i++) {
//       pop_front();
//     }
//   }

//   list operator=(list &&l) {}

//   // // Element access
//   // const_reference front() {}
//   // const_reference back() {}

//   // // Iterators
//   // iterator begin() {}
//   // iterator end() {}

//   // Capacity Definition
// //   bool empty() {}
// // | size_type size() {}
// // | size_type max_size() {}

//   // Modifiers
//   // void clear() {}
//   // iterator insert(iterator pos, const_reference value) {}
//   // void erase(iterator pos) {}
//   // void pop_back() {}
//   void push_back(const_reference value) {
//     if (!head) {
//       head = new Node(value);
//       tail = head;
//     } else {
//       tail->pnext = new Node(value);
//       tail->pnext->pprev = tail;
//       tail = tail->pnext;
//     }
//     sz++;
//     // std::cout << value << std::endl;
//   }

//   void pop_front() {
//     if (!head) {
//       return;
//     }
//     if (head == tail) {
//       delete head;
//       head = nullptr;
//       tail = nullptr;
//     } else {
//       head = head->pnext;
//       delete head->pprev;
//       head->pprev = nullptr;
//     }
//     sz--;
//   }
//   // void push_front(const_reference value) {}
//   // void swap(list& other) {}
//   // void merge(list& other) {}
//   // void splice(const_iterator pos, list& other) {}
//   // void reverse() {}
//   // void unique() {}
//   // void sort() {}
// };
// };  // namespace s21

int main() {
  // s21::list<std::string> MyList = {"what", "a", "wonderful", "world"};
  // s21::list<int> MyList2 = {1, 2, 3, 4, 5};
  std::vector<int> MyVec = {};
      try
    {
        MyVec.front();
    }
    catch (const char* error_message)
    {
        std::cout << error_message << std::endl;
    }

  return 0;
}

#endif