#include <gtest/gtest.h>

#include <array>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#include "../simple_stl.h"

template <typename T>
void list_test_foo(simplestl::list<T> &a, std::list<T> &a_eth) {
  auto iter = a.begin();
  auto iter_eth = a_eth.begin();
  for (; iter != a.end() && iter_eth != a_eth.end(); ++iter, ++iter_eth) {
    ASSERT_EQ(*iter, *iter_eth);
  }
  iter = a.end();
  iter_eth = a_eth.end();
  for (; iter != a.begin() && iter_eth != a_eth.begin();) {
    --iter;
    --iter_eth;
    ASSERT_EQ(*iter, *iter_eth);
  }
  ASSERT_EQ(a.size(), a_eth.size());
}

template <typename Key, typename T>
void map_test_foo(simplestl::map<Key, T> &a, std::map<Key, T> &a_eth) {
  auto iter = a.begin();
  auto iter_eth = a_eth.begin();
  for (; iter != a.end() && iter_eth != a_eth.end(); ++iter, ++iter_eth) {
    ASSERT_EQ(iter->first, iter_eth->first);
    ASSERT_EQ(iter->second, iter_eth->second);
  }
  iter = a.end();
  iter_eth = a_eth.end();
  for (; iter != a.begin() && iter_eth != a_eth.begin();) {
    --iter;
    --iter_eth;
    ASSERT_EQ(iter->first, iter_eth->first);
    ASSERT_EQ(iter->second, iter_eth->second);
  }
  ASSERT_EQ(a.size(), a_eth.size());
}

template <typename T>
void multiset_test_foo(simplestl::multiset<T> &a, std::multiset<T> &a_eth) {
  auto iter = a.begin();
  auto iter_eth = a_eth.begin();
  for (; iter != a.end() && iter_eth != a_eth.end(); ++iter, ++iter_eth) {
    ASSERT_EQ(*iter, *iter_eth);
  }
  iter = a.end();
  iter_eth = a_eth.end();
  for (; iter != a.begin() && iter_eth != a_eth.begin();) {
    --iter;
    --iter_eth;
    ASSERT_EQ(*iter, *iter_eth);
  }
  ASSERT_EQ(a.size(), a_eth.size());
}

template <typename T>
void set_test_foo(simplestl::set<T> &a, std::set<T> &a_eth) {
  auto iter = a.begin();
  auto iter_eth = a_eth.begin();
  for (; iter != a.end() && iter_eth != a_eth.end(); ++iter, ++iter_eth) {
    ASSERT_EQ(*iter, *iter_eth);
  }
  iter = a.end();
  iter_eth = a_eth.end();
  for (; iter != a.begin() && iter_eth != a_eth.begin();) {
    --iter;
    --iter_eth;
    ASSERT_EQ(*iter, *iter_eth);
  }
  ASSERT_EQ(a.size(), a_eth.size());
}

TEST(array_default_constructor, 1) {
  // Arrange
  // Act
  simplestl::array<int, 0> a;
  // Assert
  std::array<int, 0> a_eth;
  ASSERT_EQ(a.size(), a_eth.size());
}

TEST(array_parameterized_constructor, 1) {
  // Arrange
  // Act
  simplestl::array<int, 3> a{1, 2, 3};
  // Assert
  std::array<int, 3> a_eth{1, 2, 3};
  ASSERT_EQ(a.size(), a_eth.size());
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

TEST(array_parameterized_constructor, 2) {
  // Arrange
  // Act
  simplestl::array<int, 3> a{1, 2, 3};
  // Assert
  std::array<int, 3> a_eth{1, 2, 3};
  ASSERT_EQ(a.size(), a_eth.size());
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

TEST(array_copy_constructor, 1) {
  // Arrange
  simplestl::array<int, 3> b{1, 2, 3};
  // Act
  simplestl::array<int, 3> a(b);
  // Assert
  std::array<int, 3> b_eth{1, 2, 3};
  std::array<int, 3> a_eth(b_eth);
  ASSERT_EQ(a.size(), a_eth.size());
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

TEST(array_move_constructor, 1) {
  // Arrange
  simplestl::array<int, 3> b{1, 2, 3};
  // Act
  simplestl::array<int, 3> a(std::move(b));
  // Assert
  std::array<int, 3> b_eth{1, 2, 3};
  std::array<int, 3> a_eth(std::move(b_eth));
  ASSERT_EQ(a.size(), a_eth.size());
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

TEST(array_eq_overriten_operator_r_value, 1) {
  // Arrange
  simplestl::array<int, 3> a;
  simplestl::array<int, 3> b{1, 2, 3};
  // Act
  a = std::move(b);
  // Assert
  std::array<int, 3> a_eth;
  std::array<int, 3> b_eth{1, 2, 3};
  a_eth = std::move(b_eth);
  ASSERT_EQ(a.size(), a_eth.size());
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

TEST(array_eq_overriten_operator_r_value, 2) {
  // Arrange
  simplestl::array<int, 3> a{3, 2, 1};
  simplestl::array<int, 3> b{1, 2, 3};
  // Act
  a = std::move(b);
  // Assert
  std::array<int, 3> a_eth{3, 2, 1};
  std::array<int, 3> b_eth{1, 2, 3};
  a_eth = std::move(b_eth);
  ASSERT_EQ(a.size(), a_eth.size());
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

TEST(array_at, 1) {
  // Arrange
  simplestl::array<int, 3> a{1, 2, 3};
  // Act
  // Assert
  std::array<int, 3> a_eth{1, 2, 3};
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a.at(i), a_eth.at(i));
  }
}

TEST(array_at, 2) {
  // Arrange
  simplestl::array<int, 3> a{1, 2, 3};
  // Act
  // Assert
  ASSERT_THROW(a.at(-1), std::runtime_error);
}

TEST(array_at, 3) {
  // Arrange
  simplestl::array<int, 3> a{1, 2, 3};
  // Act
  // Assert
  ASSERT_THROW(a.at(10), std::runtime_error);
}

TEST(array_SquareBrackets, 1) {
  // Arrange
  simplestl::array<int, 3> a{1, 2, 3};
  // Act
  // Assert
  std::array<int, 3> a_eth{1, 2, 3};
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

TEST(array_square_brackets, 2) {
  // Arrange
  simplestl::array<int, 3> a{1, 2, 3};
  // Act
  // Assert
  ASSERT_THROW(a[-1], std::runtime_error);
}

TEST(array_square_brackets, 3) {
  // Arrange
  simplestl::array<int, 3> a{1, 2, 3};
  // Act
  // Assert
  ASSERT_THROW(a[10], std::runtime_error);
}

TEST(array_front, 1) {
  // Arrange
  simplestl::array<int, 3> a{1, 2, 3};
  // Act
  // Assert
  std::array<int, 3> a_eth{1, 2, 3};
  ASSERT_EQ(a.front(), a_eth.front());
}

TEST(array_back, 1) {
  // Arrange
  simplestl::array<int, 3> a{1, 2, 3};
  // Act
  // Assert
  std::array<int, 3> a_eth{1, 2, 3};
  ASSERT_EQ(a.back(), a_eth.back());
}

TEST(array_back, 2) {
  // Arrange
  simplestl::array<int, 1> a{1};
  // Act
  // Assert
  std::array<int, 1> a_eth{1};
  ASSERT_EQ(a.back(), a_eth.back());
}

TEST(array_data, 1) {
  // Arrange
  simplestl::array<int, 3> a{1, 2, 3};
  // Act
  int *add = a.data();
  // Assert
  std::array<int, 3> a_eth{1, 2, 3};
  int *add_eth = a_eth.data();
  ASSERT_EQ(*add, *add_eth);
}

TEST(array_begin, 1) {
  // Arrange
  simplestl::array<int, 3> a{1, 2, 3};
  // Act
  simplestl::array<int, 3>::iterator iter = a.begin();
  // Assert
  std::array<int, 3> a_eth{1, 2, 3};
  std::array<int, 3>::iterator iter_eth = a_eth.begin();
  ASSERT_EQ(*iter, *iter_eth);
}

TEST(array_end, 1) {
  // Arrange
  simplestl::array<int, 3> a{1, 2, 3};
  // Act
  simplestl::array<int, 3>::iterator iter = a.end();
  // Assert
  std::array<int, 3> a_eth{1, 2, 3};
  std::array<int, 3>::iterator iter_eth = a_eth.end();
  ASSERT_EQ(*--iter, *--iter_eth);
}

TEST(array_empty, 1) {
  // Arrange
  simplestl::array<int, 3> a{1, 2, 3};
  // Act
  // Assert
  std::array<int, 3> a_eth{1, 2, 3};
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(array_empty, 2) {
  // Arrange
  simplestl::array<int, 5> a{};
  // Act
  // Assert
  std::array<int, 5> a_eth{};
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(array_empty, 3) {
  // Arrange
  simplestl::array<int, 0> a;
  // Act
  // Assert
  std::array<int, 0> a_eth;
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(array_size, 1) {
  // Arrange
  simplestl::array<int, 3> a{1, 2, 3};
  // Act
  // Assert
  std::array<int, 3> a_eth{1, 2, 3};
  ASSERT_EQ(a.size(), a_eth.size());
}

TEST(array_max_size, 1) {
  // Arrange
  simplestl::array<int, 1> a{};
  // Act
  // Assert
  std::array<int, 1> a_eth{};
  ASSERT_EQ(a.max_size(), a_eth.max_size());
}

TEST(array_max_size, 2) {
  // Arrange
  simplestl::array<std::string, 1> a{};
  // Act
  // Assert
  std::array<std::string, 1> a_eth{};
  ASSERT_EQ(a.max_size(), a_eth.max_size());
}

TEST(array_swap, 1) {
  // Arrange
  simplestl::array<int, 3> a{1, 2, 3};
  simplestl::array<int, 3> b{4, 5};
  // Act
  a.swap(b);
  // Assert
  std::array<int, 3> a_eth{1, 2, 3};
  std::array<int, 3> b_eth{4, 5};
  a_eth.swap(b_eth);
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
  ASSERT_EQ(a.size(), a_eth.size());
  for (size_t i = 0; i < b.size(); i++) {
    ASSERT_EQ(b[i], b_eth[i]);
  }
  ASSERT_EQ(b.size(), b_eth.size());
}

TEST(array_swap, 2) {
  // Arrange
  simplestl::array<int, 3> a{1, 2, 3};
  simplestl::array<int, 3> b;
  // Act
  a.swap(b);
  // Assert
  std::array<int, 3> a_eth{1, 2, 3};
  std::array<int, 3> b_eth;
  a_eth.swap(b_eth);
  ASSERT_EQ(a.size(), a_eth.size());
  for (size_t i = 0; i < b.size(); i++) {
    ASSERT_EQ(b[i], b_eth[i]);
  }
  ASSERT_EQ(b.size(), b_eth.size());
}

TEST(array_swap, 3) {
  // Arrange
  simplestl::array<int, 3> a{1, 2, 3};
  // Act
  a.swap(a);
  // Assert
  std::array<int, 3> a_eth{1, 2, 3};
  a_eth.swap(a_eth);
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
  ASSERT_EQ(a.size(), a_eth.size());
}

TEST(array_fill, 1) {
  // Arrange
  simplestl::array<int, 7> a;
  // Act
  a.fill(7);
  // Assert
  std::array<int, 7> a_eth;
  a_eth.fill(7);
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
  ASSERT_EQ(a.size(), a_eth.size());
}

TEST(array_fill, 2) {
  // Arrange
  simplestl::array<int, 3> a{1, 2, 3};
  // Act
  a.fill(7);
  // Assert
  std::array<int, 3> a_eth{1, 2, 3};
  a_eth.fill(7);
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
  ASSERT_EQ(a.size(), a_eth.size());
}

TEST(array_begin_iter, 1) {
  // Arrange
  simplestl::array<int, 3> a{1, 2, 3};
  // Act
  auto iter = a.begin();
  // Assert
  std::array<int, 3> a_eth{1, 2, 3};
  auto iter_eth = a_eth.begin();
  ASSERT_EQ(*iter, *iter_eth);
}

TEST(array_end_iter, 1) {
  // Arrange
  simplestl::array<int, 3> a{1, 2, 3};
  // Act
  auto iter = a.end();
  // Assert
  std::array<int, 3> a_eth{1, 2, 3};
  auto iter_eth = a_eth.end();
  --iter;
  --iter_eth;
  ASSERT_EQ(*iter, *iter_eth);
}

TEST(array_iterator_methods, 1) {
  // Arrange
  simplestl::array<int, 3> a{1, 2, 3};
  // Act
  auto iter = a.begin();
  // Assert
  std::array<int, 3> a_eth{1, 2, 3};
  auto iter_eth = a_eth.begin();
  for (; iter != a.end(); ++iter, ++iter_eth) {
    ASSERT_EQ(*iter, *iter_eth);
  }
}

TEST(array_iterator_methods, 2) {
  // Arrange
  simplestl::array<int, 3> a{1, 2, 3};
  // Act
  auto iter = a.end();
  // Assert
  std::array<int, 3> a_eth{1, 2, 3};
  auto iter_eth = a_eth.end();
  for (; iter != a.begin();) {
    --iter;
    --iter_eth;
    ASSERT_EQ(*iter, *iter_eth);
  }
}

TEST(list_default_constructor, 1) {
  // Arrange
  // Act
  simplestl::list<int> a;
  // Assert
  std::list<int> a_eth;
  ASSERT_EQ(a.size(), a_eth.size());
}

TEST(list_parameterized_constructor, 1) {
  // Arrange
  // Act
  simplestl::list<int> a(5);
  // Assert
  std::vector<int> a_eth(5);
  ASSERT_EQ(a.size(), a_eth.size());
}

TEST(list_parameterized_constructor, 2) {
  // Arrange
  simplestl::list<int> a;
  // Act
  // Assert
  ASSERT_THROW(simplestl::list<int> b(a.max_size() + 1);, std::runtime_error);
}

TEST(list_parameterized_constructor, 3) {
  // Arrange
  // Act
  simplestl::list<int> a{1, 2, 3};
  // Assert
  std::list<int> a_eth{1, 2, 3};
  list_test_foo(a, a_eth);
}

TEST(list_copy_constructor, 1) {
  // Arrange
  simplestl::list<int> b{1, 2, 3};
  // Act
  simplestl::list<int> a(b);
  // Assert
  std::list<int> b_eth{1, 2, 3};
  std::list<int> a_eth(b_eth);
  list_test_foo(a, a_eth);
}

TEST(list_move_constructor, 1) {
  // Arrange
  simplestl::list<int> b{1, 2, 3};
  // Act
  simplestl::list<int> a(std::move(b));
  // Assert
  std::list<int> b_eth{1, 2, 3};
  std::list<int> a_eth(std::move(b_eth));
  list_test_foo(a, a_eth);
}

TEST(list_eq_overriten_operator_r_value, 1) {
  // Arrange
  simplestl::list<int> a;
  simplestl::list<int> b{1, 2, 3};
  // Act
  a = std::move(b);
  // Assert
  std::list<int> b_eth{1, 2, 3};
  std::list<int> a_eth;
  a_eth = std::move(b_eth);
  list_test_foo(a, a_eth);
}

TEST(list_eq_overriten_operator_r_value, 2) {
  // Arrange
  simplestl::list<int> a{3, 2, 1};
  simplestl::list<int> b{1, 2, 3};
  // Act
  a = std::move(b);
  // Assert
  std::list<int> a_eth{3, 2, 1};
  std::list<int> b_eth{1, 2, 3};
  a_eth = std::move(b_eth);
  list_test_foo(a, a_eth);
}

TEST(list_front, 1) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  // Act
  // Assert
  std::list<int> a_eth{1, 2, 3};
  ASSERT_EQ(a.front(), a_eth.front());
}

TEST(list_back, 1) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  // Act
  // Assert
  std::list<int> a_eth{1, 2, 3};
  ASSERT_EQ(a.back(), a_eth.back());
}

TEST(list_back, 2) {
  // Arrange
  simplestl::list<int> a{1};
  // Act
  // Assert
  std::list<int> a_eth{1};
  ASSERT_EQ(a.back(), a_eth.back());
}

TEST(list_begin_iter, 1) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  // Act
  simplestl::list<int>::iterator iter = a.begin();
  // Assert
  std::list<int> a_eth{1, 2, 3};
  std::list<int>::iterator iter_eth = a_eth.begin();
  ASSERT_EQ(*iter, *iter_eth);
}

TEST(list_end_iter, 1) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  // Act
  simplestl::list<int>::iterator iter = a.end();
  // Assert
  std::list<int> a_eth{1, 2, 3};
  std::list<int>::iterator iter_eth = a_eth.end();
  ASSERT_EQ(*--iter, *--iter_eth);
}

TEST(list_end_iter, 2) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  // Act
  simplestl::list<int>::iterator iter = a.end();
  // Assert
  std::list<int> a_eth{1, 2, 3};
  std::list<int>::iterator iter_eth = a_eth.end();
  ASSERT_EQ(*--iter, *--iter_eth);
}

TEST(list_iterator_methods, 1) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  // Act
  auto iter = a.begin();
  // Assert
  std::list<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.begin();
  for (; iter != a.end(); ++iter, ++iter_eth) {
    ASSERT_EQ(*iter, *iter_eth);
  }
}

TEST(list_iterator_methods, 2) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  // Act
  auto iter = a.end();
  // Assert
  std::list<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.end();
  for (; iter != a.begin();) {
    --iter;
    --iter_eth;
    ASSERT_EQ(*iter, *iter_eth);
  }
}

TEST(list_empty, 1) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  // Act
  // Assert
  std::list<int> a_eth{1, 2, 3};
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(list_empty, 2) {
  // Arrange
  simplestl::list<int> a;
  // Act
  // Assert
  std::list<int> a_eth;
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(list_empty, 3) {
  // Arrange
  simplestl::list<int> a(0);
  // Act
  // Assert
  std::list<int> a_eth(0);
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(list_size, 1) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  // Act
  // Assert
  std::list<int> a_eth{1, 2, 3};
  ASSERT_EQ(a.size(), a_eth.size());
}

TEST(list_max_size, 1) {
  // Arrange
  simplestl::list<int> a;
  // Act
  // Assert
  std::list<int> a_eth;
  ASSERT_EQ(a.max_size(), a_eth.max_size());
}

TEST(list_max_size, 2) {
  // Arrange
  simplestl::list<std::string> a;
  // Act
  // Assert
  std::list<std::string> a_eth;
  ASSERT_EQ(a.max_size(), a_eth.max_size());
}

TEST(list_clear, 1) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  // Act
  a.clear();
  // Assert
  std::list<int> a_eth{1, 2, 3};
  a_eth.clear();
  ASSERT_EQ(a.size(), a_eth.size());
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(list_insert, 1) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  auto iter = a.begin();
  // Act
  a.insert(iter, 7);
  // Assert
  std::list<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.begin();
  a_eth.insert(iter_eth, 7);
  list_test_foo(a, a_eth);
}

TEST(list_insert, 2) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  auto iter = a.end();
  // Act
  a.insert(iter, 7);
  // Assert
  std::list<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.end();
  a_eth.insert(iter_eth, 7);
  list_test_foo(a, a_eth);
}

