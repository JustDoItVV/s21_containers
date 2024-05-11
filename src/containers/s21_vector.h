#ifndef __S21_CONTAINERS_VECTOR_H__ 
#define __S21_CONTAINERS_VECTOR_H__ 

#include <iostream>
#include <utility>
#include <initializer_list>
#include <iterator>
#include <memory>

namespace s21 {
    template <class T> 
    class vector {
        public:
        // Vector member type
        using value_type = T;
        using reference = T&;
        using const_reference = const T&; 
        using iterator = T*; // or VectorIterator<T> 
        using const_iterator = const T*; // or VectorConstIterator<T>
        using size_type = size_t;

        //Vector Member functions
        vector() {}
        vector(size_type n) {}
        vector(std::initializer_list<value_type> const &items) {}
        vector(const vector &v) {}
        vector(vector &&v) {}
        ~vector() {}
        vector operator=(vector &&v) {}

        //Vector Element access
        reference at(size_type pos) { return 0; }
        reference operator[](size_type pos) { return 0; }
        const_reference front() { return 0; }
        const_reference back() { return 0; }
        T* data() { return nullptr; }

        //Vector Iterators
        iterator begin() { return nullptr; }
        iterator end() { return nullptr; }

        //Capacity
        bool empty() { return false; }
        size_type size() { return 0; }
        size_type max_size() { return 0; }
        void reserve(size_type size) {}
        size_type capacity() { return 0; }
        void shrink_to_fit() {}

        // Vector Modifiers
        void clear() {}
        iterator insert(iterator pos, const_reference value) { return nullptr; }
        void erase(iterator pos) {}
        void push_back(const_reference value) {}
        void pop_back() {}
        void swap(vector& other) {}
    };
}; // namespace s21 

#endif // __S21_CONTAINERS_VECTOR_H__ 