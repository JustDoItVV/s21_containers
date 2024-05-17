#ifndef __S21_CONTAINERS_RBTREE_H__
#define __S21_CONTAINERS_RBTREE_H__

#include <iostream>
#include <queue>  // replace with s21::queue when it's ready
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
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = Iterator;
  using const_iterator = ConstIterator;
  using size_type = size_t;

  enum NodeColor { BLACK, RED };

  struct Node {
    value_type value;
    Node *left, *parent, *right;
    enum NodeColor color;
    Node();
  };

  RBTree();
  RBTree(std::initializer_list<value_type> const &items);
  RBTree(const RBTree &other);
  RBTree(RBTree &&other);
  ~RBTree();
  RBTree &operator=(RBTree &&other);

  iterator begin();
  iterator end();
  bool empty();
  size_type size();
  size_type max_size();
  void clear();
  std::pair<iterator, bool> insert(const value_type &value);
  void erase(iterator pos);
  void swap(RBTree &other);
  void merge(RBTree &other);
  iterator find(const value_type &value);
  bool contains(const value_type &value);
  void visualize(Node *root);

  class Iterator {
   public:
    friend RBTree<Key, Value>;
    Node *node;

    Iterator();
    Iterator(Node *node);

    iterator &operator++();
    iterator operator++(int);
    iterator &operator--();
    iterator operator--(int);
    reference operator*();
    bool operator==(const iterator &it);
    bool operator!=(const iterator &it);

    Node *moveForward();
    Node *moveBackward();
  };

  class ConstIterator : public Iterator {
   public:
    ConstIterator();

    const_reference operator*();
  };

  //  protected:
  Node *root;

  enum Direction { LEFT, RIGHT };

  Node *copy(Node *node, Node *parent);
  Node *search(Node *node, value_type value);
  void rotate(Node *node, Direction dir);
  Node *insertNode(Node *node);
  void fixInsertion(Node *node);
  void deleteNode(Node *node);
  void fixDeletion(Node *node);
  void replaceNode(Node *node, Node *target);
  static Node *findMin(Node *node);
  static Node *findMax(Node *node);
  Node *findNode(Node *node, value_type value);
  size_type calculateSize(Node *node);
};

template <typename Key, typename Value>
RBTree<Key, Value>::Node::Node()
    : left(nullptr), parent(nullptr), right(nullptr), color(RED) {}

template <typename Key, typename Value>
RBTree<Key, Value>::RBTree() : root(nullptr) {}

template <typename Key, typename Value>
RBTree<Key, Value>::RBTree(std::initializer_list<value_type> const &items) {
  for (value_type value : items) insert(value);
}

template <typename Key, typename Value>
RBTree<Key, Value>::RBTree(const RBTree &other) {
  root = RBTree<Key, Value>::copy(other.root, nullptr);
}

template <typename Key, typename Value>
RBTree<Key, Value>::RBTree(RBTree &&other) {
  root = other.root;
  other.root = nullptr;
}

template <typename Key, typename Value>
RBTree<Key, Value>::~RBTree() {}

