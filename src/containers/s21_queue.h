#ifndef __S21_CONTAINERS_QUEUE_H__
#define __S21_CONTAINERS_QUEUE_H__

#include <iostream>
#include <utility>

namespace s21{
    template <class T>
    class queue {
        public:
            // Queue Member type
            using value_type = T;
            using reference = T&;
            using const_reference = const T&;
            using size_type = size_t;

        public:
            // Queue Member functions
            queue() {}
            queue(std::initializer_list<value_type> const &items) {}
            queue(const queue &q) {}
            queue(queue &&q) {}
            ~queue() {}
            operator=(queue &&q)

            // Queue Element access
            const_reference front() {}
            const_reference back() {}

            // Queue Capacity
            bool empty() {}
            size_type size() {}

            // Queue Modifiers
            void push(const_reference value) {}
            void pop() {}
            void swap(queue& other) {}
    };
} // namespace s21


#endif