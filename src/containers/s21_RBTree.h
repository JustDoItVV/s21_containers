#ifndef __S21_CONTAINERS_RBTREE_H__
#define __S21_CONTAINERS_RBTREE_H__

#include <iostream>
#include <utility>

namespace s21 {
template <typename Key, typename Value>
class RBTree {
 public:
  struct Node;

  class Iterator;
  class ConstIterator;

  using key_type = Key;
  using value_type = Value;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = Iterator;
  using const_iterator = ConstIterator;
  using size_type = size_t;

  struct Node {
    value_type value;
    Node* parent;
    Node* left;
    Node* right;
    int color;
    int height;
  };

  RBTree();
  RBTree(const RBTree& other);
  RBTree(RBTree& other);
  ~RBTree();
  RBTree& operator=(RBTree&& other);

  iterator begin();
  iterator end();
  bool empty();
  size_type size();
  size_type max_size();
  void clear();
  std::pair<iterator, bool> insert(const value_type& value);
  void erase(iterator pos);
  void swap(RBTree& other);
  void merge(RBTree& other);
  bool contains(const Key& key);

  class Iterator {
   public:
    friend RBTree<Key, Value>;
    Node* node;

    Iterator();
    Iterator(Node* node);

    iterator& operator++();
    iterator operator++(int);
    iterator& operator--();
    iterator operator--(int);
    reference operator*();
    bool operator==(const iterator& it);
    bool operator!=(const iterator& it);

    Node* moveForward();
    Node* moveBackward();
  };

  class ConstIterator : public Iterator {
   public:
    ConstIterator();

    const_reference operator*();
  };

 protected:
  Node* root;

  Node* copy(Node* node, Node* parent);
  void insert();
  void fixInsertion();
  void destroy();
  void fixDeleting();
  void join();
  void joinToRight();
  iterator find(const key_type& key);
  void split();
};

template <typename Key, typename Value>
RBTree<Key, Value>::RBTree() : root(nullptr) {}

template <typename Key, typename Value>
RBTree<Key, Value>::RBTree(const RBTree& other) {
  root = RBTree<Key, Value>::copy(other.root, nullptr);
}

template <typename Key, typename Value>
RBTree<Key, Value>::RBTree(RBTree& other) {
  root = other.root;
  other.root->reset(nullptr);
}

template <typename Key, typename Value>
RBTree<Key, Value>::~RBTree() {}

template <typename Key, typename Value>
typename RBTree<Key, Value>::RBTree& RBTree<Key, Value>::operator=(
    RBTree&& other) {
  if (this != &other) {
    root = other.root;
    other.root->reset(nullptr);
  }
  return this;
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::Node* RBTree<Key, Value>::copy(
    RBTree<Key, Value>::Node* node, RBTree<Key, Value>::Node* parent) {
  if (node == nullptr) return nullptr;

  Node* newNode = new Node;
  newNode->value = node->value;
  newNode->parent = node->parent;
  newNode->color = node->color;
  newNode->height = node->height;
  newNode->left = copy(node->left, newNode);
  newNode->right = copy(node->right, newNode);

  return newNode;
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::iterator RBTree<Key, Value>::begin() {
  return RBTree<Key, Value>::Iterator();
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::iterator RBTree<Key, Value>::end() {
  return RBTree<Key, Value>::Iterator();
}

template <typename Key, typename Value>
bool RBTree<Key, Value>::empty() {
  return false;
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::size_type RBTree<Key, Value>::size() {
  return 10;
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::size_type RBTree<Key, Value>::max_size() {
  return 100;
}

template <typename Key, typename Value>
void RBTree<Key, Value>::clear() {}

template <typename Key, typename Value>
typename std::pair<typename RBTree<Key, Value>::iterator, bool>
RBTree<Key, Value>::insert(
    const typename RBTree<Key, Value>::value_type& value) {
  std::pair<typename RBTree<Key, Value>::iterator, bool> b(nullptr, false);
  return b;
}

template <typename Key, typename Value>
void RBTree<Key, Value>::erase(iterator pos) {}

template <typename Key, typename Value>
void RBTree<Key, Value>::swap(RBTree& other) {}

template <typename Key, typename Value>
void RBTree<Key, Value>::merge(RBTree& other) {}

template <typename Key, typename Value>
typename RBTree<Key, Value>::iterator RBTree<Key, Value>::find(
    const key_type& key) {
  return RBTree<Key, Value>::iterator();
}

template <typename Key, typename Value>
bool RBTree<Key, Value>::contains(const key_type& key) {
  return true;
}

/***************************
 * Iterator
 * *************************/

template <typename Key, typename Value>
RBTree<Key, Value>::Iterator::Iterator() : node(nullptr) {}

template <typename Key, typename Value>
RBTree<Key, Value>::Iterator::Iterator(RBTree::Node* node) : node(node) {}

template <typename Key, typename Value>
typename RBTree<Key, Value>::Node* RBTree<Key, Value>::Iterator::moveForward() {
  return nullptr;
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::Node*
RBTree<Key, Value>::Iterator::moveBackward() {
  return nullptr;
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::reference
RBTree<Key, Value>::Iterator::operator*() {
  if (node == nullptr) throw std::runtime_error("no values");
  return node->value;
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::iterator&
RBTree<Key, Value>::Iterator::operator++() {
  return *this;
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::iterator RBTree<Key, Value>::Iterator::operator++(
    int) {
  Iterator tmp = *this;
  // operator++();
  return tmp;
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::iterator&
RBTree<Key, Value>::Iterator::operator--() {
  return *this;
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::iterator RBTree<Key, Value>::Iterator::operator--(
    int) {
  Iterator tmp = *this;
  // operator--();
  return tmp;
}

template <typename Key, typename Value>
bool RBTree<Key, Value>::Iterator::operator==(
    const typename RBTree<Key, Value>::iterator& it) {
  return node == it.node;
}

template <typename Key, typename Value>
bool RBTree<Key, Value>::Iterator::operator!=(
    const typename RBTree<Key, Value>::iterator& it) {
  return node != it.node;
}
}  // namespace s21

#endif