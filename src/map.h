#ifndef SIMPLE_STL_MAP_H_
#define SIMPLE_STL_MAP_H_

#include <cstddef>
#include <initializer_list>
#include <stdexcept>

#include "vector.h"

namespace simplestl {
template <typename Key, typename T>
class map {
  struct Node;

 public:
  class MapIterator;

  //  Member type
  typedef Key key_type;
  typedef T mapped_type;
  typedef std::pair<const key_type, mapped_type> value_type;
  typedef value_type &reference;
  typedef const value_type &const_reference;
  typedef std::size_t size_type;
  typedef MapIterator iterator;
  typedef const MapIterator const_iterator;

  class MapIterator {
    friend class map;

   public:
    MapIterator() noexcept : cur_(nullptr), tail_(nullptr) {}
    MapIterator(Node *tail, Node *node) noexcept : cur_(node), tail_(tail) {}
    MapIterator(const_iterator &iter) noexcept {
      this->cur_ = iter.cur_;
      this->tail_ = iter.tail_;
    }
    MapIterator(iterator &&iter) noexcept : MapIterator() {
      std::swap(this->cur_, iter.cur_);
      std::swap(this->tail_, iter.tail_);
    }
    iterator &operator=(iterator &&iter) noexcept {
      std::swap(this->cur_, iter.cur_);
      std::swap(this->tail_, iter.tail_);
      return *this;
    }
    iterator &operator=(const_iterator &iter) = default;
    ~MapIterator() = default;

    std::pair<key_type, mapped_type> &operator*() noexcept {
      return cur_->data;
    }
    std::pair<key_type, mapped_type> *operator->() noexcept {
      return &cur_->data;
    }
    iterator &operator++() noexcept {
      cur_ = &next(cur_);
      return *this;
    }
    iterator &operator--() noexcept {
      cur_ = &previous(cur_);
      return *this;
    }
    bool operator==(const_iterator &other) noexcept {
      return this->cur_ == other.cur_;
    }
    bool operator!=(const_iterator &other) noexcept {
      return this->cur_ != other.cur_;
    }

   private:
    Node &minimum(Node *head) noexcept {
      if (head->left == tail_) {
        return *head;
      }
      return minimum(head->left);
    }
    Node &maximum(Node *head) noexcept {
      if (head->right == tail_) {
        return *head;
      }
      return maximum(head->right);
    }
    Node &next(Node *head) noexcept {
      if (head->right != tail_) {
        return minimum(head->right);
      }
      Node *tmp = head->parent;
      while (tmp != tail_ && head == tmp->right) {
        head = tmp;
        tmp = tmp->parent;
      }
      return *tmp;
    }
    Node &previous(Node *head) noexcept {
      if (head->left != tail_) {
        return maximum(head->left);
      }
      Node *tmp = head->parent;
      while (tmp != tail_ && head == tmp->left) {
        head = tmp;
        tmp = tmp->parent;
      }
      return *tmp;
    }
    Node *cur_;
    Node *tail_;
  };
  map() noexcept : root_(nullptr), tail_(nullptr), size_(0) {
    tail_ = new Node;
    root_ = tail_;
    tail_->parent = tail_;
    tail_->left = tail_;
    tail_->right = root_;
    tail_->color = false;
  }
  map(std::initializer_list<value_type> const &items) : map() {
    if (items.size() > max_size()) {
      throw std::runtime_error("length_error");
    }
    auto iter = items.begin();
    for (size_type i = 0; i < items.size(); ++i) {
      this->insert(iter[i]);
    }
  }
  map(const map &m) : map() {
    for (auto iter = m.begin(); iter != m.end(); ++iter) {
      this->insert(*iter);
    }
  }
  map(map &&m) noexcept : map() {
    std::swap(this->size_, m.size_);
    std::swap(this->root_, m.root_);
    std::swap(this->tail_, m.tail_);
  }
  map &operator=(map &&m) noexcept {
    this->swap(m);
    m.clear();
    return *this;
  }
  map &operator=(const map &m) = delete;
  ~map() {
    clear();
    delete tail_;
  }