TEST(list_insert, 3) {
  // Arrange
  simplestl::list<int> a;
  auto iter = a.begin();
  // Act
  a.insert(iter, 7);
  // Assert
  std::list<int> a_eth;
  auto iter_eth = a_eth.begin();
  a_eth.insert(iter_eth, 7);
  list_test_foo(a, a_eth);
}

TEST(list_insert, 4) {
  // Arrange
  simplestl::list<int> a;
  auto iter = a.end();
  // Act
  a.insert(iter, 7);
  // Assert
  std::list<int> a_eth;
  auto iter_eth = a_eth.end();
  a_eth.insert(iter_eth, 7);
  list_test_foo(a, a_eth);
}

TEST(list_insert, 5) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  auto iter = a.begin();
  // Act
  ++iter;
  a.insert(iter, 7);
  // Assert
  std::list<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.begin();
  ++iter_eth;
  a_eth.insert(iter_eth, 7);
  list_test_foo(a, a_eth);
}

TEST(list_erase, 1) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  auto iter = a.begin();
  // Act
  a.erase(iter);
  // Assert
  std::list<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.begin();
  a_eth.erase(iter_eth);
  list_test_foo(a, a_eth);
}

TEST(list_erase, 2) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  auto iter = a.end();
  // Act
  --iter;
  a.erase(iter);
  // Assert
  std::list<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.end();
  --iter_eth;
  a_eth.erase(iter_eth);
  list_test_foo(a, a_eth);
}

TEST(list_erase, 3) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  auto iter = a.begin();
  ++iter;
  // Act
  a.erase(iter);
  // Assert
  std::list<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.begin();
  ++iter_eth;
  a_eth.erase(iter_eth);
  list_test_foo(a, a_eth);
}

TEST(list_push_back, 1) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  // Act
  a.push_back(7);
  // Assert
  std::list<int> a_eth{1, 2, 3};
  a_eth.push_back(7);
  list_test_foo(a, a_eth);
}

TEST(list_push_back, 2) {
  // Arrange
  simplestl::list<int> a;
  // Act
  a.push_back(7);
  // Assert
  std::list<int> a_eth;
  a_eth.push_back(7);
  list_test_foo(a, a_eth);
}

TEST(list_pop_back, 1) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  // Act
  a.pop_back();
  // Assert
  std::list<int> a_eth{1, 2, 3};
  a_eth.pop_back();
  list_test_foo(a, a_eth);
}

TEST(list_pop_back, 2) {
  // Arrange
  simplestl::list<int> a{1};
  // Act
  a.pop_back();
  // Assert
  std::list<int> a_eth{1};
  a_eth.pop_back();
  list_test_foo(a, a_eth);
}

TEST(list_push_front, 1) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  // Act
  a.push_front(7);
  // Assert
  std::list<int> a_eth{1, 2, 3};
  a_eth.push_front(7);
  list_test_foo(a, a_eth);
}

TEST(list_push_front, 2) {
  // Arrange
  simplestl::list<int> a;
  // Act
  a.push_front(7);
  // Assert
  std::list<int> a_eth;
  a_eth.push_front(7);
  list_test_foo(a, a_eth);
}

TEST(list_pop_front, 1) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  // Act
  a.pop_front();
  // Assert
  std::list<int> a_eth{1, 2, 3};
  a_eth.pop_front();
  list_test_foo(a, a_eth);
}

TEST(list_pop_front, 2) {
  // Arrange
  simplestl::list<int> a{1};
  // Act
  a.pop_front();
  // Assert
  std::list<int> a_eth{1};
  a_eth.pop_front();
  list_test_foo(a, a_eth);
}

TEST(list_swap, 1) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  simplestl::list<int> b{4, 5};
  // Act
  a.swap(b);
  // Assert
  std::list<int> a_eth{1, 2, 3};
  std::list<int> b_eth{4, 5};
  a_eth.swap(b_eth);
  list_test_foo(a, a_eth);
  list_test_foo(b, b_eth);
}

TEST(list_swap, 2) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  simplestl::list<int> b;
  // Act
  a.swap(b);
  // Assert
  std::list<int> a_eth{1, 2, 3};
  std::list<int> b_eth;
  a_eth.swap(b_eth);
  list_test_foo(a, a_eth);
  list_test_foo(b, b_eth);
}

TEST(list_swap, 3) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  // Act
  a.swap(a);
  // Assert
  std::list<int> a_eth{1, 2, 3};
  a_eth.swap(a_eth);
  list_test_foo(a, a_eth);
}

TEST(list_merge, 1) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  simplestl::list<int> b{4, 5};
  // Act
  a.merge(b);
  // Assert
  std::list<int> a_eth{1, 2, 3};
  std::list<int> b_eth{4, 5};
  a_eth.merge(b_eth);
  list_test_foo(a, a_eth);
  list_test_foo(b, b_eth);
}

TEST(list_merge, 2) {
  // Arrange
  simplestl::list<int> a;
  simplestl::list<int> b{4, 5};
  // Act
  a.merge(b);
  // Assert
  std::list<int> a_eth;
  std::list<int> b_eth{4, 5};
  a_eth.merge(b_eth);
  list_test_foo(a, a_eth);
  list_test_foo(b, b_eth);
}

TEST(list_merge, 3) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  simplestl::list<int> b;
  // Act
  a.merge(b);
  // Assert
  std::list<int> a_eth{1, 2, 3};
  std::list<int> b_eth;
  a_eth.merge(b_eth);
  list_test_foo(a, a_eth);
  list_test_foo(b, b_eth);
}

TEST(list_merge, 4) {
  // Arrange
  simplestl::list<int> a{7, 8, 9};
  simplestl::list<int> b{1, 2, 3};
  // Act
  a.merge(b);
  // Assert
  std::list<int> a_eth{7, 8, 9};
  std::list<int> b_eth{1, 2, 3};
  a_eth.merge(b_eth);
  list_test_foo(a, a_eth);
  list_test_foo(b, b_eth);
}

TEST(list_splice, 1) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  simplestl::list<int> b{4, 5};
  // Act
  auto iter = a.begin();
  a.splice(iter, b);
  // Assert
  std::list<int> a_eth{1, 2, 3};
  std::list<int> b_eth{4, 5};
  auto iter_eth = a_eth.begin();
  a_eth.splice(iter_eth, b_eth);
  list_test_foo(a, a_eth);
  list_test_foo(b, b_eth);
}

TEST(list_splice, 2) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  simplestl::list<int> b{4, 5};
  // Act
  auto iter = a.begin();
  ++iter;
  a.splice(iter, b);
  // Assert
  std::list<int> a_eth{1, 2, 3};
  std::list<int> b_eth{4, 5};
  auto iter_eth = a_eth.begin();
  ++iter_eth;
  a_eth.splice(iter_eth, b_eth);
  list_test_foo(a, a_eth);
  list_test_foo(b, b_eth);
}

TEST(list_splice, 3) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  simplestl::list<int> b{4, 5};
  // Act
  auto iter = a.end();
  --iter;
  a.splice(iter, b);
  // Assert
  std::list<int> a_eth{1, 2, 3};
  std::list<int> b_eth{4, 5};
  auto iter_eth = a_eth.end();
  --iter_eth;
  a_eth.splice(iter_eth, b_eth);
  list_test_foo(a, a_eth);
  list_test_foo(b, b_eth);
}

TEST(list_splice, 4) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  simplestl::list<int> b{4, 5};
  // Act
  auto iter = a.end();
  a.splice(iter, b);
  // Assert
  std::list<int> a_eth{1, 2, 3};
  std::list<int> b_eth{4, 5};
  auto iter_eth = a_eth.end();
  a_eth.splice(iter_eth, b_eth);
  list_test_foo(a, a_eth);
  list_test_foo(b, b_eth);
}

TEST(list_splice, 5) {
  // Arrange
  simplestl::list<int> a;
  simplestl::list<int> b{4, 5};
  // Act
  auto iter = a.begin();
  a.splice(iter, b);
  // Assert
  std::list<int> a_eth;
  std::list<int> b_eth{4, 5};
  auto iter_eth = a_eth.begin();
  a_eth.splice(iter_eth, b_eth);
  list_test_foo(a, a_eth);
  list_test_foo(b, b_eth);
}

TEST(list_splice, 6) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  simplestl::list<int> b;
  // Act
  auto iter = a.begin();
  a.splice(iter, b);
  // Assert
  std::list<int> a_eth{1, 2, 3};
  std::list<int> b_eth;
  auto iter_eth = a_eth.begin();
  a_eth.splice(iter_eth, b_eth);
  list_test_foo(a, a_eth);
  list_test_foo(b, b_eth);
}

TEST(list_reverse, 1) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  // Act
  a.reverse();
  // Assert
  std::list<int> a_eth{1, 2, 3};
  a_eth.reverse();
  list_test_foo(a, a_eth);
}

TEST(list_reverse, 2) {
  // Arrange
  simplestl::list<int> a;
  // Act
  a.reverse();
  // Assert
  std::list<int> a_eth;
  a_eth.reverse();
  list_test_foo(a, a_eth);
}

TEST(list_reverse, 3) {
  // Arrange
  simplestl::list<int> a{1};
  // Act
  a.reverse();
  // Assert
  std::list<int> a_eth{1};
  a_eth.reverse();
  list_test_foo(a, a_eth);
}

TEST(list_unique, 1) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  // Act
  a.unique();
  // Assert
  std::list<int> a_eth{1, 2, 3};
  a_eth.unique();
  list_test_foo(a, a_eth);
}

TEST(list_unique, 2) {
  // Arrange
  simplestl::list<int> a{1, 1, 1, 2, 3};
  // Act
  a.unique();
  // Assert
  std::list<int> a_eth{1, 1, 1, 2, 3};
  a_eth.unique();
  list_test_foo(a, a_eth);
}

TEST(list_unique, 3) {
  // Arrange
  simplestl::list<int> a{1};
  // Act
  a.unique();
  // Assert
  std::list<int> a_eth{1};
  a_eth.unique();
  list_test_foo(a, a_eth);
}

TEST(list_unique, 4) {
  // Arrange
  simplestl::list<int> a{1, 1, 1, 2, 3, 1, 1, 7, 7};
  // Act
  a.unique();
  // Assert
  std::list<int> a_eth{1, 1, 1, 2, 3, 1, 1, 7, 7};
  a_eth.unique();
  list_test_foo(a, a_eth);
}

TEST(list_sort, 1) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  // Act
  a.sort();
  // Assert
  std::list<int> a_eth{1, 2, 3};
  a_eth.sort();
  list_test_foo(a, a_eth);
}

TEST(list_sort, 2) {
  // Arrange
  simplestl::list<int> a{1};
  // Act
  a.sort();
  // Assert
  std::list<int> a_eth{1};
  a_eth.sort();
  list_test_foo(a, a_eth);
}

TEST(list_sort, 3) {
  // Arrange
  simplestl::list<int> a{3, 2, 7, 8, 1, -1};
  // Act
  a.sort();
  // Assert
  std::list<int> a_eth{3, 2, 7, 8, 1, -1};
  a_eth.sort();
  list_test_foo(a, a_eth);
}

TEST(list_emplace, 1) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  // Act
  auto iter = a.begin();
  iter = a.emplace(iter, 3, 2, 7, 8, 1, -1);
  // Assert
  ASSERT_EQ(*iter, -1);
  std::list<int> a_eth{3, 2, 7, 8, 1, -1, 1, 2, 3};
  list_test_foo(a, a_eth);
}

