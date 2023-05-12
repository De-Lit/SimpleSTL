#ifndef SIMPLE_STL_QUEUE_H_
#define SIMPLE_STL_QUEUE_H_

#include <cstddef>
#include <initializer_list>
#include <stdexcept>

namespace simplestl {
template <typename T>
class queue {
  struct Node;

 public:
  //  Member type
  typedef T value_type;
  typedef T &reference;
  typedef const T &const_reference;
  typedef std::size_t size_type;

  // Member functions
  queue() noexcept : head_(nullptr), tail_(nullptr), size_(0) {}
  queue(std::initializer_list<value_type> const &items) noexcept : queue() {
    auto iter = items.begin();
    for (size_type i = 0; i < items.size(); ++i) {
      this->push(iter[i]);
    }
  }
  queue(const queue &s) noexcept : queue() {
    Node *node = s.head_;
    while (node != nullptr) {
      push(node->value);
      node = node->next;
    }
  }
  queue(queue &&s) noexcept : queue() {
    std::swap(this->size_, s.size_);
    std::swap(this->head_, s.head_);
    std::swap(this->tail_, s.tail_);
  }
  queue &operator=(const queue &s) = delete;
  queue &operator=(queue &&s) noexcept {
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
    std::swap(this->tail_, s.tail_);
    return *this;
  }
  ~queue() {
    Node *node = nullptr;
    while (head_ != nullptr) {
      node = head_;
      head_ = head_->next;
      delete node;
    }
    tail_ = nullptr;
  }

  // Element access
  const_reference front() noexcept { return head_->value; }
  const_reference back() noexcept { return tail_->value; }

  // Capacity
  bool empty() noexcept { return size_ == 0; }
  size_type size() const noexcept { return size_; }

  // Modifiers
  void push(const_reference value) noexcept {
    Node *new_node = new Node;
    new_node->value = value;
    new_node->next = nullptr;
    if (head_ == nullptr) {
      head_ = new_node;
      tail_ = new_node;
    } else {
      tail_->next = new_node;
      tail_ = new_node;
    }
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
  void swap(queue &other) noexcept {
    std::swap(this->size_, other.size_);
    std::swap(this->head_, other.head_);
    std::swap(this->tail_, other.tail_);
  }

  // Insert template
  template <typename... Args>
  void emplace_back(Args &&...args) noexcept {
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
  Node *tail_;
  size_type size_;
};
}  // namespace simplestl

#endif  // SIMPLE_STL_H_