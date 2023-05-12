#ifndef SIMPLE_STL_LIST_H_
#define SIMPLE_STL_LIST_H_

#include <cstddef>
#include <initializer_list>
#include <stdexcept>

namespace simplestl {
template <typename T>
class list {
  struct Node;

 public:
  class ListIterator;
  //  Member type
  typedef T value_type;
  typedef T &reference;
  typedef const T &const_reference;
  typedef std::size_t size_type;
  typedef ListIterator iterator;
  typedef const ListIterator const_iterator;

  class ListIterator {
    friend class list;

   public:
    ListIterator() noexcept : cur_(nullptr) {}
    ListIterator(Node *node) noexcept : cur_(node) {}
    ListIterator(const_iterator &iter) noexcept : cur_(iter.cur_) {}
    ListIterator(iterator &&iter) noexcept : ListIterator() {
      std::swap(this->cur_, iter.cur_);
    }
    iterator &operator=(const_iterator &iter) = default;
    iterator &operator=(iterator &&iter) noexcept {
      std::swap(this->cur_, iter.cur_);
      return *this;
    }
    ~ListIterator() = default;

    reference operator*() noexcept { return cur_->value; }
    iterator &operator++() noexcept {
      cur_ = cur_->next;
      return *this;
    }
    iterator &operator--() noexcept {
      cur_ = cur_->previous;
      return *this;
    }
    bool operator==(const_iterator &other) noexcept {
      return this->cur_ == other.cur_;
    }
    bool operator!=(const_iterator &other) noexcept {
      return this->cur_ != other.cur_;
    }

   private:
    Node *cur_;
  };

  list() noexcept : head_(nullptr), tail_(nullptr), size_(0) {
    tail_ = new Node;
    head_ = tail_;
    tail_->next = tail_;
    tail_->previous = tail_;
  }
  list(size_type n) : list() {
    if (n > max_size()) {
      throw std::runtime_error("length_error");
    }
    Node node;
    while (size_ != n) {
      push_back(node.value);
    }
  }
  list(std::initializer_list<value_type> const &items) : list() {
    if (items.size() > max_size()) {
      throw std::runtime_error("length_error");
    }
    auto iter = items.begin();
    for (size_type i = 0; i < items.size(); ++i) {
      this->push_back(iter[i]);
    }
  }
  list(const list &l) : list() {
    auto node = l.head_;
    while (node != l.tail_) {
      this->push_back(node->value);
      node = node->next;
    }
  }
  list(list &&l) noexcept : list() {
    std::swap(this->size_, l.size_);
    std::swap(this->head_, l.head_);
    std::swap(this->tail_, l.tail_);
  }
  list &operator=(const list &l) = delete;
  list &operator=(list &&l) noexcept {
    this->swap(l);
    return *this;
  }
  ~list() {
    Node *pop_node = nullptr;
    for (; head_ != tail_;) {
      pop_node = head_;
      head_ = head_->next;
      delete pop_node;
      pop_node = nullptr;
    }
    delete tail_;
    head_ = nullptr;
    tail_ = nullptr;
  }

  //  nodes access
  const_reference front() noexcept { return head_->value; }
  const_reference back() noexcept {
    return size_ > 0 ? tail_->previous->value : tail_->value;
  }

  //  Iterators
  iterator begin() noexcept {
    iterator iter(head_);
    return iter;
  }
  iterator end() noexcept {
    iterator iter(tail_);
    return iter;
  }

  //  Capacity
  bool empty() const noexcept { return head_ == tail_; }
  size_type size() const noexcept { return size_; }
  size_type max_size() const noexcept { return SIZE_MAX / sizeof(Node) / 2; }