TEST(list_emplace_front, 1) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  // Act
  a.emplace_front(3, 2, 7, 8, 1, -1);
  // Assert
  std::list<int> a_eth{3, 2, 7, 8, 1, -1, 1, 2, 3};
  list_test_foo(a, a_eth);
}

TEST(list_emplace_back, 1) {
  // Arrange
  simplestl::list<int> a{1, 2, 3};
  // Act
  a.emplace_back(3, 2, 7, 8, 1, -1);
  // Assert
  std::list<int> a_eth{1, 2, 3, 3, 2, 7, 8, 1, -1};
  list_test_foo(a, a_eth);
}

TEST(map_default_constructor, 1) {
  // Arrange
  // Act
  simplestl::map<int, std::string> a;
  // Assert
  std::map<int, std::string> a_eth;
  map_test_foo(a, a_eth);
}

TEST(map_parameterized_constructor, 1) {
  // Arrange
  // Act
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  map_test_foo(a, a_eth);
}

TEST(map_copy_constructor, 1) {
  // Arrange
  simplestl::map<int, std::string> b{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  simplestl::map<int, std::string> a(b);
  // Assert
  std::map<int, std::string> b_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  std::map<int, std::string> a_eth(b_eth);
  map_test_foo(a, a_eth);
}

TEST(map_move_constructor, 1) {
  // Arrange
  simplestl::map<int, std::string> b{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  simplestl::map<int, std::string> a(std::move(b));
  // Assert
  std::map<int, std::string> b_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  std::map<int, std::string> a_eth(std::move(b_eth));
  map_test_foo(a, a_eth);
  map_test_foo(b, b_eth);
}

TEST(map_eq_overriten_operator_r_value, 1) {
  // Arrange
  simplestl::map<int, std::string> a;
  simplestl::map<int, std::string> b{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  a = std::move(b);
  // Assert
  std::map<int, std::string> b_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  std::map<int, std::string> a_eth;
  a_eth = std::move(b_eth);
  map_test_foo(a, a_eth);
  map_test_foo(b, b_eth);
}

TEST(map_eq_overriten_operator_r_value, 2) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  simplestl::map<int, std::string> b{std::pair<int, std::string>(4, "4"),
                                     std::pair<int, std::string>(4, "4"),
                                     std::pair<int, std::string>(4, "4")};
  // Act
  a = std::move(b);
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  std::map<int, std::string> b_eth{std::pair<int, std::string>(4, "4"),
                                   std::pair<int, std::string>(4, "4"),
                                   std::pair<int, std::string>(4, "4")};
  a_eth = std::move(b_eth);
  map_test_foo(a, a_eth);
  map_test_foo(b, b_eth);
}

TEST(map_begin_iter, 1) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  auto iter = a.begin();
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  auto iter_eth = a_eth.begin();
  ASSERT_EQ(iter->first, iter_eth->first);
  ASSERT_EQ(iter->second, iter_eth->second);
}

TEST(map_end_iter, 1) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  auto iter = a.end();
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  auto iter_eth = a_eth.end();
  --iter;
  --iter_eth;
  ASSERT_EQ(iter->first, iter_eth->first);
  ASSERT_EQ(iter->second, iter_eth->second);
}

TEST(map_iterator_methods, 1) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  auto iter = a.begin();
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  auto iter_eth = a_eth.begin();
  for (; iter != a.end(); ++iter, ++iter_eth) {
    ASSERT_EQ(iter->first, iter_eth->first);
    ASSERT_EQ(iter->second, iter_eth->second);
  }
}

TEST(map_iterator_methods, 2) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  auto iter = a.begin();
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  auto iter_eth = a_eth.end();
  for (; iter != a.begin();) {
    --iter;
    --iter_eth;
    ASSERT_EQ(iter->first, iter_eth->first);
    ASSERT_EQ(iter->second, iter_eth->second);
  }
}

TEST(map_at, 1) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  ASSERT_EQ(a.at(1), a_eth.at(1));
  ASSERT_EQ(a.at(2), a_eth.at(2));
  ASSERT_EQ(a.at(3), a_eth.at(3));
}

TEST(map_at, 2) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  // Assert
  ASSERT_THROW(a.at(-1), std::runtime_error);
}

TEST(map_at, 3) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  // Assert
  ASSERT_THROW(a.at(10), std::runtime_error);
}

TEST(map_square_brackets, 1) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  ASSERT_EQ(a[1], a_eth[1]);
  ASSERT_EQ(a[2], a_eth[2]);
  ASSERT_EQ(a[3], a_eth[3]);
}

TEST(map_square_brackets, 2) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  // Assert
  ASSERT_THROW(a[-1], std::runtime_error);
}

TEST(map_square_brackets, 3) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  // Assert
  ASSERT_THROW(a[10], std::runtime_error);
}

TEST(map_empty, 1) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(map_empty, 2) {
  // Arrange
  simplestl::map<int, std::string> a;
  // Act
  // Assert
  std::map<int, std::string> a_eth;
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(map_size, 1) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  ASSERT_EQ(a.size(), a_eth.size());
}

TEST(map_max_size, 1) {
  // Arrange
  simplestl::map<int, std::string> a;
  // Act
  // Assert
  std::map<int, std::string> a_eth;
  ASSERT_EQ(a.max_size(), a_eth.max_size());
}

TEST(map_max_size, 2) {
  // Arrange
  simplestl::map<int, int> a;
  // Act
  // Assert
  std::map<int, int> a_eth;
  ASSERT_EQ(a.max_size(), a_eth.max_size());
}

TEST(map_clear, 1) {
  // Arrange
  simplestl::map<int, int> a{std::pair<int, int>(1, 1),
                             std::pair<int, int>(2, 2),
                             std::pair<int, int>(2, 3)};
  // Act
  a.clear();
  // Assert
  std::map<int, int> a_eth{std::pair<int, int>(1, 1), std::pair<int, int>(2, 2),
                           std::pair<int, int>(2, 3)};
  a_eth.clear();
  map_test_foo(a, a_eth);
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(map_clear, 2) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(7, "7"),
                                     std::pair<int, std::string>(5, "5"),
                                     std::pair<int, std::string>(4, "4"),
                                     std::pair<int, std::string>(6, "6"),
                                     std::pair<int, std::string>(9, "9"),
                                     std::pair<int, std::string>(8, "8"),
                                     std::pair<int, std::string>(10, "10"),
                                     std::pair<int, std::string>(11, "11"),
                                     std::pair<int, std::string>(-5, "-5")};
  // Act
  a.clear();
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(7, "7"),
                                   std::pair<int, std::string>(5, "5"),
                                   std::pair<int, std::string>(4, "4"),
                                   std::pair<int, std::string>(6, "6"),
                                   std::pair<int, std::string>(9, "9"),
                                   std::pair<int, std::string>(8, "8"),
                                   std::pair<int, std::string>(10, "10"),
                                   std::pair<int, std::string>(11, "11"),
                                   std::pair<int, std::string>(-5, "-5")};
  a_eth.clear();
  map_test_foo(a, a_eth);
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(map_clear, 3) {
  // Arrange
  simplestl::map<int, std::string> a{
      std::pair<int, std::string>(1, "1"), std::pair<int, std::string>(2, "2"),
      std::pair<int, std::string>(3, "3"), std::pair<int, std::string>(4, "4"),
      std::pair<int, std::string>(5, "5")};
  // Act
  a.clear();
  // Assert
  std::map<int, std::string> a_eth{
      std::pair<int, std::string>(1, "1"), std::pair<int, std::string>(2, "2"),
      std::pair<int, std::string>(3, "3"), std::pair<int, std::string>(4, "4"),
      std::pair<int, std::string>(5, "5")};
  a_eth.clear();
  map_test_foo(a, a_eth);
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(map_clear, 4) {
  // Arrange
  simplestl::map<int, std::string> a{
      std::pair<int, std::string>(5, "5"), std::pair<int, std::string>(4, "4"),
      std::pair<int, std::string>(3, "3"), std::pair<int, std::string>(2, "2"),
      std::pair<int, std::string>(1, "1")};
  // Act
  a.clear();
  // Assert
  std::map<int, std::string> a_eth{
      std::pair<int, std::string>(5, "5"), std::pair<int, std::string>(4, "4"),
      std::pair<int, std::string>(3, "3"), std::pair<int, std::string>(2, "2"),
      std::pair<int, std::string>(1, "1")};
  a_eth.clear();
  map_test_foo(a, a_eth);
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(map_clear, 5) {
  // Arrange
  simplestl::map<float, double> a;
  // Act
  a.clear();
  // Assert
  std::map<float, double> a_eth;
  a_eth.clear();
  map_test_foo(a, a_eth);
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(map_insert_value_type, 1) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  auto pair = a.insert(std::pair<int, std::string>(1, "1"));
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  auto pair_eth = a_eth.insert(std::pair<int, std::string>(1, "1"));
  map_test_foo(a, a_eth);
  ASSERT_EQ(pair.first->first, pair_eth.first->first);
  ASSERT_EQ(pair.first->second, pair_eth.first->second);
  ASSERT_EQ(pair.second, pair_eth.second);
}

TEST(map_insert_value_type, 2) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  auto pair = a.insert(std::pair<int, std::string>(7, "1"));
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  auto pair_eth = a_eth.insert(std::pair<int, std::string>(7, "1"));
  map_test_foo(a, a_eth);
  ASSERT_EQ(pair.first->first, pair_eth.first->first);
  ASSERT_EQ(pair.first->second, pair_eth.first->second);
  ASSERT_EQ(pair.second, pair_eth.second);
}

TEST(map_insert_key_obj, 1) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  auto pair = a.insert(1, "1");
  // Assert
  ASSERT_EQ(pair.second, false);
  ASSERT_EQ(a[1], "1");
}

TEST(map_insert_key_obj, 2) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  auto pair = a.insert(7, "7");
  // Assert
  ASSERT_EQ(pair.second, true);
  ASSERT_EQ(pair.first->first, 7);
  ASSERT_EQ(pair.first->second, "7");
}

TEST(map_insert_or_assign, 1) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  auto pair = a.insert_or_assign(1, "7");
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  auto pair_eth = a_eth.insert_or_assign(1, "7");
  map_test_foo(a, a_eth);
  ASSERT_EQ(pair.first->first, pair_eth.first->first);
  ASSERT_EQ(pair.first->second, pair_eth.first->second);
  ASSERT_EQ(pair.second, pair_eth.second);
}

TEST(map_insert_or_assign, 2) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  auto pair = a.insert_or_assign(7, "7");
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  auto pair_eth = a_eth.insert_or_assign(7, "7");
  map_test_foo(a, a_eth);
  ASSERT_EQ(pair.first->first, pair_eth.first->first);
  ASSERT_EQ(pair.first->second, pair_eth.first->second);
  ASSERT_EQ(pair.second, pair_eth.second);
}

TEST(map_erase, 1) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  auto iter = a.begin();
  // Act
  a.erase(iter);
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  auto iter_eth = a_eth.begin();
  a_eth.erase(iter_eth);
  map_test_foo(a, a_eth);
}

TEST(map_erase, 2) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  auto iter = a.end();
  // Act
  --iter;
  a.erase(iter);
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  auto iter_eth = a_eth.end();
  --iter_eth;
  a_eth.erase(iter_eth);
  map_test_foo(a, a_eth);
}

TEST(map_erase, 3) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  auto iter = a.begin();
  ++iter;
  // Act
  a.erase(iter);
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  auto iter_eth = a_eth.begin();
  ++iter_eth;
  a_eth.erase(iter_eth);
  map_test_foo(a, a_eth);
}

TEST(map_erase, 4) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  auto iter = a.end();
  // Act
  --iter;
  a.erase(iter);
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  auto iter_eth = a_eth.end();
  --iter_eth;
  a_eth.erase(iter_eth);
  map_test_foo(a, a_eth);
}

TEST(map_erase, 5) {
  // Arrange
  simplestl::map<int, std::string> a{
      std::pair<int, std::string>(7, "1"), std::pair<int, std::string>(4, "1"),
      std::pair<int, std::string>(2, "1"), std::pair<int, std::string>(5, "1"),
      std::pair<int, std::string>(1, "1"), std::pair<int, std::string>(11, "1"),
      std::pair<int, std::string>(8, "1"), std::pair<int, std::string>(9, "1"),
      std::pair<int, std::string>(12, "1")};
  // Act
  // Assert
  std::map<int, std::string> a_eth{
      std::pair<int, std::string>(7, "1"), std::pair<int, std::string>(4, "1"),
      std::pair<int, std::string>(2, "1"), std::pair<int, std::string>(5, "1"),
      std::pair<int, std::string>(1, "1"), std::pair<int, std::string>(11, "1"),
      std::pair<int, std::string>(8, "1"), std::pair<int, std::string>(9, "1"),
      std::pair<int, std::string>(12, "1")};
  auto iter = a.begin();
  auto iter_eth = a_eth.begin();
  ++iter;
  ++iter;
  ++iter_eth;
  ++iter_eth;
  a.erase(iter);
  a_eth.erase(iter_eth);
  iter = a.begin();
  iter_eth = a_eth.begin();
  ++iter;
  ++iter_eth;
  a.erase(iter);
  a_eth.erase(iter_eth);
  iter = a.begin();
  iter_eth = a_eth.begin();
  ++iter;
  ++iter;
  ++iter_eth;
  ++iter_eth;
  a.erase(iter);
  a_eth.erase(iter_eth);
  map_test_foo(a, a_eth);
}

TEST(map_erase, 6) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(7, "1"),
                                     std::pair<int, std::string>(9, "2"),
                                     std::pair<int, std::string>(8, "3")};
  auto iter = a.end();
  // Act
  --iter;
  a.erase(iter);
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(7, "1"),
                                   std::pair<int, std::string>(9, "2"),
                                   std::pair<int, std::string>(8, "3")};
  auto iter_eth = a_eth.end();
  --iter_eth;
  a_eth.erase(iter_eth);
  map_test_foo(a, a_eth);
}

TEST(map_erase, 7) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(7, "1"),
                                     std::pair<int, std::string>(6, "2")};
  auto iter = a.begin();
  ++iter;
  // Act
  a.erase(iter);
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(7, "1"),
                                   std::pair<int, std::string>(6, "2")};
  auto iter_eth = a_eth.begin();
  ++iter_eth;
  a_eth.erase(iter_eth);
  map_test_foo(a, a_eth);
}

TEST(map_erase, 8) {
  // Arrange
  simplestl::map<int, std::string> a{
      std::pair<int, std::string>(2, "1"), std::pair<int, std::string>(4, "2"),
      std::pair<int, std::string>(3, "3"), std::pair<int, std::string>(5, "2"),
      std::pair<int, std::string>(6, "2")};
  auto iter = a.begin();
  ++iter;
  ++iter;
  // Act
  a.erase(iter);
  // Assert
  std::map<int, std::string> a_eth{
      std::pair<int, std::string>(2, "1"), std::pair<int, std::string>(4, "2"),
      std::pair<int, std::string>(3, "3"), std::pair<int, std::string>(5, "2"),
      std::pair<int, std::string>(6, "2")};
  auto iter_eth = a_eth.begin();
  ++iter_eth;
  ++iter_eth;
  a_eth.erase(iter_eth);
  map_test_foo(a, a_eth);
}