  // Elements access
  mapped_type &at(const key_type &key) {
    auto res = &search(root_, key);
    if (res == tail_) {
      throw std::runtime_error("out_of_range");
    }
    return res->data.second;
  }
  mapped_type &operator[](const key_type &key) { return at(key); }

  //  Iterators
  iterator begin() noexcept {
    iterator iter(tail_, root_);
    return iterator(tail_, &iter.minimum(root_));
  }
  const_iterator begin() const noexcept {
    iterator iter(tail_, root_);
    return iterator(tail_, &iter.minimum(root_));
  }
  iterator end() noexcept { return iterator(tail_, tail_); }
  const_iterator end() const noexcept { return iterator(tail_, tail_); }

  //  Capacity
  bool empty() const noexcept { return root_ == tail_; }
  size_type size() const noexcept { return size_; }
  size_type max_size() const noexcept { return SIZE_MAX / sizeof(Node) / 2; }

  //  Modifiers
  void clear() noexcept {
    for (auto iter = begin(); iter != end(); iter = begin()) {
      erase(iter);
    }
  }
  std::pair<iterator, bool> insert(const value_type &value) {
    if (size_ + 1 > max_size()) {
      throw std::runtime_error("length_error");
    }
    Node *new_node = new Node;
    new_node->data = value;
    new_node->parent = new_node->left = new_node->right = tail_;
    auto head = &insert_node(new_node);
    if (head != nullptr) {
      return std::pair<iterator, bool>(iterator(tail_, head), false);
    }
    return std::pair<iterator, bool>(iterator(tail_, new_node), true);
  }
  std::pair<iterator, bool> insert(const key_type &key,
                                   const mapped_type &obj) {
    return insert(std::pair<const key_type, mapped_type>(key, obj));
  }
  std::pair<iterator, bool> insert_or_assign(const key_type &key,
                                             const mapped_type &obj) {
    auto pair = insert(key, obj);
    if (!pair.second) {
      pair.first.cur_->data.second = obj;
    }
    return pair;
  }
  void erase(iterator pos) noexcept {
    if (pos.cur_ != tail_) {
      Node *parent = pos.cur_->parent;
      if (pos.cur_->left == tail_ && pos.cur_->right == tail_) {
        if (parent->left == pos.cur_) {
          parent->left = tail_;
        }
        if (parent->right == pos.cur_) {
          parent->right = tail_;
        }
        if (root_ == pos.cur_) {
          root_ = parent;
        }
        if (tail_->parent == pos.cur_) {
          tail_->parent = parent;
          tail_->left = parent;
        }
        delete pos.cur_;
        pos.cur_ = nullptr;
        --size_;
      } else if (pos.cur_->left == tail_ || pos.cur_->right == tail_) {
        if (pos.cur_->left == tail_) {
          if (parent->left == pos.cur_) {
            parent->left = pos.cur_->right;
          } else {
            parent->right = pos.cur_->right;
          }
          pos.cur_->right->parent = parent;
          if (root_ == pos.cur_) {
            root_ = pos.cur_->right;
          }
        } else {
          if (parent->left == pos.cur_) {
            parent->left = pos.cur_->left;
          } else {
            parent->right = pos.cur_->left;
          }
          pos.cur_->left->parent = parent;
          if (root_ == pos.cur_) {
            root_ = pos.cur_->left;
          }
        }
        delete pos.cur_;
        pos.cur_ = nullptr;
        --size_;
      } else {
        auto successor(pos);
        ++successor;
        pos.cur_->data = successor.cur_->data;
        if (successor.cur_->parent->left == successor.cur_) {
          successor.cur_->parent->left = successor.cur_->right;
          if (successor.cur_->right != tail_) {
            successor.cur_->right->parent = successor.cur_->parent;
          }
        } else {
          successor.cur_->parent->right = successor.cur_->right;
          if (successor.cur_->right != tail_) {
            successor.cur_->right->parent = successor.cur_->parent;
          }
        }
        delete successor.cur_;
        successor.cur_ = nullptr;
        --size_;
      }
    }
  }
  void swap(map &other) noexcept {
    std::swap(this->root_, other.root_);
    std::swap(this->tail_, other.tail_);
    std::swap(this->size_, other.size_);
  }
  void merge(map &other) noexcept {
    if (this != &other && other.size_ > 0) {
      Node *merge_node = nullptr;
      map *tmp = new map;
      for (auto iter = other.begin(); other.size_ != 0;) {
        if (iter.cur_->left == other.tail_ && iter.cur_->right == other.tail_) {
          merge_node = iter.cur_;
          if (iter.cur_->parent->left == iter.cur_) {
            iter.cur_->parent->left = other.tail_;
          } else {
            iter.cur_->parent->right = other.tail_;
          }
          --other.size_;
          if (&this->search(root_, merge_node->data.first) == this->tail_) {
            merge_node->parent = this->tail_;
            merge_node->left = this->tail_;
            merge_node->right = this->tail_;
            this->insert_node(merge_node);
          } else {
            merge_node->parent = tmp->tail_;
            merge_node->left = tmp->tail_;
            merge_node->right = tmp->tail_;
            tmp->insert_node(merge_node);
          }
          merge_node = nullptr;
          if (other.size_) {
            iter = other.begin();
          }
        } else {
          ++iter;
        }
      }
      other.root_ = other.tail_;
      other.tail_->parent = other.tail_;
      other.tail_->left = other.tail_;
      other.tail_->right = other.root_;
      other.swap(*tmp);
      delete tmp;
    }
  }

