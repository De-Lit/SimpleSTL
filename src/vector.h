#ifndef SIMPLE_STL_VECTOR_H_
#define SIMPLE_STL_VECTOR_H_

#include <cstddef>
#include <initializer_list>
#include <stdexcept>

namespace simplestl {
template <typename T>
class vector {
 public:
  class VectorIterator;
  //  Member type
  typedef T value_type;
  typedef T &reference;
  typedef const T &const_reference;
  typedef std::size_t size_type;
  typedef VectorIterator iterator;
  typedef const VectorIterator const_iterator;

  class VectorIterator {
   public:
    VectorIterator() noexcept : cur_(nullptr) {}
    VectorIterator(value_type *first) noexcept : cur_(first) {}
    VectorIterator(const_iterator &iter) noexcept { this->cur_ = iter.cur_; }
    VectorIterator(iterator &&iter) noexcept : VectorIterator() {
      std::swap(this->cur_, iter.cur_);
    }
    iterator &operator=(const_iterator &iter) = default;
    iterator &operator=(iterator &&iter) noexcept {
      std::swap(this->cur_, iter.cur_);
      return *this;
    }
    ~VectorIterator() = default;

    reference operator*() noexcept { return *cur_; }
    iterator &operator++() noexcept {
      ++cur_;
      return *this;
    }
    iterator &operator--() noexcept {
      --cur_;
      return *this;
    }
    bool operator==(const_iterator &other) noexcept {
      return this->cur_ == other.cur_;
    }
    bool operator!=(const_iterator &other) noexcept {
      return this->cur_ != other.cur_;
    }

   private:
    value_type *cur_;
  };

  //  Functions
  vector() noexcept : arr_(nullptr), size_(0), capacity_(0) {}
  vector(size_type n) : vector() {
    if (n > max_size()) {
      throw std::runtime_error("length_error");
    }
    size_ = n;
    capacity_ = n;
    arr_ = new value_type[n + 1];
  }
  vector(std::initializer_list<value_type> const &items)
      : vector(items.size()) {
    auto iter = items.begin();
    for (size_type i = 0; i < items.size(); ++i) {
      this->arr_[i] = iter[i];
    }
  }
  vector(const vector &v) : vector(v.size_) {
    for (size_type i = 0; i < size_; ++i) {
      arr_[i] = v.arr_[i];
    }
  }
  vector(vector &&v) noexcept : vector() {
    std::swap(this->size_, v.size_);
    std::swap(this->capacity_, v.capacity_);
    std::swap(this->arr_, v.arr_);
  }
  vector &operator=(const vector &v) = delete;
  vector &operator=(vector &&v) noexcept {
    if (this->arr_ != nullptr) {
      delete[] this->arr_;
      this->arr_ = nullptr;
      this->size_ = 0;
      this->capacity_ = 0;
    }
    std::swap(this->size_, v.size_);
    std::swap(this->capacity_, v.capacity_);
    std::swap(this->arr_, v.arr_);
    return *this;
  }
  ~vector() { delete[] arr_; }

  //  Elements access
  reference at(size_type pos) {
    if (!(pos < size())) {
      throw std::runtime_error("out_of_range");
    }
    return arr_[pos];
  }
  reference operator[](size_type pos) { return at(pos); }
  const_reference front() noexcept { return arr_[0]; }
  const_reference back() noexcept { return arr_[size_ - 1]; }
  value_type *data() noexcept { return arr_; }

  //  Iterators
  iterator begin() noexcept {
    iterator iter(arr_);
    return iter;
  }
  iterator end() noexcept {
    iterator iter(arr_ + size_);
    return iter;
  }

  //  Capacity
  bool empty() noexcept { return begin() == end(); }
  size_type size() const noexcept { return size_; }
  size_type max_size() const noexcept {
    return SIZE_MAX / sizeof(value_type) / 2;
  }
  void reserve(size_type size) {
    if (size > capacity_) {
      if (size > max_size()) {
        throw std::runtime_error("length_error");
      }
      vector tmp(size);
      for (size_type i = 0; i < this->size_; ++i) {
        tmp.arr_[i] = this->arr_[i];
      }
      this->swap(tmp);
      this->size_ = tmp.size_;
    }
  }
  size_type capacity() const noexcept { return capacity_; }
  void shrink_to_fit() {
    if (size_ != capacity_) {
      vector tmp(this->size_);
      for (size_type i = 0; i < this->size_; ++i) {
        tmp.arr_[i] = this->arr_[i];
      }
      this->swap(tmp);
    }
  }

  //  Modifiers
  void clear() noexcept { size_ = 0; }
  iterator insert(iterator pos, const_reference value) {
    vector tmp(*this);
    if (tmp.capacity_ == 0) {
      tmp.reserve(1);
    } else if (tmp.size_ + 1 > tmp.capacity_) {
      tmp.reserve(tmp.capacity_ * 2);
    }
    ++tmp.size_;
    iterator iter_tmp = tmp.end();
    iterator iter_this = this->end();
    while (iter_this != pos) {
      --iter_this;
      --iter_tmp;
      *iter_tmp = *iter_this;
    }
    --iter_tmp;
    *iter_tmp = value;
    this->swap(tmp);
    return iter_tmp;
  }
  void erase(iterator pos) noexcept {
    iterator pos_next = pos;
    for (; pos_next != end(); ++pos) {
      ++pos_next;
      *pos = *pos_next;
    }
    --size_;
  }
  void push_back(const_reference value) {
    if (capacity_ == 0) {
      reserve(1);
    } else if (size_ == capacity_) {
      reserve(capacity_ * 2);
    }
    arr_[size_] = value;
    ++size_;
  }
  void pop_back() noexcept { --size_; }
  void swap(vector &other) noexcept {
    std::swap(this->size_, other.size_);
    std::swap(this->capacity_, other.capacity_);
    std::swap(this->arr_, other.arr_);
  }

  // Insert template
  template <typename... Args>
  iterator emplace(const_iterator pos, Args &&...args) {
    simplestl::vector<value_type> tmp(*this);
    tmp.reserve(sizeof...(args) + size_);
    tmp.size_ += sizeof...(args);
    iterator iter_tmp = tmp.end();
    iterator iter_this = this->end();
    while (iter_this != pos) {
      --iter_this;
      --iter_tmp;
      *iter_tmp = *iter_this;
    }
    simplestl::vector<value_type>::iterator iter_res(iter_tmp);
    --iter_res;
    for (unsigned long int i = 0; i < sizeof...(args); ++i) {
      --iter_tmp;
    }
    for (auto arg : {std::forward<Args>(args)...}) {
      *iter_tmp = arg;
      ++iter_tmp;
    }
    this->swap(tmp);
    return iter_res;
  }
  template <typename... Args>
  void emplace_back(Args &&...args) {
    reserve(sizeof...(args) + size_);
    for (auto arg : {std::forward<Args>(args)...}) {
      push_back(arg);
    }
  }

 private:
  value_type *arr_;
  size_type size_;
  size_type capacity_;
};
}  // namespace simplestl

#endif  // SIMPLE_STL_VECTOR_H_