TEST(map_swap, 1) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  simplestl::map<int, std::string> b{std::pair<int, std::string>(4, "4"),
                                     std::pair<int, std::string>(5, "5")};
  // Act
  a.swap(b);
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  std::map<int, std::string> b_eth{std::pair<int, std::string>(4, "4"),
                                   std::pair<int, std::string>(5, "5")};
  a_eth.swap(b_eth);
  map_test_foo(a, a_eth);
  map_test_foo(b, b_eth);
}

TEST(map_swap, 2) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  simplestl::map<int, std::string> b;
  // Act
  a.swap(b);
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  std::map<int, std::string> b_eth;
  a_eth.swap(b_eth);
  map_test_foo(a, a_eth);
  map_test_foo(b, b_eth);
}

TEST(map_swap, 3) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  a.swap(a);
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  a_eth.swap(a_eth);
  map_test_foo(a, a_eth);
}

TEST(map_merge, 1) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  simplestl::map<int, std::string> b{std::pair<int, std::string>(4, "4"),
                                     std::pair<int, std::string>(5, "5")};
  // Act
  a.merge(b);
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  std::map<int, std::string> b_eth{std::pair<int, std::string>(4, "4"),
                                   std::pair<int, std::string>(5, "5")};
  a_eth.merge(b_eth);
  map_test_foo(a, a_eth);
  map_test_foo(b, b_eth);
}

TEST(map_merge, 2) {
  // Arrange
  simplestl::map<int, std::string> a;
  simplestl::map<int, std::string> b{std::pair<int, std::string>(4, "4"),
                                     std::pair<int, std::string>(5, "5")};
  // Act
  a.merge(b);
  // Assert
  std::map<int, std::string> a_eth;
  std::map<int, std::string> b_eth{std::pair<int, std::string>(4, "4"),
                                   std::pair<int, std::string>(5, "5")};
  a_eth.merge(b_eth);
  map_test_foo(a, a_eth);
  map_test_foo(b, b_eth);
}

TEST(map_merge, 3) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  simplestl::map<int, std::string> b;
  // Act
  a.merge(b);
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  std::map<int, std::string> b_eth;
  a_eth.merge(b_eth);
  map_test_foo(a, a_eth);
  map_test_foo(b, b_eth);
}

TEST(map_merge, 4) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  simplestl::map<int, std::string> b{std::pair<int, std::string>(8, "8"),
                                     std::pair<int, std::string>(5, "5"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(4, "4"),
                                     std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(3, "3"),
                                     std::pair<int, std::string>(7, "7"),
                                     std::pair<int, std::string>(6, "6"),
                                     std::pair<int, std::string>(11, "11"),
                                     std::pair<int, std::string>(9, "9"),
                                     std::pair<int, std::string>(12, "12"),
                                     std::pair<int, std::string>(10, "10")};
  // Act
  a.merge(b);
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  std::map<int, std::string> b_eth{std::pair<int, std::string>(8, "8"),
                                   std::pair<int, std::string>(5, "5"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(4, "4"),
                                   std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(3, "3"),
                                   std::pair<int, std::string>(7, "7"),
                                   std::pair<int, std::string>(6, "6"),
                                   std::pair<int, std::string>(11, "11"),
                                   std::pair<int, std::string>(9, "9"),
                                   std::pair<int, std::string>(12, "12"),
                                   std::pair<int, std::string>(10, "10")};
  a_eth.merge(b_eth);
  map_test_foo(a, a_eth);
  map_test_foo(b, b_eth);
}

TEST(map_merge, 5) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  simplestl::map<int, std::string> b{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  a.merge(b);
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  std::map<int, std::string> b_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  a_eth.merge(b_eth);
  map_test_foo(a, a_eth);
  map_test_foo(b, b_eth);
}

TEST(map_contains, 1) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  bool res = a.contains(2);
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  bool res_eth = a.contains(2);
  ASSERT_EQ(res, res_eth);
}

TEST(map_contains, 2) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  bool res = a.contains(7);
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  bool res_eth = a.contains(7);
  ASSERT_EQ(res, res_eth);
}

TEST(map_emplace, 1) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  auto res = a.emplace(std::pair<int, std::string>(4, "4"),
                       std::pair<int, std::string>(5, "5"),
                       std::pair<int, std::string>(6, "6"));
  // Assert
  std::map<int, std::string> a_eth{
      std::pair<int, std::string>(1, "1"), std::pair<int, std::string>(2, "2"),
      std::pair<int, std::string>(3, "3"), std::pair<int, std::string>(4, "4"),
      std::pair<int, std::string>(5, "5"), std::pair<int, std::string>(6, "6")};
  simplestl::vector<std::pair<std::string, bool>> res_eth{
      std::pair<std::string, bool>("4", true),
      std::pair<std::string, bool>("5", true),
      std::pair<std::string, bool>("6", true)};
  auto iter_eth = res_eth.begin();
  for (auto iter : res) {
    ASSERT_EQ((*(iter.first)).second, (*iter_eth).first);
    ASSERT_EQ(iter.second, (*iter_eth).second);
    ++iter_eth;
  }
  map_test_foo(a, a_eth);
}

TEST(map_emplace, 2) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  auto res = a.emplace(std::pair<int, std::string>(1, "4"),
                       std::pair<int, std::string>(2, "5"),
                       std::pair<int, std::string>(3, "6"));
  // Assert
  std::map<int, std::string> a_eth{std::pair<int, std::string>(1, "1"),
                                   std::pair<int, std::string>(2, "2"),
                                   std::pair<int, std::string>(3, "3")};
  simplestl::vector<std::pair<std::string, bool>> res_eth{
      std::pair<std::string, bool>("4", false),
      std::pair<std::string, bool>("5", false),
      std::pair<std::string, bool>("6", false)};
  auto iter_eth = res_eth.begin();
  for (auto iter : res) {
    // ASSERT_EQ((*(iter.first)).second, (*iter_eth).first);
    ASSERT_EQ(iter.second, (*iter_eth).second);
    ++iter_eth;
  }
  map_test_foo(a, a_eth);
}

TEST(map_emplace, 3) {
  // Arrange
  simplestl::map<int, std::string> a{std::pair<int, std::string>(1, "1"),
                                     std::pair<int, std::string>(2, "2"),
                                     std::pair<int, std::string>(3, "3")};
  // Act
  auto res = a.emplace(std::pair<int, std::string>(4, "4"),
                       std::pair<int, std::string>(3, "5"),
                       std::pair<int, std::string>(6, "6"));
  // Assert
  std::map<int, std::string> a_eth{
      std::pair<int, std::string>(1, "1"), std::pair<int, std::string>(2, "2"),
      std::pair<int, std::string>(3, "3"), std::pair<int, std::string>(4, "4"),
      std::pair<int, std::string>(6, "6")};
  simplestl::vector<std::pair<std::string, bool>> res_eth{
      std::pair<std::string, bool>("4", true),
      std::pair<std::string, bool>("5", false),
      std::pair<std::string, bool>("6", true)};
  auto iter_eth = res_eth.begin();
  for (auto iter : res) {
    // ASSERT_EQ((*(iter.first)).second, (*iter_eth).first);
    ASSERT_EQ(iter.second, (*iter_eth).second);
    ++iter_eth;
  }
  map_test_foo(a, a_eth);
}

TEST(multiset_default_constructor, 1) {
  // Arrange
  // Act
  simplestl::multiset<int> a;
  // Assert
  std::multiset<int> a_eth;
  multiset_test_foo(a, a_eth);
}

TEST(multiset_parameterized_constructor, 1) {
  // Arrange
  // Act
  simplestl::multiset<int> a{1, 2, 3};
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  multiset_test_foo(a, a_eth);
}

TEST(multiset_parameterized_constructor, 2) {
  // Arrange
  // Act
  simplestl::multiset<int> a{1, 2, 3, 2, 1};
  // Assert
  std::multiset<int> a_eth{1, 2, 3, 2, 1};
  multiset_test_foo(a, a_eth);
}

TEST(multiset_copy_constructor, 1) {
  // Arrange
  simplestl::multiset<int> b{1, 2, 3};
  // Act
  simplestl::multiset<int> a(b);
  // Assert
  std::multiset<int> b_eth{1, 2, 3};
  std::multiset<int> a_eth(b_eth);
  multiset_test_foo(a, a_eth);
}

TEST(multiset_move_constructor, 1) {
  // Arrange
  simplestl::multiset<int> b{1, 2, 3, 3};
  // Act
  simplestl::multiset<int> a(std::move(b));
  // Assert
  std::multiset<int> b_eth{1, 2, 3, 3};
  std::multiset<int> a_eth(std::move(b_eth));
  multiset_test_foo(a, a_eth);
  multiset_test_foo(b, b_eth);
}

TEST(multiset_eq_overriten_operator_r_value, 1) {
  // Arrange
  simplestl::multiset<int> a;
  simplestl::multiset<int> b{1, 2, 3};
  // Act
  a = std::move(b);
  // Assert
  std::multiset<int> b_eth{1, 2, 3};
  std::multiset<int> a_eth;
  a_eth = std::move(b_eth);
  multiset_test_foo(a, a_eth);
  multiset_test_foo(b, b_eth);
}

TEST(multiset_eq_overriten_operator_r_value, 2) {
  // Arrange
  simplestl::multiset<int> a{3, 2, 1};
  simplestl::multiset<int> b{1, 2, 3};
  // Act
  a = std::move(b);
  // Assert
  std::multiset<int> a_eth{3, 2, 1};
  std::multiset<int> b_eth{1, 2, 3};
  a_eth = std::move(b_eth);
  multiset_test_foo(a, a_eth);
  multiset_test_foo(b, b_eth);
}

TEST(multiset_begin_iter, 1) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  // Act
  simplestl::multiset<int>::iterator iter = a.begin();
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  std::multiset<int>::iterator iter_eth = a_eth.begin();
  ASSERT_EQ(*iter, *iter_eth);
}

TEST(multiset_end_iter, 1) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3, 2};
  // Act
  simplestl::multiset<int>::iterator iter = a.end();
  // Assert
  std::multiset<int> a_eth{1, 2, 3, 2};
  std::multiset<int>::iterator iter_eth = a_eth.end();
  ASSERT_EQ(*--iter, *--iter_eth);
}

TEST(multiset_iterator_methods, 1) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  // Act
  auto iter = a.begin();
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.begin();
  for (; iter != a.end(); ++iter, ++iter_eth) {
    ASSERT_EQ(*iter, *iter_eth);
  }
}

TEST(multiset_iterator_methods, 2) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  // Act
  auto iter = a.end();
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.end();
  for (; iter != a.begin();) {
    --iter;
    --iter_eth;
    ASSERT_EQ(*iter, *iter_eth);
  }
}

TEST(multiset_empty, 1) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3, 3};
  // Act
  // Assert
  std::multiset<int> a_eth{1, 2, 3, 3};
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(multiset_empty, 2) {
  // Arrange
  simplestl::multiset<int> a;
  // Act
  // Assert
  std::multiset<int> a_eth;
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(multiset_empty, 3) {
  // Arrange
  simplestl::multiset<std::string> a{"1", "2", "3", "4"};
  // Act
  // Assert
  std::multiset<std::string> a_eth{"1", "2", "3", "4"};
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(multiset_size, 1) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  // Act
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  ASSERT_EQ(a.size(), a_eth.size());
}

TEST(multiset_max_size, 1) {
  // Arrange
  simplestl::multiset<int> a;
  // Act
  // Assert
  std::multiset<int> a_eth;
  ASSERT_EQ(a.max_size(), a_eth.max_size());
}

TEST(multiset_max_size, 2) {
  // Arrange
  simplestl::multiset<std::string> a;
  // Act
  // Assert
  std::multiset<std::string> a_eth;
  ASSERT_EQ(a.max_size(), a_eth.max_size());
}

TEST(multiset_clear, 1) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  // Act
  a.clear();
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  a_eth.clear();
  multiset_test_foo(a, a_eth);
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(multiset_clear, 2) {
  // Arrange
  simplestl::multiset<int> a{7, 5, 4, 6, 9, 8, 10, 11, -5};
  // Act
  a.clear();
  // Assert
  std::multiset<int> a_eth{7, 5, 4, 6, 9, 8, 10, 11, -5};
  a_eth.clear();
  multiset_test_foo(a, a_eth);
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(multiset_clear, 3) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3, 4, 5};
  // Act
  a.clear();
  // Assert
  std::multiset<int> a_eth{1, 2, 3, 4, 5};
  a_eth.clear();
  multiset_test_foo(a, a_eth);
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(multiset_clear, 4) {
  // Arrange
  simplestl::multiset<int> a{5, 4, 3, 2, 1, 1};
  // Act
  a.clear();
  // Assert
  std::multiset<int> a_eth{5, 4, 3, 2, 1, 1};
  a_eth.clear();
  multiset_test_foo(a, a_eth);
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(multiset_clear, 5) {
  // Arrange
  simplestl::multiset<int> a;
  // Act
  a.clear();
  // Assert
  std::multiset<int> a_eth;
  a_eth.clear();
  multiset_test_foo(a, a_eth);
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(multiset_insert, 1) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  // Act
  auto iter = a.insert(7);
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.insert(7);
  multiset_test_foo(a, a_eth);
  ASSERT_EQ(*iter, *iter_eth);
}

TEST(multiset_insert, 2) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  // Act
  auto iter = a.insert(3);
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.insert(3);
  multiset_test_foo(a, a_eth);
  ASSERT_EQ(*iter, *iter_eth);
}

TEST(multiset_insert, 3) {
  // Arrange
  simplestl::multiset<int> a;
  // Act
  auto iter = a.insert(7);
  // Assert
  std::multiset<int> a_eth;
  auto iter_eth = a_eth.insert(7);
  multiset_test_foo(a, a_eth);
  ASSERT_EQ(*iter, *iter_eth);
}

TEST(multiset_insert, 4) {
  // Arrange
  simplestl::multiset<std::string> a{"1", "2", "3"};
  // Act
  auto iter = a.insert("7");
  // Assert
  std::multiset<std::string> a_eth{"1", "2", "3"};
  auto iter_eth = a_eth.insert("7");
  multiset_test_foo(a, a_eth);
  ASSERT_EQ(*iter, *iter_eth);
}

TEST(multiset_insert, 5) {
  // Arrange
  simplestl::multiset<std::string> a{"1", "2", "3"};
  // Act
  auto iter = a.insert("2");
  // Assert
  std::multiset<std::string> a_eth{"1", "2", "3"};
  auto iter_eth = a_eth.insert("2");
  multiset_test_foo(a, a_eth);
  ASSERT_EQ(*iter, *iter_eth);
}

TEST(multiset_insert, 6) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  // Act
  auto iter = a.insert(-1);
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.insert(-1);
  multiset_test_foo(a, a_eth);
  ASSERT_EQ(*iter, *iter_eth);
}

TEST(multiset_erase, 1) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  auto iter = a.begin();
  // Act
  a.erase(iter);
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.begin();
  a_eth.erase(iter_eth);
  multiset_test_foo(a, a_eth);
}

TEST(multiset_erase, 2) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  auto iter = a.end();
  // Act
  --iter;
  a.erase(iter);
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.end();
  --iter_eth;
  a_eth.erase(iter_eth);
  multiset_test_foo(a, a_eth);
}