  //  map Lookup
  bool contains(const key_type &key) noexcept {
    return tail_ != &search(root_, key);
  }

  // Insert template
  template <typename... Args>
  vector<std::pair<iterator, bool>> emplace(Args &&...args) {
    vector<std::pair<iterator, bool>> result;
    result.reserve(sizeof...(args));
    for (auto arg : {std::forward<Args>(args)...}) {
      result.push_back(insert(std::move(arg)));
    }
    return result;
  }

 private:
  struct Node {
    Node()
        : data(), left(nullptr), right(nullptr), parent(nullptr), color(true) {}
    std::pair<key_type, mapped_type> data;
    Node *left;
    Node *right;
    Node *parent;
    bool color;
  };

  Node &insert_node(Node *new_node) noexcept {
    Node *head = root_;
    if (root_ == tail_) {
      root_ = new_node;
      tail_->parent = new_node;
      tail_->left = new_node;
      tail_->right = root_;
      ++size_;
      head = nullptr;
    } else {
      while (head != tail_) {
        if (new_node->data.first > head->data.first) {
          if (head->right != tail_) {
            head = head->right;
          } else {
            new_node->parent = head;
            head->right = new_node;
            if (new_node->data.first > tail_->parent->data.first) {
              tail_->parent = new_node;
            }
            head = nullptr;
            ++size_;
            break;
          }
        } else if (new_node->data.first < head->data.first) {
          if (head->left != tail_) {
            head = head->left;
          } else {
            new_node->parent = head;
            head->left = new_node;
            head = nullptr;
            ++size_;
            break;
          }
        } else {
          delete new_node;
          break;
        }
      }
    }
    return *head;
  }
  Node &search(Node *node, const key_type &key) noexcept {
    if (node == tail_ || key == node->data.first) {
      return *node;
    }
    if (key < node->data.first) {
      return search(node->left, key);
    } else {
      return search(node->right, key);
    }
  }

  Node *root_;
  Node *tail_;
  size_type size_;
};
}  // namespace simplestl

#endif  // SIMPLE_STL_MAP_H_