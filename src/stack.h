#ifndef SIMPLE_STL_STACK_H_
#define SIMPLE_STL_STACK_H_

#include <cstddef>
#include <initializer_list>
#include <stdexcept>

namespace simplestl {
template <typename T>
class stack {
  struct Node;

 public:
  //  Member type
  typedef T value_type;
  typedef T &reference;
  typedef const T &const_reference;
  typedef std::size_t size_type;

  // Member functions
  stack() noexcept : head_(nullptr), size_(0) {}
  stack(std::initializer_list<value_type> const &items) noexcept : stack() {
    auto iter = items.begin();
    for (size_type i = 0; i < items.size(); ++i) {
      this->push(iter[i]);
    }
  }
  stack(const stack &s) noexcept : stack() {
    stack tmp;
    Node *node = s.head_;
    while (node != nullptr) {
      tmp.push(node->value);
      node = node->next;
    }
    node = tmp.head_;
    while (node != nullptr) {
      this->push(node->value);
      node = node->next;
    }
  }
  stack(stack &&s) noexcept : stack() {
    std::swap(this->size_, s.size_);
    std::swap(this->head_, s.head_);
  }
  stack &operator=(const stack &s) = delete;
  stack &operator=(stack &&s) noexcept {
    if (head_ != nullptr) {
      Node *node = nullptr;
      while (head_ != nullptr) {
        node = head_;
        head_ = head_->next;
        delete node;
      }
    }
    std::swap(this->size_, s.size_);
    std::swap(this->head_, s.head_);
    return *this;
  }
  ~stack() {
    Node *node = nullptr;
    while (head_ != nullptr) {
      node = head_;
      head_ = head_->next;
      delete node;
    }
  }

  // Element access
  const_reference top() noexcept { return head_->value; }

  // Capacity
  bool empty() const noexcept { return size_ == 0; }
  size_type size() const noexcept { return size_; }

  // Modifiers
  void push(const_reference value) noexcept {
    Node *new_node = new Node;
    new_node->value = value;
    new_node->next = head_;
    head_ = new_node;
    ++size_;
  }
  void pop() noexcept {
    if (head_ != nullptr) {
      Node *pop_node = head_;
      head_ = head_->next;
      delete pop_node;
      pop_node = nullptr;
    }
    --size_;
  }
  void swap(stack &other) noexcept {
    std::swap(this->size_, other.size_);
    std::swap(this->head_, other.head_);
  }

  // Insert template
  template <typename... Args>
  void emplace_front(Args &&...args) noexcept {
    for (auto arg : {std::forward<Args>(args)...}) {
      push(arg);
    }
  }

 private:
  struct Node {
    Node() : value(), next(nullptr) {}
    value_type value;
    Node *next;
  };

  Node *head_;
  size_type size_;
};
}  // namespace simplestl

#endif  // SIMPLE_STL_STACK_H_