TEST(multiset_erase, 3) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  auto iter = a.begin();
  ++iter;
  // Act
  a.erase(iter);
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.begin();
  ++iter_eth;
  a_eth.erase(iter_eth);
  multiset_test_foo(a, a_eth);
}

TEST(multiset_erase, 4) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3, 3};
  auto iter = a.end();
  // Act
  --iter;
  a.erase(iter);
  // Assert
  std::multiset<int> a_eth{1, 2, 3, 3};
  auto iter_eth = a_eth.end();
  --iter_eth;
  a_eth.erase(iter_eth);
  multiset_test_foo(a, a_eth);
}

TEST(multiset_erase, 5) {
  // Arrange
  simplestl::multiset<int> a{7, 4, 2, 5, 1, 11, 8, 9, 12};
  // Act
  // Assert
  std::multiset<int> a_eth{7, 4, 2, 5, 1, 11, 8, 9, 12};
  auto iter = a.begin();
  auto iter_eth = a_eth.begin();
  ++iter;
  ++iter;
  ++iter_eth;
  ++iter_eth;
  a.erase(iter);
  a_eth.erase(iter_eth);
  iter = a.begin();
  iter_eth = a_eth.begin();
  ++iter;
  ++iter_eth;
  a.erase(iter);
  a_eth.erase(iter_eth);
  iter = a.begin();
  iter_eth = a_eth.begin();
  ++iter;
  ++iter;
  ++iter_eth;
  ++iter_eth;
  a.erase(iter);
  a_eth.erase(iter_eth);
  multiset_test_foo(a, a_eth);
}

TEST(multiset_erase, 6) {
  // Arrange
  simplestl::multiset<int> a{7, 9, 8};
  auto iter = a.end();
  // Act
  --iter;
  a.erase(iter);
  // Assert
  std::multiset<int> a_eth{7, 9, 8};
  auto iter_eth = a_eth.end();
  --iter_eth;
  a_eth.erase(iter_eth);
  multiset_test_foo(a, a_eth);
}

TEST(multiset_erase, 7) {
  // Arrange
  simplestl::multiset<int> a{7, 6};
  auto iter = a.begin();
  ++iter;
  // Act
  a.erase(iter);
  // Assert
  std::multiset<int> a_eth{7, 6};
  auto iter_eth = a_eth.begin();
  ++iter_eth;
  a_eth.erase(iter_eth);
  multiset_test_foo(a, a_eth);
}

TEST(multiset_erase, 8) {
  // Arrange
  simplestl::multiset<int> a{2, 4, 3, 5, 6};
  auto iter = a.begin();
  ++iter;
  ++iter;
  // Act
  a.erase(iter);
  // Assert
  std::multiset<int> a_eth{2, 4, 3, 5, 6};
  auto iter_eth = a_eth.begin();
  ++iter_eth;
  ++iter_eth;
  a_eth.erase(iter_eth);
  multiset_test_foo(a, a_eth);
}

TEST(multiset_swap, 1) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  simplestl::multiset<int> b{4, 5};
  // Act
  a.swap(b);
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  std::multiset<int> b_eth{4, 5};
  a_eth.swap(b_eth);
  multiset_test_foo(a, a_eth);
  multiset_test_foo(b, b_eth);
}

TEST(multiset_swap, 2) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  simplestl::multiset<int> b;
  // Act
  a.swap(b);
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  std::multiset<int> b_eth;
  a_eth.swap(b_eth);
  multiset_test_foo(a, a_eth);
  multiset_test_foo(b, b_eth);
}

TEST(multiset_swap, 3) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  // Act
  a.swap(a);
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  a_eth.swap(a_eth);
  multiset_test_foo(a, a_eth);
}

TEST(multiset_merge, 1) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  simplestl::multiset<int> b{4, 5};
  // Act
  a.merge(b);
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  std::multiset<int> b_eth{4, 5};
  a_eth.merge(b_eth);
  multiset_test_foo(a, a_eth);
  multiset_test_foo(b, b_eth);
}

TEST(multiset_merge, 2) {
  // Arrange
  simplestl::multiset<int> a;
  simplestl::multiset<int> b{4, 5};
  // Act
  a.merge(b);
  // Assert
  std::multiset<int> a_eth;
  std::multiset<int> b_eth{4, 5};
  a_eth.merge(b_eth);
  multiset_test_foo(a, a_eth);
  multiset_test_foo(b, b_eth);
}

TEST(multiset_merge, 3) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  simplestl::multiset<int> b;
  // Act
  a.merge(b);
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  std::multiset<int> b_eth;
  a_eth.merge(b_eth);
  multiset_test_foo(a, a_eth);
  multiset_test_foo(b, b_eth);
}

TEST(multiset_merge, 4) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  simplestl::multiset<int> b{8, 5, 2, 4, 1, 3, 7, 6, 11, 9, 12, 10};
  // Act
  a.merge(b);
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  std::multiset<int> b_eth{8, 5, 2, 4, 1, 3, 7, 6, 11, 9, 12, 10};
  a_eth.merge(b_eth);
  multiset_test_foo(a, a_eth);
  multiset_test_foo(b, b_eth);
}

TEST(multiset_merge, 5) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  simplestl::multiset<int> b{1, 2, 3};
  // Act
  a.merge(b);
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  std::multiset<int> b_eth{1, 2, 3};
  a_eth.merge(b_eth);
  multiset_test_foo(a, a_eth);
  multiset_test_foo(b, b_eth);
}

TEST(multiset_count, 1) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  // Act
  auto count = a.count(2);
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  auto count_eth = a_eth.count(2);
  multiset_test_foo(a, a_eth);
  ASSERT_EQ(count, count_eth);
}

TEST(multiset_count, 2) {
  // Arrange
  simplestl::multiset<int> a;
  // Act
  auto count = a.count(2);
  // Assert
  std::multiset<int> a_eth;
  auto count_eth = a_eth.count(2);
  multiset_test_foo(a, a_eth);
  ASSERT_EQ(count, count_eth);
}

TEST(multiset_count, 3) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3, 2, 2};
  // Act
  auto count = a.count(2);
  // Assert
  std::multiset<int> a_eth{1, 2, 3, 2, 2};
  auto count_eth = a_eth.count(2);
  multiset_test_foo(a, a_eth);
  ASSERT_EQ(count, count_eth);
}

TEST(multiset_count, 4) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3, 2, 2};
  // Act
  auto count = a.count(7);
  // Assert
  std::multiset<int> a_eth{1, 2, 3, 2, 2};
  auto count_eth = a_eth.count(7);
  multiset_test_foo(a, a_eth);
  ASSERT_EQ(count, count_eth);
}

TEST(multiset_find, 1) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  // Act
  auto iter = a.find(1);
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.find(1);
  ASSERT_EQ(*iter, *iter_eth);
}

TEST(multiset_find, 2) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  // Act
  auto iter = a.find(3);
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.find(3);
  ASSERT_EQ(*iter, *iter_eth);
}

TEST(multiset_find, 3) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  // Act
  auto iter = a.find(7);
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.find(7);
  ASSERT_EQ(iter == a.end(), iter_eth == a_eth.end());
}

TEST(multiset_contains, 1) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  // Act
  bool res = a.contains(2);
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  bool res_eth = a.contains(2);
  ASSERT_EQ(res, res_eth);
}

TEST(multiset_contains, 2) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  // Act
  bool res = a.contains(7);
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  bool res_eth = a.contains(7);
  ASSERT_EQ(res, res_eth);
}

TEST(multiset_lower_bound, 1) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  // Act
  auto iter = a.lower_bound(1);
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.lower_bound(1);
  ASSERT_EQ(*iter, *iter_eth);
  for (; *iter != *(--a.end()) && *iter_eth != *(--a_eth.end());) {
    ++iter;
    ++iter_eth;
    ASSERT_EQ(*iter, *iter_eth);
  }
  iter = a.end();
  iter_eth = a_eth.end();
  --iter;
  --iter_eth;
  for (; *iter != *a.begin() && *iter_eth != *a_eth.begin();) {
    ASSERT_EQ(*iter, *iter_eth);
    --iter;
    --iter_eth;
  }
}

TEST(multiset_lower_bound, 2) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 2, 3, 4, 2};
  // Act
  auto iter = a.lower_bound(2);
  // Assert
  std::multiset<int> a_eth{1, 2, 2, 3, 4, 2};
  auto iter_eth = a_eth.lower_bound(2);
  ASSERT_EQ(*iter, *iter_eth);
  for (; *iter != *(--a.end()) && *iter_eth != *(--a_eth.end());) {
    ++iter;
    ++iter_eth;
    ASSERT_EQ(*iter, *iter_eth);
  }
  iter = a.end();
  iter_eth = a_eth.end();
  --iter;
  --iter_eth;
  for (; *iter != *a.begin() && *iter_eth != *a_eth.begin();) {
    ASSERT_EQ(*iter, *iter_eth);
    --iter;
    --iter_eth;
  }
}

TEST(multiset_lower_bound, 3) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 2, 3, 4, 2};
  // Act
  auto iter = a.lower_bound(7);
  // Assert
  std::multiset<int> a_eth{1, 2, 2, 3, 4, 2};
  auto iter_eth = a_eth.lower_bound(7);
  ASSERT_EQ(iter == a.end(), iter_eth == a_eth.end());
}

TEST(multiset_upper_bound, 1) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  // Act
  auto iter = a.upper_bound(1);
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.upper_bound(1);
  ASSERT_EQ(*iter, *iter_eth);
  for (; *iter != *(--a.end()) && *iter_eth != *(--a_eth.end());) {
    ++iter;
    ++iter_eth;
    ASSERT_EQ(*iter, *iter_eth);
  }
  iter = a.end();
  iter_eth = a_eth.end();
  --iter;
  --iter_eth;
  for (; *iter != *a.begin() && *iter_eth != *a_eth.begin();) {
    ASSERT_EQ(*iter, *iter_eth);
    --iter;
    --iter_eth;
  }
}

TEST(multiset_upper_bound, 2) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 2, 3, 4, 2};
  // Act
  auto iter = a.upper_bound(2);
  // Assert
  std::multiset<int> a_eth{1, 2, 2, 3, 4, 2};
  auto iter_eth = a_eth.upper_bound(2);
  ASSERT_EQ(*iter, *iter_eth);
  for (; *iter != *(--a.end()) && *iter_eth != *(--a_eth.end());) {
    ++iter;
    ++iter_eth;
    ASSERT_EQ(*iter, *iter_eth);
  }
  iter = a.end();
  iter_eth = a_eth.end();
  --iter;
  --iter_eth;
  for (; *iter != *a.begin() && *iter_eth != *a_eth.begin();) {
    ASSERT_EQ(*iter, *iter_eth);
    --iter;
    --iter_eth;
  }
}

TEST(multiset_upper_bound, 3) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 2, 3, 4, 2};
  // Act
  auto iter = a.upper_bound(7);
  // Assert
  std::multiset<int> a_eth{1, 2, 2, 3, 4, 2};
  auto iter_eth = a_eth.upper_bound(7);
  ASSERT_EQ(iter == a.end(), iter_eth == a_eth.end());
}

TEST(multiset_equal_range, 1) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  // Act
  auto pair = a.equal_range(1);
  // Assert
  std::multiset<int> a_eth{1, 2, 3};
  auto pair_eth = a_eth.equal_range(1);
  ASSERT_EQ(*pair.first, *pair_eth.first);
  ASSERT_EQ(*pair.second, *pair_eth.second);
}

TEST(multiset_equal_range, 2) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 2, 3, 4, 2};
  // Act
  auto pair = a.equal_range(2);
  // Assert
  std::multiset<int> a_eth{1, 2, 2, 3, 4, 2};
  auto pair_eth = a_eth.equal_range(2);
  ASSERT_EQ(*pair.first, *pair_eth.first);
  ASSERT_EQ(*pair.second, *pair_eth.second);
}

TEST(multiset_equal_range, 3) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 2, 3, 4, 2};
  // Act
  auto pair = a.equal_range(7);
  // Assert
  std::multiset<int> a_eth{1, 2, 2, 3, 4, 2};
  auto pair_eth = a_eth.equal_range(7);
  ASSERT_EQ(pair.first == a.end(), pair_eth.first == a_eth.end());
  ASSERT_EQ(pair.second == a.end(), pair_eth.second == a_eth.end());
}

TEST(multiset_emplace, 1) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  // Act
  auto res = a.emplace(4, 5, 6);
  // Assert
  std::multiset<int> a_eth{1, 2, 3, 4, 5, 6};
  simplestl::vector<std::pair<int, bool>> res_eth{
      std::pair<int, bool>(4, true), std::pair<int, bool>(5, true),
      std::pair<int, bool>(6, true)};
  auto iter_eth = res_eth.begin();
  for (auto iter : res) {
    ASSERT_EQ(*(iter.first), (*iter_eth).first);
    ASSERT_EQ(iter.second, (*iter_eth).second);
    ++iter_eth;
  }
  multiset_test_foo(a, a_eth);
}

TEST(multiset_emplace, 2) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  // Act
  auto res = a.emplace(1, 2, 3);
  // Assert
  std::multiset<int> a_eth{1, 2, 3, 1, 2, 3};
  simplestl::vector<std::pair<int, bool>> res_eth{
      std::pair<int, bool>(1, true), std::pair<int, bool>(2, true),
      std::pair<int, bool>(3, true)};
  auto iter_eth = res_eth.begin();
  for (auto iter : res) {
    ASSERT_EQ(*(iter.first), (*iter_eth).first);
    ASSERT_EQ(iter.second, (*iter_eth).second);
    ++iter_eth;
  }
  multiset_test_foo(a, a_eth);
}

TEST(multiset_emplace, 3) {
  // Arrange
  simplestl::multiset<int> a{1, 2, 3};
  // Act
  auto res = a.emplace(4, 3, 6);
  // Assert
  std::multiset<int> a_eth{1, 2, 3, 3, 4, 6};
  simplestl::vector<std::pair<int, bool>> res_eth{
      std::pair<int, bool>(4, true), std::pair<int, bool>(3, true),
      std::pair<int, bool>(6, true)};
  auto iter_eth = res_eth.begin();
  for (auto iter : res) {
    ASSERT_EQ(*(iter.first), (*iter_eth).first);
    ASSERT_EQ(iter.second, (*iter_eth).second);
    ++iter_eth;
  }
  multiset_test_foo(a, a_eth);
}

TEST(queue_default_constructor, 1) {
  // Arrange
  // Act
  simplestl::queue<int> a;
  // Assert
  std::queue<int> a_eth;
  ASSERT_EQ(a.size(), a_eth.size());
}

TEST(queue_parameterized_constructor, 1) {
  // Arrange
  // Act
  simplestl::queue<int> a{1, 2, 3};
  // Assert
  std::queue<int> a_eth;
  a_eth.push(1);
  a_eth.push(2);
  a_eth.push(3);
  ASSERT_EQ(a.size(), a_eth.size());
  while (a.size() != 0) {
    ASSERT_EQ(a.front(), a_eth.front());
    a.pop();
    a_eth.pop();
  }
}

TEST(queue_copy_constructor, 1) {
  // Arrange
  simplestl::queue<int> b;
  b.push(1);
  b.push(2);
  b.push(3);
  // Act
  simplestl::queue<int> a(b);
  // Assert
  std::queue<int> b_eth;
  b_eth.push(1);
  b_eth.push(2);
  b_eth.push(3);
  std::queue<int> a_eth(b_eth);
  ASSERT_EQ(a.size(), a_eth.size());
  while (a.size() != 0) {
    ASSERT_EQ(a.front(), a_eth.front());
    a.pop();
    a_eth.pop();
  }
}