  //  Modifiers
  void clear() noexcept {
    while (size_ != 0) {
      pop_back();
    }
  }
  iterator insert(iterator pos, const_reference value) {
    if (size_ + 1 > max_size()) {
      throw std::runtime_error("length_error");
    }
    Node *insert_node = new Node;
    insert_node->value = value;
    insert_node->previous = pos.cur_->previous;
    insert_node->next = pos.cur_;
    pos.cur_->previous->next = insert_node;
    pos.cur_->previous = insert_node;
    if (head_ == pos.cur_) {
      head_ = insert_node;
    }
    ++size_;
    return iterator(insert_node);
  }
  void erase(iterator pos) {
    pos.cur_->previous->next = pos.cur_->next;
    pos.cur_->next->previous = pos.cur_->previous;
    if (head_ == pos.cur_) {
      head_ = pos.cur_->next;
    }
    delete pos.cur_;
    pos.cur_ = nullptr;
    --size_;
  }
  void push_back(const_reference value) {
    if (size_ + 1 > max_size()) {
      throw std::runtime_error("length_error");
    }
    Node *push_node = new Node;
    push_node->value = value;
    push_node->next = tail_;
    push_node->previous = tail_->previous;
    tail_->previous->next = push_node;
    tail_->previous = push_node;
    if (head_ == tail_) {
      head_ = push_node;
      tail_->next = push_node;
    }
    ++size_;
  }
  void pop_back() noexcept {
    if (tail_ != head_) {
      Node *pop_node = tail_->previous;
      tail_->previous = tail_->previous->previous;
      if (tail_->previous == tail_) {
        head_ = tail_;
        tail_->next = tail_;
      } else {
        tail_->previous->next = tail_;
      }
      delete pop_node;
      pop_node = nullptr;
      --size_;
    }
  }
  void push_front(const_reference value) {
    if (size_ + 1 > max_size()) {
      throw std::runtime_error("length_error");
    }
    Node *push_node = new Node;
    push_node->value = value;
    push_node->next = head_;
    push_node->previous = head_->previous;
    head_->previous = push_node;
    head_ = push_node;
    ++size_;
  }
  void pop_front() noexcept {
    if (head_ != tail_) {
      Node *pop_node = head_;
      head_ = head_->next;
      head_->previous = tail_;
      tail_->next = head_;
      delete pop_node;
      pop_node = nullptr;
    }
    --size_;
  }
  void swap(list &other) noexcept {
    std::swap(this->head_, other.head_);
    std::swap(this->tail_, other.tail_);
    std::swap(this->size_, other.size_);
  }
  void merge(list &other) noexcept {
    if (this != &other && other.size_ > 0) {
      if (this->size_ > 0) {
        Node *tmp_head = nullptr;
        Node *tmp = nullptr;
        Node *this_node = this->head_;
        Node *other_node = other.head_;
        size_type i = 0, j = 0;
        for (; i < this->size_ && j < other.size_;) {
          if (this_node->value < other_node->value) {
            if (tmp_head == nullptr) {
              tmp_head = this_node;
            }
            if (tmp != nullptr) {
              tmp->next = this_node;
            }
            this_node->previous = tmp;
            tmp = this_node;
            this_node = this_node->next;
            ++i;
          } else {
            if (tmp_head == nullptr) {
              tmp_head = other_node;
            }
            if (tmp != nullptr) {
              tmp->next = other_node;
            }
            other_node->previous = tmp;
            tmp = other_node;
            other_node = other_node->next;
            ++j;
          }
        }
        for (; i < this->size_; ++i) {
          tmp->next = this_node;
          this_node->previous = tmp;
          tmp = this_node;
          this_node = this_node->next;
        }
        for (; j < other.size_; ++j) {
          tmp->next = other_node;
          other_node->previous = tmp;
          tmp = other_node;
          other_node = other_node->next;
        }
        this->head_ = tmp_head;
        this->tail_->previous = tmp;
        tmp->next = tail_;
        this->size_ += other.size_;
      } else {
        this->head_ = other.head_;
        this->tail_->previous = other.tail_->previous;
        this->tail_->previous->next = this->tail_;
        this->size_ = other.size_;
      }
      other.tail_->previous = other.tail_;
      other.tail_->next = other.tail_;
      other.head_ = other.tail_;
      other.size_ = 0;
    }
  }
  void splice(const_iterator pos, list &other) noexcept {
    if (this != &other && other.size_ > 0) {
      pos.cur_->previous->next = other.head_;
      other.head_->previous = pos.cur_->previous;
      pos.cur_->previous = other.tail_->previous;
      other.tail_->previous->next = pos.cur_;
      if (this->head_ == pos.cur_) {
        this->head_ = other.head_;
      }
      this->size_ += other.size_;
      other.head_ = other.tail_;
      other.head_->next = other.tail_;
      other.head_->previous = other.tail_;
      other.size_ = 0;
    }
  }
  void reverse() noexcept {
    if (size_ > 0) {
      Node *tmp = head_;
      Node *tmp_next = nullptr;
      for (size_type i = 0; i < size_; ++i) {
        tmp_next = tmp->next;
        std::swap(tmp->next, tmp->previous);
        tmp = tmp_next;
      }
      std::swap(head_->next, tail_->previous->previous);
      std::swap(head_, tail_->previous);
    }
  }
  void unique() {
    Node *head = head_;
    Node *tmp = nullptr;
    for (size_type i = 0; i < size_;) {
      if (head->value == head->next->value) {
        tmp = head->next;
        head->next = tmp->next;
        head->next->previous = head;
        delete tmp;
        tmp = nullptr;
        --size_;
      } else {
        head = head->next;
        ++i;
      }
    }
  }
  void sort() noexcept {
    list hook;
    list tmp;
    for (size_type i = 0; i < size_; ++i) {
      tmp.head_ = head_;
      head_ = head_->next;
      head_->previous = nullptr;

      tmp.head_->previous = nullptr;
      tmp.head_->next = tmp.tail_;
      tmp.tail_->previous = tmp.head_;

      tmp.size_ = 1;
      hook.merge(tmp);
    }

    head_ = hook.head_;
    hook.tail_->previous->next = tail_;
    tail_->previous = hook.tail_->previous;

    hook.head_ = hook.tail_;
    hook.size_ = 0;
  }

  // Insert template
  template <typename... Args>
  iterator emplace(const_iterator pos, Args &&...args) {
    simplestl::list<value_type>::iterator iter;
    for (auto arg : {std::forward<Args>(args)...}) {
      iter = insert(pos, arg);
    }
    return iter;
  }
  template <typename... Args>
  void emplace_front(Args &&...args) {
    auto pos = begin();
    for (auto arg : {std::forward<Args>(args)...}) {
      insert(pos, arg);
    }
  }
  template <typename... Args>
  void emplace_back(Args &&...args) {
    for (auto arg : {std::forward<Args>(args)...}) {
      push_back(arg);
    }
  }

 private:
  struct Node {
    Node() : value(), previous(nullptr), next(nullptr) {}
    value_type value;
    Node *previous;
    Node *next;
  };

  Node *head_;
  Node *tail_;
  size_type size_;
};
}  // namespace simplestl

#endif  // SIMPLE_STL_LIST_H_