template <typename Key, typename Value>
typename RBTree<Key, Value>::RBTree &RBTree<Key, Value>::operator=(
    RBTree &&other) {
  if (this != &other) {
    root = other.root;
    other.root = nullptr;
  }
  return this;
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::Node *RBTree<Key, Value>::copy(
    RBTree<Key, Value>::Node *node, RBTree<Key, Value>::Node *parent) {
  if (node == nullptr) return nullptr;

  Node *newNode = new Node;
  newNode->value = node->value;
  newNode->parent = parent;
  newNode->color = node->color;
  newNode->left = copy(node->left, newNode);
  newNode->right = copy(node->right, newNode);

  return newNode;
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::iterator RBTree<Key, Value>::begin() {
  Node *node = findMin(root);
  return Iterator(node);
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::iterator RBTree<Key, Value>::end() {
  Node *node = findMax(root);
  return Iterator(node);
}

template <typename Key, typename Value>
bool RBTree<Key, Value>::empty() {
  return !root;
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::size_type RBTree<Key, Value>::size() {
  return calculateSize(root);
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::size_type RBTree<Key, Value>::max_size() {
  return 100;
}

template <typename Key, typename Value>
void RBTree<Key, Value>::clear() {}

template <typename Key, typename Value>
typename std::pair<typename RBTree<Key, Value>::iterator, bool>
RBTree<Key, Value>::insert(const value_type &value) {
  Node *node = new Node;
  node->value = value;
  Node *insertedNode = insertNode(node);
  iterator it = Iterator(insertedNode == node ? node : insertedNode);
  std::pair<iterator, bool> b(it, insertedNode == node);
  return b;
}

template <typename Key, typename Value>
void RBTree<Key, Value>::erase(iterator pos) {}

template <typename Key, typename Value>
void RBTree<Key, Value>::swap(RBTree &other) {}

template <typename Key, typename Value>
void RBTree<Key, Value>::merge(RBTree &other) {}

template <typename Key, typename Value>
typename RBTree<Key, Value>::iterator RBTree<Key, Value>::find(
    const value_type &value) {
  Node *node = findNode(root, value);
  return Iterator(node);
}

template <typename Key, typename Value>
bool RBTree<Key, Value>::contains(const value_type &value) {
  Node *node = findNode(root, value);
  return node != nullptr;
}

/***************************
 * Iterator
 * *************************/

template <typename Key, typename Value>
RBTree<Key, Value>::Iterator::Iterator() : node(nullptr) {}

template <typename Key, typename Value>
RBTree<Key, Value>::Iterator::Iterator(RBTree::Node *node) : node(node) {}

template <typename Key, typename Value>
typename RBTree<Key, Value>::Node *RBTree<Key, Value>::Iterator::moveForward() {
  if (node->right != nullptr) return findMin(node->right);

  Node *parent = node->parent;
  if (parent->right == node) return node;

  while (parent != nullptr && node == parent->right) {
    node = parent;
    parent = parent->parent;
  }
  return parent;
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::Node *
RBTree<Key, Value>::Iterator::moveBackward() {
  if (node->left != nullptr) return findMax(node->right);

  Node *parent = node->parent;
  if (parent->left == node) return node;

  while (parent != nullptr && node == parent->left) {
    node = parent;
    parent = parent->parent;
  }
  return parent;
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::reference
RBTree<Key, Value>::Iterator::operator*() {
  if (node == nullptr) {
    static value_type fakeValue{};
    return fakeValue;
  }
  return node->value;
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::iterator &
RBTree<Key, Value>::Iterator::operator++() {
  node = moveForward();
  return *this;
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::iterator RBTree<Key, Value>::Iterator::operator++(
    int) {
  Iterator tmp = *this;
  operator++();
  return tmp;
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::iterator &
RBTree<Key, Value>::Iterator::operator--() {
  node = moveBackward();
  return *this;
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::iterator RBTree<Key, Value>::Iterator::operator--(
    int) {
  Iterator tmp = *this;
  operator--();
  return tmp;
}

template <typename Key, typename Value>
bool RBTree<Key, Value>::Iterator::operator==(
    const typename RBTree<Key, Value>::iterator &it) {
  return node == it.node;
}

template <typename Key, typename Value>
bool RBTree<Key, Value>::Iterator::operator!=(
    const typename RBTree<Key, Value>::iterator &it) {
  return node != it.node;
}

/***************************
 * RBTree inner methods (protected)
 * *************************/

template <typename Key, typename Value>
typename RBTree<Key, Value>::Node *RBTree<Key, Value>::search(
    Node *node, value_type value) {
  if (node == nullptr || value == node->value) return node;
  if (value < node->value)
    return search(node->left, value);
  else
    return search(node->right, value);
}

template <typename Key, typename Value>
void RBTree<Key, Value>::rotate(Node *root, Direction dir) {
  bool isLeft = dir == LEFT;
  Node *target = isLeft ? root->right : root->left;

  if (root == nullptr || (isLeft && root->right == nullptr) ||
      (!isLeft && root->left == nullptr))
    return;

  target->parent = root->parent;
  root->parent = target;
  if (target->parent == nullptr)
    this->root = target;
  else if (root == target->parent->left)
    target->parent->left = target;
  else
    target->parent->right = target;

  if (isLeft) {
    root->right = target->left;
    target->left = root;
  } else {
    root->left = target->right;
    target->right = root;
  }
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::Node *RBTree<Key, Value>::insertNode(Node *node) {
  Node *parent = nullptr, *root = this->root;
  node->color = RED;

  while (root != nullptr) {
    parent = root;
    if (node->value < root->value)
      root = root->left;
    else if (node->value > root->value)
      root = root->right;
    else
      return root;
  };

  if (parent == nullptr)
    this->root = node;
  else if (node->value < parent->value)
    parent->left = node;
  else
    parent->right = node;

  node->parent = parent;

  fixInsertion(node);
  return node;
}

template <typename Key, typename Value>
void RBTree<Key, Value>::fixInsertion(Node *node) {
  while (node != root && node->parent->color == RED) {
    if (node->parent == node->parent->parent->left) {
      Node *uncle = node->parent->parent->right;
      if (uncle != nullptr && uncle->color == RED) {
        node->parent->color = BLACK;
        node->color = BLACK;
        node->parent->parent->color = RED;
        node = node->parent->parent;
      } else {
        if (node == node->parent->right) {
          node = node->parent;
          rotate(node, LEFT);
        }
        node->parent->color = BLACK;
        node->parent->parent->color = RED;
        rotate(node->parent->parent, RIGHT);
      }
    } else {
      Node *uncle = node->parent->parent->left;
      if (uncle != nullptr && uncle->color == RED) {
        node->parent->color = BLACK;
        uncle->color = BLACK;
        node->parent->parent->color = RED;
        node = node->parent->parent;
      } else {
        if (node == node->parent->left) {
          node = node->parent;
          rotate(node, RIGHT);
        }
        node->parent->color = BLACK;
        node->parent->parent->color = RED;
        rotate(node->parent->parent, LEFT);
      }
    }
  }
  this->root->color = BLACK;
}

template <typename Key, typename Value>
void RBTree<Key, Value>::deleteNode(Node *node) {
  if (node == nullptr) return;

  Node *y = node;
  Node *x = nullptr;
  NodeColor y_original_color = y->color;

  if (node->left == nullptr) {
    x = node->right;
    replaceNode(node, node->right);
  } else if (node->right == nullptr) {
    x = node->left;
    replaceNode(node, node->left);
  } else {
    y = findMin(node->right);
    y_original_color = y->color;
    x = y->right;

    if (y->parent == node) {
      if (x != nullptr) x->parent = y;
    } else {
      if (x != nullptr) x->parent = y->parent;

      replaceNode(y, y->right);
      if (y->right != nullptr) y->right->parent = y;
      y->right = node->right;
      if (y->right != nullptr) y->right->parent = y;
    }
    replaceNode(node, y);
    y->left = node->left;
    if (y->left != nullptr) y->left->parent = y;
    y->color = node->color;
  }

  if (y_original_color == BLACK && x != nullptr) fixDeletion(x);

  delete node;
}

template <typename Key, typename Value>
void RBTree<Key, Value>::fixDeletion(Node *node) {
  while (node != root && node != nullptr && node->color == BLACK) {
    if (node == node->parent->left) {
      Node *tmp = node->parent->right;
      if (tmp->color == RED) {
        tmp->color = BLACK;
        node->parent->color = RED;
        rotate(node->parent, LEFT);
        tmp = node->parent->right;
      }
      if ((tmp->left == nullptr || tmp->left->color == BLACK) &&
          (tmp->right == nullptr || tmp->right->color == BLACK)) {
        tmp->color = RED;
        node = node->parent;
      } else {
        if (tmp->right == nullptr || tmp->right->color == BLACK) {
          if (tmp->left != nullptr) tmp->left->color = BLACK;
          tmp->color = RED;
          rotate(tmp, RIGHT);
          tmp = node->parent->right;
        }
        tmp->color = node->parent->color;
        node->parent->color = BLACK;
        if (tmp->right != nullptr) tmp->right->color = BLACK;
        rotate(node->parent, LEFT);
        node = root;
      }
    } else {
      Node *tmp = node->parent->left;
      if (tmp->color == RED) {
        tmp->color = BLACK;
        node->parent->color = RED;
        rotate(node->parent, RIGHT);
        tmp = node->parent->left;
      }
      if ((tmp->right == nullptr || tmp->right->color == BLACK) &&
          (tmp->left == nullptr || tmp->left->color == BLACK)) {
        tmp->color = RED;
        node = node->parent;
      } else {
        if (tmp->left == nullptr || tmp->left->color == BLACK) {
          if (tmp->right != nullptr) tmp->right->color = BLACK;
          tmp->color = RED;
          rotate(tmp, LEFT);
          tmp = node->parent->left;
        }
        tmp->color = node->parent->color;
        node->parent->color = BLACK;
        if (tmp->left != nullptr) tmp->left->color = BLACK;
        rotate(node->parent, RIGHT);
        node = root;
      }
    }
  }
  if (node != nullptr) node->color = BLACK;
}

template <typename Key, typename Value>
void RBTree<Key, Value>::replaceNode(Node *node, Node *target) {
  if (node->parent == nullptr)
    this->root = target;
  else if (node == node->parent->left)
    node->parent->left = target;
  else
    node->parent->right = target;

  if (target != nullptr) target->parent = node->parent;
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::Node *RBTree<Key, Value>::findMin(Node *node) {
  while (node != nullptr && node->left != nullptr) node = node->left;
  return node;
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::Node *RBTree<Key, Value>::findMax(Node *node) {
  while (node != nullptr && node->right != nullptr) node = node->right;
  return node;
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::Node *RBTree<Key, Value>::findNode(
    Node *node, value_type value) {
  if (node == nullptr || node->value == value) return node;

  if (value < node->value)
    return findNode(node->left, value);
  else
    return findNode(node->right, value);
}

template <typename Key, typename Value>
typename RBTree<Key, Value>::size_type RBTree<Key, Value>::calculateSize(
    Node *node) {
  if (node == nullptr) return 0;
  size_type leftSize = calculateSize(node->left);
  size_type rightSize = calculateSize(node->right);
  return 1 + leftSize + rightSize;
}

template <typename Key, typename Value>
void RBTree<Key, Value>::visualize(Node *root) {
  std::queue<Node *> activeQueue, nextQueue;
  Node *nil = new Node;
  nextQueue.push(root != nullptr ? root : nil);

  while (!nextQueue.empty()) {
    activeQueue = std::move(nextQueue);
    while (!activeQueue.empty()) {
      Node *node = activeQueue.front();
      activeQueue.pop();
      if (node->left != nullptr)
        nextQueue.push(node->left);
      else if (node != nil)
        nextQueue.push(nil);
      if (node->right != nullptr)
        nextQueue.push(node->right);
      else if (node != nil)
        nextQueue.push(nil);
      if (node->color == RED) std::cout << "\033[1;31m";
      if (node != nil)
        std::cout << node->value;
      else
        std::cout << "-";
      if (node->color == RED) std::cout << "\033[0m";
      std::cout << " ";
    };
    std::cout << std::endl;
  };
  std::cout << std::endl;
}
}  // namespace s21

#endif