TEST(queue_move_constructor, 1) {
  // Arrange
  simplestl::queue<int> b;
  b.push(1);
  b.push(2);
  b.push(3);
  // Act
  simplestl::queue<int> a(std::move(b));
  // Assert
  std::queue<int> b_eth;
  b_eth.push(1);
  b_eth.push(2);
  b_eth.push(3);
  std::queue<int> a_eth(std::move(b_eth));
  ASSERT_EQ(a.size(), a_eth.size());
  while (a.size() != 0) {
    ASSERT_EQ(a.front(), a_eth.front());
    a.pop();
    a_eth.pop();
  }
}

TEST(queue_eq_overriten_operator_r_value, 1) {
  // Arrange
  simplestl::queue<int> a;
  simplestl::queue<int> b;
  b.push(1);
  b.push(2);
  b.push(3);
  // Act
  a = std::move(b);
  // Assert
  std::queue<int> b_eth;
  b_eth.push(1);
  b_eth.push(2);
  b_eth.push(3);
  std::queue<int> a_eth;
  a_eth = std::move(b_eth);
  ASSERT_EQ(a.size(), a_eth.size());
  while (a.size() != 0) {
    ASSERT_EQ(a.front(), a_eth.front());
    a.pop();
    a_eth.pop();
  }
}

TEST(queue_eq_overriten_operator_r_value, 2) {
  // Arrange
  simplestl::queue<int> a;
  a.push(1);
  a.push(2);
  a.push(3);
  simplestl::queue<int> b;
  b.push(1);
  b.push(2);
  b.push(3);
  // Act
  a = std::move(b);
  // Assert
  std::queue<int> b_eth;
  b_eth.push(1);
  b_eth.push(2);
  b_eth.push(3);
  std::queue<int> a_eth;
  a_eth.push(1);
  a_eth.push(2);
  a_eth.push(3);
  a_eth = std::move(b_eth);
  ASSERT_EQ(a.size(), a_eth.size());
  while (a.size() != 0) {
    ASSERT_EQ(a.front(), a_eth.front());
    a.pop();
    a_eth.pop();
  }
}

TEST(queue_front, 1) {
  // Arrange
  simplestl::queue<int> a;
  a.push(1);
  a.push(2);
  a.push(3);
  // Act
  // Assert
  std::queue<int> a_eth;
  a_eth.push(1);
  a_eth.push(2);
  a_eth.push(3);
  ASSERT_EQ(a.front(), a_eth.front());
}

TEST(queue_back, 1) {
  // Arrange
  simplestl::queue<int> a;
  a.push(1);
  a.push(2);
  a.push(3);
  // Act
  // Assert
  std::queue<int> a_eth;
  a_eth.push(1);
  a_eth.push(2);
  a_eth.push(3);
  ASSERT_EQ(a.back(), a_eth.back());
}

TEST(queue_empty, 1) {
  // Arrange
  simplestl::queue<int> a;
  a.push(1);
  a.push(2);
  a.push(3);
  // Act
  // Assert
  std::queue<int> a_eth;
  a_eth.push(1);
  a_eth.push(2);
  a_eth.push(3);
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(queue_empty, 2) {
  // Arrange
  simplestl::queue<int> a;
  // Act
  // Assert
  std::queue<int> a_eth;
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(queue_size, 1) {
  // Arrange
  simplestl::queue<int> a;
  a.push(1);
  a.push(2);
  a.push(3);
  // Act
  // Assert
  std::queue<int> a_eth;
  a_eth.push(1);
  a_eth.push(2);
  a_eth.push(3);
  ASSERT_EQ(a.size(), a_eth.size());
}

TEST(queue_size, 2) {
  // Arrange
  simplestl::queue<int> a;
  // Act
  // Assert
  std::queue<int> a_eth;
  ASSERT_EQ(a.size(), a_eth.size());
}

TEST(queue_push, 1) {
  // Arrange
  simplestl::queue<int> a;
  // Act
  a.push(7);
  // Assert
  std::queue<int> a_eth;
  a_eth.push(7);
  ASSERT_EQ(a.front(), a_eth.front());
  ASSERT_EQ(a.back(), a_eth.back());
  ASSERT_EQ(a.size(), a_eth.size());
}

TEST(queue_push, 2) {
  // Arrange
  simplestl::queue<int> a;
  // Act
  a.push(1);
  a.push(2);
  a.push(3);
  // Assert
  std::queue<int> a_eth;
  a_eth.push(1);
  a_eth.push(2);
  a_eth.push(3);
  ASSERT_EQ(a.size(), a_eth.size());
  while (a.size() != 0) {
    ASSERT_EQ(a.back(), a_eth.back());
    ASSERT_EQ(a.front(), a_eth.front());
    a.pop();
    a_eth.pop();
  }
}

TEST(queue_pop, 1) {
  // Arrange
  simplestl::queue<int> a;
  // Act
  a.pop();
  // Assert
  std::queue<int> a_eth;
  a_eth.pop();
  ASSERT_EQ(a.size(), a_eth.size());
}

TEST(queue_pop, 2) {
  // Arrange
  simplestl::queue<int> a;
  // Act
  a.push(1);
  a.push(2);
  a.push(3);
  // Assert
  std::queue<int> a_eth;
  a_eth.push(1);
  a_eth.push(2);
  a_eth.push(3);
  while (a.size() != 0) {
    a.pop();
    a_eth.pop();
    ASSERT_EQ(a.size(), a_eth.size());
  }
}

TEST(queue_swap, 1) {
  // Arrange
  simplestl::queue<int> a;
  simplestl::queue<int> b;
  b.push(1);
  b.push(2);
  b.push(3);
  // Act
  a.swap(b);
  // Assert
  std::queue<int> a_eth;
  std::queue<int> b_eth;
  b_eth.push(1);
  b_eth.push(2);
  b_eth.push(3);
  a_eth.swap(b_eth);
  ASSERT_EQ(a.size(), a_eth.size());
  while (a.size() != 0) {
    ASSERT_EQ(a.front(), a_eth.front());
    ASSERT_EQ(a.back(), a_eth.back());
    a.pop();
    a_eth.pop();
  }
  ASSERT_EQ(b.size(), b_eth.size());
}

TEST(queue_swap, 2) {
  // Arrange
  simplestl::queue<int> a;
  a.push(4);
  a.push(5);
  simplestl::queue<int> b;
  b.push(1);
  b.push(2);
  b.push(3);
  // Act
  a.swap(b);
  // Assert
  std::queue<int> a_eth;
  a_eth.push(4);
  a_eth.push(5);
  std::queue<int> b_eth;
  b_eth.push(1);
  b_eth.push(2);
  b_eth.push(3);
  a_eth.swap(b_eth);
  ASSERT_EQ(a.size(), a_eth.size());
  while (a.size() != 0) {
    ASSERT_EQ(a.front(), a_eth.front());
    ASSERT_EQ(a.back(), a_eth.back());
    a.pop();
    a_eth.pop();
  }
  ASSERT_EQ(b.size(), b_eth.size());
  while (b.size() != 0) {
    ASSERT_EQ(b.front(), b_eth.front());
    ASSERT_EQ(b.back(), b_eth.back());
    b.pop();
    b_eth.pop();
  }
}

TEST(queue_emplace_back, 1) {
  // Arrange
  simplestl::queue<int> a{1, 2, 3};
  // Act
  a.emplace_back(4, 5, 6);
  // Assert
  std::queue<int> a_eth;
  a_eth.push(1);
  a_eth.push(2);
  a_eth.push(3);
  a_eth.push(4);
  a_eth.push(5);
  a_eth.push(6);
  ASSERT_EQ(a.size(), a_eth.size());
  while (a.size() != 0) {
    ASSERT_EQ(a.front(), a_eth.front());
    a.pop();
    a_eth.pop();
  }
}

TEST(set_default_constructor, 1) {
  // Arrange
  // Act
  simplestl::set<int> a;
  // Assert
  std::set<int> a_eth;
  set_test_foo(a, a_eth);
}

TEST(set_parameterized_constructor, 1) {
  // Arrange
  // Act
  simplestl::set<int> a{1, 2, 3};
  // Assert
  std::set<int> a_eth{1, 2, 3};
  set_test_foo(a, a_eth);
}

TEST(set_copy_constructor, 1) {
  // Arrange
  simplestl::set<int> b{1, 2, 3};
  // Act
  simplestl::set<int> a(b);
  // Assert
  std::set<int> b_eth{1, 2, 3};
  std::set<int> a_eth(b_eth);
  set_test_foo(a, a_eth);
}

TEST(set_move_constructor, 1) {
  // Arrange
  simplestl::set<int> b{1, 2, 3};
  // Act
  simplestl::set<int> a(std::move(b));
  // Assert
  std::set<int> b_eth{1, 2, 3};
  std::set<int> a_eth(std::move(b_eth));
  set_test_foo(a, a_eth);
  set_test_foo(b, b_eth);
}

TEST(set_eq_overriten_operator_r_value, 1) {
  // Arrange
  simplestl::set<int> a;
  simplestl::set<int> b{1, 2, 3};
  // Act
  a = std::move(b);
  // Assert
  std::set<int> b_eth{1, 2, 3};
  std::set<int> a_eth;
  a_eth = std::move(b_eth);
  set_test_foo(a, a_eth);
  set_test_foo(b, b_eth);
}

TEST(set_eq_overriten_operator_r_value, 2) {
  // Arrange
  simplestl::set<int> a{3, 2, 1};
  simplestl::set<int> b{1, 2, 3};
  // Act
  a = std::move(b);
  // Assert
  std::set<int> a_eth{3, 2, 1};
  std::set<int> b_eth{1, 2, 3};
  a_eth = std::move(b_eth);
  set_test_foo(a, a_eth);
  set_test_foo(b, b_eth);
}

TEST(set_begin_iter, 1) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  // Act
  simplestl::set<int>::iterator iter = a.begin();
  // Assert
  std::set<int> a_eth{1, 2, 3};
  std::set<int>::iterator iter_eth = a_eth.begin();
  ASSERT_EQ(*iter, *iter_eth);
}

TEST(set_end_iter, 1) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  // Act
  simplestl::set<int>::iterator iter = a.end();
  // Assert
  std::set<int> a_eth{1, 2, 3};
  std::set<int>::iterator iter_eth = a_eth.end();
  ASSERT_EQ(*--iter, *--iter_eth);
}

TEST(set_iterator_methods, 1) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  // Act
  auto iter = a.begin();
  // Assert
  std::set<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.begin();
  for (; iter != a.end(); ++iter, ++iter_eth) {
    ASSERT_EQ(*iter, *iter_eth);
  }
}

TEST(set_iterator_methods, 2) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  // Act
  auto iter = a.end();
  // Assert
  std::set<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.end();
  for (; iter != a.begin();) {
    --iter;
    --iter_eth;
    ASSERT_EQ(*iter, *iter_eth);
  }
}

TEST(set_empty, 1) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  // Act
  // Assert
  std::set<int> a_eth{1, 2, 3};
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(set_empty, 2) {
  // Arrange
  simplestl::set<int> a;
  // Act
  // Assert
  std::set<int> a_eth;
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(set_empty, 3) {
  // Arrange
  simplestl::set<std::string> a{"1", "2", "3", "4"};
  // Act
  // Assert
  std::set<std::string> a_eth{"1", "2", "3", "4"};
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(set_size, 1) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  // Act
  // Assert
  std::set<int> a_eth{1, 2, 3};
  ASSERT_EQ(a.size(), a_eth.size());
}

TEST(set_max_size, 1) {
  // Arrange
  simplestl::set<int> a;
  // Act
  // Assert
  std::set<int> a_eth;
  ASSERT_EQ(a.max_size(), a_eth.max_size());
}

TEST(set_max_size, 2) {
  // Arrange
  simplestl::set<std::string> a;
  // Act
  // Assert
  std::set<std::string> a_eth;
  ASSERT_EQ(a.max_size(), a_eth.max_size());
}

TEST(set_clear, 1) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  // Act
  a.clear();
  // Assert
  std::set<int> a_eth{1, 2, 3};
  a_eth.clear();
  set_test_foo(a, a_eth);
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(set_clear, 2) {
  // Arrange
  simplestl::set<int> a{7, 5, 4, 6, 9, 8, 10, 11, -5};
  // Act
  a.clear();
  // Assert
  std::set<int> a_eth{7, 5, 4, 6, 9, 8, 10, 11, -5};
  a_eth.clear();
  set_test_foo(a, a_eth);
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(set_clear, 3) {
  // Arrange
  simplestl::set<int> a{1, 2, 3, 4, 5};
  // Act
  a.clear();
  // Assert
  std::set<int> a_eth{1, 2, 3, 4, 5};
  a_eth.clear();
  set_test_foo(a, a_eth);
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(set_clear, 4) {
  // Arrange
  simplestl::set<int> a{5, 4, 3, 2, 1};
  // Act
  a.clear();
  // Assert
  std::set<int> a_eth{5, 4, 3, 2, 1};
  a_eth.clear();
  set_test_foo(a, a_eth);
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(set_clear, 5) {
  // Arrange
  simplestl::set<int> a;
  // Act
  a.clear();
  // Assert
  std::set<int> a_eth;
  a_eth.clear();
  set_test_foo(a, a_eth);
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(set_insert, 1) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  // Act
  a.insert(7);
  // Assert
  std::set<int> a_eth{1, 2, 3};
  a_eth.insert(7);
  set_test_foo(a, a_eth);
}

TEST(set_insert, 2) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  // Act
  a.insert(3);
  // Assert
  std::set<int> a_eth{1, 2, 3};
  a_eth.insert(3);
  set_test_foo(a, a_eth);
}

TEST(set_insert, 3) {
  // Arrange
  simplestl::set<int> a;
  // Act
  a.insert(7);
  // Assert
  std::set<int> a_eth;
  a_eth.insert(7);
  set_test_foo(a, a_eth);
}

TEST(set_insert, 4) {
  // Arrange
  simplestl::set<std::string> a{"1", "2", "3"};
  // Act
  a.insert("7");
  // Assert
  std::set<std::string> a_eth{"1", "2", "3"};
  a_eth.insert("7");
  set_test_foo(a, a_eth);
}

TEST(set_insert, 5) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  // Act
  a.insert(3);
  // Assert
  std::set<int> a_eth{1, 2, 3};
  a_eth.insert(3);
  set_test_foo(a, a_eth);
}

TEST(set_insert, 6) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  // Act
  a.insert(-7);
  // Assert
  std::set<int> a_eth{1, 2, 3};
  a_eth.insert(-7);
  set_test_foo(a, a_eth);
}

TEST(set_insert, 7) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  // Act
  auto pair = a.insert(2);
  // Assert
  std::set<int> a_eth{1, 2, 3};
  auto pair_eth = a_eth.insert(2);
  set_test_foo(a, a_eth);
  ASSERT_EQ(*pair.first, *pair_eth.first);
  ASSERT_EQ(pair.second, pair_eth.second);
}

TEST(set_erase, 1) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  auto iter = a.begin();
  // Act
  a.erase(iter);
  // Assert
  std::set<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.begin();
  a_eth.erase(iter_eth);
  set_test_foo(a, a_eth);
}

