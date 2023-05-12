#ifndef SIMPLE_STL_ARRAY_H_
#define SIMPLE_STL_ARRAY_H_

#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <stdexcept>

namespace simplestl {
template <typename T, std::size_t N>
class array {
 public:
  class ArrayIterator;

  //  Member type
  typedef T value_type;
  typedef T &reference;
  typedef const T &const_reference;
  typedef std::size_t size_type;
  typedef ArrayIterator iterator;
  typedef const ArrayIterator const_iterator;

  class ArrayIterator {
   public:
    ArrayIterator() noexcept : cur_(nullptr) {}
    ArrayIterator(value_type *first) noexcept : cur_(first) {}
    ArrayIterator(const_iterator &iter) noexcept : cur_(iter.cur_) {}
    ArrayIterator(iterator &&iter) noexcept : ArrayIterator() {
      std::swap(this->cur_, iter.cur_);
    }
    iterator &operator=(const_iterator &iter) = default;
    iterator &operator=(iterator &&iter) noexcept {
      std::swap(this->cur_, iter.cur_);
    }
    ~ArrayIterator() = default;

    reference operator*() { return *cur_; }
    iterator &operator++() {
      ++cur_;
      return *this;
    }
    iterator &operator--() {
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
  array() = default;
  array(std::initializer_list<value_type> const &items) : array() {
    if (items.size() > max_size()) {
      throw std::runtime_error("length_error");
    }
    auto iter = items.begin();
    for (size_type i = 0; i < items.size(); ++i) {
      arr_[i] = iter[i];
    }
  }
  array(const array &a) = default;
  array(array &&a) = default;
  array &operator=(const array &a) = delete;
  array &operator=(array &&a) noexcept {
    this->size_ = a.size_;
    for (size_type i = 0; i < size_; ++i) {
      this->arr_[i] = a.arr_[i];
    }
    return *this;
  }
  ~array() = default;

  //  Elements access
  reference at(size_type pos) {
    if (!(pos < size())) {
      throw std::runtime_error("out_of_range");
    }
    return arr_[pos];
  }
  reference operator[](size_type pos) { return at(pos); }
  const_reference front() { return arr_[0]; }
  const_reference back() { return arr_[size_ - 1]; }
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
  bool empty() const noexcept { return size_ == 0; }
  size_type size() const noexcept { return size_; }
  size_type max_size() const noexcept { return size_; }

  //  Modifiers
  void swap(array &other) noexcept {
    std::swap(this->arr_, other.arr_);
    std::swap(this->size_, other.size_);
  }
  void fill(const_reference value) noexcept {
    for (size_type i = 0; i < size_; ++i) {
      arr_[i] = value;
    }
  }

 private:
  value_type arr_[N + 1] = {};
  size_type size_ = N;
};
}  // namespace simplestl

#endif  // SIMPLE_STL_ARRAY_H_