TEST(set_erase, 2) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  auto iter = a.end();
  // Act
  --iter;
  a.erase(iter);
  // Assert
  std::set<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.end();
  --iter_eth;
  a_eth.erase(iter_eth);
  set_test_foo(a, a_eth);
}

TEST(set_erase, 3) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  auto iter = a.begin();
  ++iter;
  // Act
  a.erase(iter);
  // Assert
  std::set<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.begin();
  ++iter_eth;
  a_eth.erase(iter_eth);
  set_test_foo(a, a_eth);
}

TEST(set_erase, 4) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  auto iter = a.end();
  // Act
  --iter;
  a.erase(iter);
  // Assert
  std::set<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.end();
  --iter_eth;
  a_eth.erase(iter_eth);
  set_test_foo(a, a_eth);
}

TEST(set_erase, 5) {
  // Arrange
  simplestl::set<int> a{7, 4, 2, 5, 1, 11, 8, 9, 12};
  // Act
  // Assert
  std::set<int> a_eth{7, 4, 2, 5, 1, 11, 8, 9, 12};
  auto iter = a.begin();
  auto iter_eth = a_eth.begin();
  ++iter;
  ++iter;
  ++iter_eth;
  ++iter_eth;
  a.erase(iter);
  a_eth.erase(iter_eth);
  iter = a.begin();
  iter_eth = a_eth.begin();
  ++iter;
  ++iter_eth;
  a.erase(iter);
  a_eth.erase(iter_eth);
  iter = a.begin();
  iter_eth = a_eth.begin();
  ++iter;
  ++iter;
  ++iter_eth;
  ++iter_eth;
  a.erase(iter);
  a_eth.erase(iter_eth);
  set_test_foo(a, a_eth);
}

TEST(set_erase, 6) {
  // Arrange
  simplestl::set<int> a{7, 9, 8};
  auto iter = a.end();
  // Act
  --iter;
  a.erase(iter);
  // Assert
  std::set<int> a_eth{7, 9, 8};
  auto iter_eth = a_eth.end();
  --iter_eth;
  a_eth.erase(iter_eth);
  set_test_foo(a, a_eth);
}

TEST(set_erase, 7) {
  // Arrange
  simplestl::set<int> a{7, 6};
  auto iter = a.begin();
  ++iter;
  // Act
  a.erase(iter);
  // Assert
  std::set<int> a_eth{7, 6};
  auto iter_eth = a_eth.begin();
  ++iter_eth;
  a_eth.erase(iter_eth);
  set_test_foo(a, a_eth);
}

TEST(set_erase, 8) {
  // Arrange
  simplestl::set<int> a{2, 4, 3, 5, 6};
  auto iter = a.begin();
  ++iter;
  ++iter;
  // Act
  a.erase(iter);
  // Assert
  std::set<int> a_eth{2, 4, 3, 5, 6};
  auto iter_eth = a_eth.begin();
  ++iter_eth;
  ++iter_eth;
  a_eth.erase(iter_eth);
  set_test_foo(a, a_eth);
}

TEST(set_swap, 1) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  simplestl::set<int> b{4, 5};
  // Act
  a.swap(b);
  // Assert
  std::set<int> a_eth{1, 2, 3};
  std::set<int> b_eth{4, 5};
  a_eth.swap(b_eth);
  set_test_foo(a, a_eth);
  set_test_foo(b, b_eth);
}

TEST(set_swap, 2) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  simplestl::set<int> b;
  // Act
  a.swap(b);
  // Assert
  std::set<int> a_eth{1, 2, 3};
  std::set<int> b_eth;
  a_eth.swap(b_eth);
  set_test_foo(a, a_eth);
  set_test_foo(b, b_eth);
}

TEST(set_swap, 3) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  // Act
  a.swap(a);
  // Assert
  std::set<int> a_eth{1, 2, 3};
  a_eth.swap(a_eth);
  set_test_foo(a, a_eth);
}

TEST(set_merge, 1) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  simplestl::set<int> b{4, 5};
  // Act
  a.merge(b);
  // Assert
  std::set<int> a_eth{1, 2, 3};
  std::set<int> b_eth{4, 5};
  a_eth.merge(b_eth);
  set_test_foo(a, a_eth);
  set_test_foo(b, b_eth);
}

TEST(set_merge, 2) {
  // Arrange
  simplestl::set<int> a;
  simplestl::set<int> b{4, 5};
  // Act
  a.merge(b);
  // Assert
  std::set<int> a_eth;
  std::set<int> b_eth{4, 5};
  a_eth.merge(b_eth);
  set_test_foo(a, a_eth);
  set_test_foo(b, b_eth);
}

TEST(set_merge, 3) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  simplestl::set<int> b;
  // Act
  a.merge(b);
  // Assert
  std::set<int> a_eth{1, 2, 3};
  std::set<int> b_eth;
  a_eth.merge(b_eth);
  set_test_foo(a, a_eth);
  set_test_foo(b, b_eth);
}

TEST(set_merge, 4) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  simplestl::set<int> b{8, 5, 2, 4, 1, 3, 7, 6, 11, 9, 12, 10};
  // Act
  a.merge(b);
  // Assert
  std::set<int> a_eth{1, 2, 3};
  std::set<int> b_eth{8, 5, 2, 4, 1, 3, 7, 6, 11, 9, 12, 10};
  a_eth.merge(b_eth);
  set_test_foo(a, a_eth);
  set_test_foo(b, b_eth);
}

TEST(set_merge, 5) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  simplestl::set<int> b{1, 2, 3};
  // Act
  a.merge(b);
  // Assert
  std::set<int> a_eth{1, 2, 3};
  std::set<int> b_eth{1, 2, 3};
  a_eth.merge(b_eth);
  set_test_foo(a, a_eth);
  set_test_foo(b, b_eth);
}

TEST(set_find, 1) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  // Act
  auto iter = a.find(1);
  // Assert
  std::set<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.find(1);
  ASSERT_EQ(*iter, *iter_eth);
}

TEST(set_find, 2) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  // Act
  auto iter = a.find(3);
  // Assert
  std::set<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.find(3);
  ASSERT_EQ(*iter, *iter_eth);
}

TEST(set_find, 3) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  // Act
  auto iter = a.find(7);
  // Assert
  std::set<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.find(7);
  ASSERT_EQ(iter == a.end(), iter_eth == a_eth.end());
}

TEST(set_contains, 1) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  // Act
  bool res = a.contains(2);
  // Assert
  std::set<int> a_eth{1, 2, 3};
  bool res_eth = a.contains(2);
  ASSERT_EQ(res, res_eth);
}

TEST(set_contains, 2) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  // Act
  bool res = a.contains(7);
  // Assert
  std::set<int> a_eth{1, 2, 3};
  bool res_eth = a.contains(7);
  ASSERT_EQ(res, res_eth);
}

TEST(set_emplace, 1) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  // Act
  auto res = a.emplace(4, 5, 6);
  // Assert
  std::set<int> a_eth{1, 2, 3, 4, 5, 6};
  simplestl::vector<std::pair<int, bool>> res_eth{
      std::pair<int, bool>(4, true), std::pair<int, bool>(5, true),
      std::pair<int, bool>(6, true)};
  auto iter_eth = res_eth.begin();
  for (auto iter : res) {
    ASSERT_EQ(*(iter.first), (*iter_eth).first);
    ASSERT_EQ(iter.second, (*iter_eth).second);
    ++iter_eth;
  }
  set_test_foo(a, a_eth);
}

TEST(set_emplace, 2) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  // Act
  auto res = a.emplace(1, 2, 3);
  // Assert
  std::set<int> a_eth{1, 2, 3};
  for (auto iter : res) {
    // ASSERT_EQ(iter.first, a.end());
    ASSERT_EQ(iter.second, false);
  }
  set_test_foo(a, a_eth);
}

TEST(set_emplace, 3) {
  // Arrange
  simplestl::set<int> a{1, 2, 3};
  // Act
  auto res = a.emplace(4, 3, 6);
  // Assert
  std::set<int> a_eth{1, 2, 3, 4, 6};
  simplestl::vector<std::pair<int, bool>> res_eth{
      std::pair<int, bool>(4, true), std::pair<int, bool>(3, false),
      std::pair<int, bool>(6, true)};
  auto iter_eth = res_eth.begin();
  for (auto iter : res) {
    // ASSERT_EQ(*(iter.first), (*iter_eth).first);
    ASSERT_EQ(iter.second, (*iter_eth).second);
    ++iter_eth;
  }
  set_test_foo(a, a_eth);
}

TEST(stack_default_constructor, 1) {
  // Arrange
  // Act
  simplestl::stack<int> a;
  // Assert
  std::stack<int> a_eth;
  ASSERT_EQ(a.size(), a_eth.size());
}

TEST(stack_parameterized_constructor, 1) {
  // Arrange
  // Act
  simplestl::stack<int> a{1, 2, 3};
  // Assert
  std::stack<int> a_eth;
  a_eth.push(1);
  a_eth.push(2);
  a_eth.push(3);
  ASSERT_EQ(a.size(), a_eth.size());
  while (a.size() != 0) {
    ASSERT_EQ(a.top(), a_eth.top());
    a.pop();
    a_eth.pop();
  }
}

TEST(stack_copy_constructor, 1) {
  // Arrange
  simplestl::stack<int> b;
  b.push(1);
  b.push(2);
  b.push(3);
  // Act
  simplestl::stack<int> a(b);
  // Assert
  std::stack<int> b_eth;
  b_eth.push(1);
  b_eth.push(2);
  b_eth.push(3);
  std::stack<int> a_eth(b_eth);
  ASSERT_EQ(a.size(), a_eth.size());
  while (a.size() != 0) {
    ASSERT_EQ(a.top(), a_eth.top());
    a.pop();
    a_eth.pop();
  }
}

TEST(stack_move_constructor, 1) {
  // Arrange
  simplestl::stack<int> b;
  b.push(1);
  b.push(2);
  b.push(3);
  // Act
  simplestl::stack<int> a(std::move(b));
  // Assert
  std::stack<int> b_eth;
  b_eth.push(1);
  b_eth.push(2);
  b_eth.push(3);
  std::stack<int> a_eth(std::move(b_eth));
  ASSERT_EQ(a.size(), a_eth.size());
  while (a.size() != 0) {
    ASSERT_EQ(a.top(), a_eth.top());
    a.pop();
    a_eth.pop();
  }
}

TEST(stack_eq_overriten_operator_r_value, 1) {
  // Arrange
  simplestl::stack<int> a;
  simplestl::stack<int> b;
  b.push(1);
  b.push(2);
  b.push(3);
  // Act
  a = std::move(b);
  // Assert
  std::stack<int> b_eth;
  b_eth.push(1);
  b_eth.push(2);
  b_eth.push(3);
  std::stack<int> a_eth;
  a_eth = std::move(b_eth);
  ASSERT_EQ(a.size(), a_eth.size());
  while (a.size() != 0) {
    ASSERT_EQ(a.top(), a_eth.top());
    a.pop();
    a_eth.pop();
  }
}

TEST(stack_eq_overriten_operator_r_value, 2) {
  // Arrange
  simplestl::stack<int> a;
  a.push(1);
  a.push(2);
  a.push(3);
  simplestl::stack<int> b;
  b.push(1);
  b.push(2);
  b.push(3);
  // Act
  a = std::move(b);
  // Assert
  std::stack<int> b_eth;
  b_eth.push(1);
  b_eth.push(2);
  b_eth.push(3);
  std::stack<int> a_eth;
  a_eth.push(1);
  a_eth.push(2);
  a_eth.push(3);
  a_eth = std::move(b_eth);
  ASSERT_EQ(a.size(), a_eth.size());
  while (a.size() != 0) {
    ASSERT_EQ(a.top(), a_eth.top());
    a.pop();
    a_eth.pop();
  }
}

TEST(stack_top, 1) {
  // Arrange
  simplestl::stack<int> a;
  a.push(1);
  a.push(2);
  a.push(3);
  // Act
  // Assert
  std::stack<int> a_eth;
  a_eth.push(1);
  a_eth.push(2);
  a_eth.push(3);
  ASSERT_EQ(a.top(), a_eth.top());
}

TEST(stack_empty, 1) {
  // Arrange
  simplestl::stack<int> a;
  a.push(1);
  a.push(2);
  a.push(3);
  // Act
  // Assert
  std::stack<int> a_eth;
  a_eth.push(1);
  a_eth.push(2);
  a_eth.push(3);
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(stack_empty, 2) {
  // Arrange
  simplestl::stack<int> a;
  // Act
  // Assert
  std::stack<int> a_eth;
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(stack_size, 1) {
  // Arrange
  simplestl::stack<int> a;
  a.push(1);
  a.push(2);
  a.push(3);
  // Act
  // Assert
  std::stack<int> a_eth;
  a_eth.push(1);
  a_eth.push(2);
  a_eth.push(3);
  ASSERT_EQ(a.size(), a_eth.size());
}

TEST(stack_size, 2) {
  // Arrange
  simplestl::stack<int> a;
  // Act
  // Assert
  std::stack<int> a_eth;
  ASSERT_EQ(a.size(), a_eth.size());
}

TEST(stack_push, 1) {
  // Arrange
  simplestl::stack<int> a;
  // Act
  a.push(7);
  // Assert
  std::stack<int> a_eth;
  a_eth.push(7);
  ASSERT_EQ(a.top(), a_eth.top());
  ASSERT_EQ(a.size(), a_eth.size());
}

TEST(stack_push, 2) {
  // Arrange
  simplestl::stack<int> a;
  // Act
  a.push(1);
  a.push(2);
  a.push(3);
  // Assert
  std::stack<int> a_eth;
  a_eth.push(1);
  a_eth.push(2);
  a_eth.push(3);
  ASSERT_EQ(a.size(), a_eth.size());
  while (a.size() != 0) {
    ASSERT_EQ(a.top(), a_eth.top());
    a.pop();
    a_eth.pop();
  }
}

TEST(stack_pop, 1) {
  // Arrange
  simplestl::stack<int> a;
  // Act
  a.pop();
  // Assert
  std::stack<int> a_eth;
  a_eth.pop();
  ASSERT_EQ(a.size(), a_eth.size());
}

TEST(stack_pop, 2) {
  // Arrange
  simplestl::stack<int> a;
  // Act
  a.push(1);
  a.push(2);
  a.push(3);
  // Assert
  std::stack<int> a_eth;
  a_eth.push(1);
  a_eth.push(2);
  a_eth.push(3);
  while (a.size() != 0) {
    a.pop();
    a_eth.pop();
    ASSERT_EQ(a.size(), a_eth.size());
  }
}

TEST(stack_swap, 1) {
  // Arrange
  simplestl::stack<int> a;
  simplestl::stack<int> b;
  b.push(1);
  b.push(2);
  b.push(3);
  // Act
  a.swap(b);
  // Assert
  std::stack<int> a_eth;
  std::stack<int> b_eth;
  b_eth.push(1);
  b_eth.push(2);
  b_eth.push(3);
  a_eth.swap(b_eth);
  ASSERT_EQ(a.size(), a_eth.size());
  while (a.size() != 0) {
    ASSERT_EQ(a.top(), a_eth.top());
    a.pop();
    a_eth.pop();
  }
  ASSERT_EQ(b.size(), b_eth.size());
}

TEST(stack_swap, 2) {
  // Arrange
  simplestl::stack<int> a;
  a.push(4);
  a.push(5);
  simplestl::stack<int> b;
  b.push(1);
  b.push(2);
  b.push(3);
  // Act
  a.swap(b);
  // Assert
  std::stack<int> a_eth;
  a_eth.push(4);
  a_eth.push(5);
  std::stack<int> b_eth;
  b_eth.push(1);
  b_eth.push(2);
  b_eth.push(3);
  a_eth.swap(b_eth);
  ASSERT_EQ(a.size(), a_eth.size());
  while (a.size() != 0) {
    ASSERT_EQ(a.top(), a_eth.top());
    a.pop();
    a_eth.pop();
  }
  ASSERT_EQ(b.size(), b_eth.size());
  while (b.size() != 0) {
    ASSERT_EQ(b.top(), b_eth.top());
    b.pop();
    b_eth.pop();
  }
}

TEST(stack_emplace_front, 1) {
  // Arrange
  simplestl::stack<int> a{1, 2, 3};
  // Act
  a.emplace_front(4, 5, 6);
  // Assert
  std::stack<int> a_eth;
  a_eth.push(1);
  a_eth.push(2);
  a_eth.push(3);
  a_eth.push(4);
  a_eth.push(5);
  a_eth.push(6);
  ASSERT_EQ(a.size(), a_eth.size());
  while (a.size() != 0) {
    ASSERT_EQ(a.top(), a_eth.top());
    a.pop();
    a_eth.pop();
  }
}

TEST(vector_default_constructor, 1) {
  // Arrange
  // Act
  simplestl::vector<int> a;
  // Assert
  std::vector<int> a_eth;
  ASSERT_EQ(a.size(), a_eth.size());
  ASSERT_EQ(a.capacity(), a_eth.capacity());
}

TEST(vector_parameterized_constructor, 1) {
  // Arrange
  // Act
  simplestl::vector<int> a(5);
  // Assert
  std::vector<int> a_eth(5);
  ASSERT_EQ(a.size(), a_eth.size());
  ASSERT_EQ(a.capacity(), a_eth.capacity());
}

TEST(vector_parameterized_constructor, 2) {
  // Arrange
  simplestl::vector<int> a;
  // Act
  // Assert
  ASSERT_THROW(simplestl::vector<int> b(a.max_size() + 1);, std::runtime_error);
}

TEST(vector_parameterized_constructor, 3) {
  // Arrange
  // Act
  simplestl::vector<int> a{1, 2, 3};
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  ASSERT_EQ(a.size(), a_eth.size());
  ASSERT_EQ(a.capacity(), a_eth.capacity());
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

TEST(vector_copy_constructor, 1) {
  // Arrange
  simplestl::vector<int> b{1, 2, 3};
  // Act
  simplestl::vector<int> a(b);
  // Assert
  std::vector<int> b_eth{1, 2, 3};
  std::vector<int> a_eth(b_eth);
  ASSERT_EQ(a.size(), a_eth.size());
  ASSERT_EQ(a.capacity(), a_eth.capacity());
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

TEST(vector_move_constructor, 1) {
  // Arrange
  simplestl::vector<int> b{1, 2, 3};
  // Act
  simplestl::vector<int> a(std::move(b));
  // Assert
  std::vector<int> b_eth{1, 2, 3};
  std::vector<int> a_eth(std::move(b_eth));
  ASSERT_EQ(a.size(), a_eth.size());
  ASSERT_EQ(a.capacity(), a_eth.capacity());
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

TEST(vector_eq_overriten_operator_r_value, 1) {
  // Arrange
  simplestl::vector<int> a;
  simplestl::vector<int> b{1, 2, 3};
  // Act
  a = std::move(b);
  // Assert
  std::vector<int> b_eth{1, 2, 3};
  std::vector<int> a_eth;
  a_eth = std::move(b_eth);
  ASSERT_EQ(a.size(), a_eth.size());
  ASSERT_EQ(a.capacity(), a_eth.capacity());
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

TEST(vector_eq_overriten_operator_r_value, 2) {
  // Arrange
  simplestl::vector<int> a{3, 2, 1};
  simplestl::vector<int> b{1, 2, 3};
  // Act
  a = std::move(b);
  // Assert
  std::vector<int> a_eth{3, 2, 1};
  std::vector<int> b_eth{1, 2, 3};
  a_eth = std::move(b_eth);
  ASSERT_EQ(a.size(), a_eth.size());
  ASSERT_EQ(a.capacity(), a_eth.capacity());
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

TEST(vector_at, 1) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a.at(i), a_eth.at(i));
  }
}

TEST(vector_at, 2) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  // Assert
  ASSERT_THROW(a.at(-1), std::runtime_error);
}

TEST(vector_at, 3) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  // Assert
  ASSERT_THROW(a.at(10), std::runtime_error);
}

TEST(vector_square_brackets, 1) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

TEST(vector_square_brackets, 2) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  // Assert
  ASSERT_THROW(a[-1], std::runtime_error);
}

TEST(vector_square_brackets, 3) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  // Assert
  ASSERT_THROW(a[10], std::runtime_error);
}

TEST(vector_front, 1) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  ASSERT_EQ(a.front(), a_eth.front());
}

TEST(vector_back, 1) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  ASSERT_EQ(a.back(), a_eth.back());
}

TEST(vector_back, 2) {
  // Arrange
  simplestl::vector<int> a{1};
  // Act
  // Assert
  std::vector<int> a_eth{1};
  ASSERT_EQ(a.back(), a_eth.back());
}

TEST(vector_data, 1) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  int *add = a.data();
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  int *add_eth = a_eth.data();
  ASSERT_EQ(*add, *add_eth);
}

TEST(vector_begin_iter, 1) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  simplestl::vector<int>::iterator iter = a.begin();
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  std::vector<int>::iterator iter_eth = a_eth.begin();
  ASSERT_EQ(*iter, *iter_eth);
}

TEST(vector_end_iter, 1) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  simplestl::vector<int>::iterator iter = a.end();
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  std::vector<int>::iterator iter_eth = a_eth.end();
  ASSERT_EQ(*--iter, *--iter_eth);
}

TEST(vector_end_iter, 2) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  simplestl::vector<int>::iterator iter = a.end();
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  std::vector<int>::iterator iter_eth = a_eth.end();
  ASSERT_EQ(*--iter, *--iter_eth);
}

TEST(vector_iterator_methods, 1) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  auto iter = a.begin();
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.begin();
  for (; iter != a.end(); ++iter, ++iter_eth) {
    ASSERT_EQ(*iter, *iter_eth);
  }
}

TEST(vector_iterator_methods, 2) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  auto iter = a.end();
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  auto iter_eth = a_eth.end();
  for (; iter != a.begin();) {
    --iter;
    --iter_eth;
    ASSERT_EQ(*iter, *iter_eth);
  }
}

TEST(vector_empty, 1) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(vector_empty, 2) {
  // Arrange
  simplestl::vector<int> a;
  // Act
  // Assert
  std::vector<int> a_eth;
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(vector_empty, 3) {
  // Arrange
  simplestl::vector<int> a(0);
  // Act
  // Assert
  std::vector<int> a_eth(0);
  ASSERT_EQ(a.empty(), a_eth.empty());
}

TEST(vector_size, 1) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  ASSERT_EQ(a.size(), a_eth.size());
}

TEST(vector_max_size, 1) {
  // Arrange
  simplestl::vector<int> a;
  // Act
  // Assert
  std::vector<int> a_eth;
  ASSERT_EQ(a.max_size(), a_eth.max_size());
}

TEST(vector_max_size, 2) {
  // Arrange
  simplestl::vector<std::string> a{"qwert"};
  // Act
  // Assert
  std::vector<std::string> a_eth{"qwert"};
  ASSERT_EQ(a.max_size(), a_eth.max_size());
}

TEST(vector_max_size, 3) {
  // Arrange
  simplestl::vector<double> a;
  // Act
  // Assert
  std::vector<double> a_eth;
  ASSERT_EQ(a.max_size(), a_eth.max_size());
}

TEST(vector_reserve, 1) {
  // Arrange
  simplestl::vector<std::string> a;
  // Act
  a.reserve(8);
  // Assert
  std::vector<std::string> a_eth;
  a_eth.reserve(8);
  ASSERT_EQ(a.capacity(), a_eth.capacity());
}

TEST(vector_reserve, 2) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  a.reserve(1);
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  a_eth.reserve(1);
  ASSERT_EQ(a.capacity(), a_eth.capacity());
}

TEST(vector_reserve, 3) {
  // Arrange
  simplestl::vector<std::string> a;
  // Act
  // Assert
  ASSERT_THROW(a.reserve(a.max_size() + 1), std::runtime_error);
}

TEST(vector_capacity, 1) {
  // Arrange
  simplestl::vector<int> a;
  // Act
  // Assert
  std::vector<int> a_eth;
  ASSERT_EQ(a.capacity(), a_eth.capacity());
}

TEST(vector_capacity, 2) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  ASSERT_EQ(a.capacity(), a_eth.capacity());
}

TEST(vector_shrink_to_fit, 1) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  a.shrink_to_fit();
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  a_eth.shrink_to_fit();
  ASSERT_EQ(a.capacity(), a_eth.capacity());
}

TEST(vector_shrink_to_fit, 2) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  a.reserve(9);
  a.shrink_to_fit();
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  a_eth.reserve(9);
  a_eth.shrink_to_fit();
  ASSERT_EQ(a.capacity(), a_eth.capacity());
}

TEST(vector_clear, 1) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  a.clear();
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  a_eth.clear();
  ASSERT_EQ(a.size(), a_eth.size());
  ASSERT_EQ(a.capacity(), a_eth.capacity());
  ASSERT_EQ(*a.data(), *a_eth.data());
}

TEST(vector_insert, 1) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  simplestl::vector<int>::iterator iter = a.begin();
  // Act
  a.insert(iter, 7);
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  std::vector<int>::iterator iter_eth = a_eth.begin();
  a_eth.insert(iter_eth, 7);
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

TEST(vector_insert, 2) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  simplestl::vector<int>::iterator iter = a.end();
  // Act
  a.insert(iter, 7);
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  std::vector<int>::iterator iter_eth = a_eth.end();
  a_eth.insert(iter_eth, 7);
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

TEST(vector_insert, 3) {
  // Arrange
  simplestl::vector<int> a;
  simplestl::vector<int>::iterator iter = a.begin();
  // Act
  a.insert(iter, 7);
  // Assert
  std::vector<int> a_eth;
  std::vector<int>::iterator iter_eth = a_eth.begin();
  a_eth.insert(iter_eth, 7);
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

TEST(vector_insert, 4) {
  // Arrange
  simplestl::vector<int> a;
  simplestl::vector<int>::iterator iter = a.end();
  // Act
  a.insert(iter, 7);
  // Assert
  std::vector<int> a_eth;
  std::vector<int>::iterator iter_eth = a_eth.end();
  a_eth.insert(iter_eth, 7);
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

TEST(vector_insert, 5) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  simplestl::vector<int>::iterator iter = a.begin();
  // Act
  ++iter;
  a.insert(iter, 7);
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  std::vector<int>::iterator iter_eth = a_eth.begin();
  ++iter_eth;
  a_eth.insert(iter_eth, 7);
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

TEST(vector_erase, 1) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  simplestl::vector<int>::iterator iter = a.begin();
  // Act
  a.erase(iter);
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  std::vector<int>::iterator iter_eth = a_eth.begin();
  a_eth.erase(iter_eth);
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

TEST(vector_erase, 2) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  simplestl::vector<int>::iterator iter = a.end();
  // Act
  --iter;
  a.erase(iter);
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  std::vector<int>::iterator iter_eth = a_eth.end();
  --iter_eth;
  a_eth.erase(iter_eth);
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

TEST(vector_push_back, 1) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  a.push_back(7);
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  a_eth.push_back(7);
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

TEST(vector_push_back, 2) {
  // Arrange
  simplestl::vector<int> a;
  // Act
  a.push_back(7);
  // Assert
  std::vector<int> a_eth;
  a_eth.push_back(7);
  ASSERT_EQ(a.size(), a_eth.size());
  ASSERT_EQ(a.capacity(), a_eth.capacity());
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

TEST(vector_pop_back, 1) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  a.pop_back();
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  a_eth.pop_back();
  ASSERT_EQ(a.size(), a_eth.size());
  ASSERT_EQ(a.capacity(), a_eth.capacity());
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

TEST(vector_pop_back, 2) {
  // Arrange
  simplestl::vector<int> a;
  // Act
  a.pop_back();
  // Assert
  std::vector<int> a_eth;
  a_eth.pop_back();
  ASSERT_EQ(a.size(), a_eth.size());
  ASSERT_EQ(a.capacity(), a_eth.capacity());
}

TEST(vector_swap, 1) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  simplestl::vector<int> b{4, 5};
  // Act
  a.swap(b);
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  std::vector<int> b_eth{4, 5};
  a_eth.swap(b_eth);
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
  ASSERT_EQ(a.size(), a_eth.size());
  ASSERT_EQ(a.capacity(), a_eth.capacity());
  for (size_t i = 0; i < b.size(); i++) {
    ASSERT_EQ(b[i], b_eth[i]);
  }
  ASSERT_EQ(b.size(), b_eth.size());
  ASSERT_EQ(b.capacity(), b_eth.capacity());
}

TEST(vector_swap, 2) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  simplestl::vector<int> b;
  // Act
  a.swap(b);
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  std::vector<int> b_eth;
  a_eth.swap(b_eth);
  ASSERT_EQ(a.size(), a_eth.size());
  ASSERT_EQ(a.capacity(), a_eth.capacity());
  for (size_t i = 0; i < b.size(); i++) {
    ASSERT_EQ(b[i], b_eth[i]);
  }
  ASSERT_EQ(b.size(), b_eth.size());
  ASSERT_EQ(b.capacity(), b_eth.capacity());
}

TEST(vector_swap, 3) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  a.swap(a);
  // Assert
  std::vector<int> a_eth{1, 2, 3};
  a_eth.swap(a_eth);
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
  ASSERT_EQ(a.size(), a_eth.size());
  ASSERT_EQ(a.capacity(), a_eth.capacity());
}

TEST(vector_emplace, 1) {
  // Arrange
  simplestl::vector<int> a{4, 5, 6};
  // Act
  auto it = a.begin();
  it = a.emplace(it, 1, 2, 3);
  // Assert
  std::vector<int> a_eth{1, 2, 3, 4, 5, 6};
  ASSERT_EQ(a.size(), a_eth.size());
  ASSERT_EQ(*it, 3);
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

TEST(vector_emplace, 2) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  auto it = a.end();
  it = a.emplace(it, 4, 5, 6);
  // Assert
  std::vector<int> a_eth{1, 2, 3, 4, 5, 6};
  ASSERT_EQ(a.size(), a_eth.size());
  ASSERT_EQ(*it, 6);
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

TEST(vector_emplace_back, 1) {
  // Arrange
  simplestl::vector<int> a{1, 2, 3};
  // Act
  a.emplace_back(4, 5, 6);
  // Assert
  std::vector<int> a_eth{1, 2, 3, 4, 5, 6};
  ASSERT_EQ(a.size(), a_eth.size());
  for (size_t i = 0; i < a.size(); i++) {
    ASSERT_EQ(a[i], a_eth[i]);
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}