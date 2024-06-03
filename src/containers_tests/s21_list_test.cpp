#include <list>
#include <iostream>

#include "../s21_containers_test.h"

TEST(List_Member_functions, default_constructor) {
  EXPECT_NO_THROW(s21::list<int>());
  EXPECT_NO_THROW(s21::list<char>());
  EXPECT_NO_THROW(s21::list<double>());
}

// list capacity tests

TEST(List_Capacity, empty) {
  s21::list<int> s21EmptyIntList{};
  std::list<int> stlEmptyIntList{};
  EXPECT_EQ(s21EmptyIntList.empty(), stlEmptyIntList.empty());
}

TEST(List_Capacity, size) {
  s21::list<int> s21EmptyIntList{};
  std::list<int> stlEmptyIntList{};
  EXPECT_EQ(s21EmptyIntList.size(), stlEmptyIntList.size());
}

TEST(List_Capacity, maxsize) {
  s21::list<int> s21EmptyIntList{};
  std::list<int> stlEmptyIntList{};
  EXPECT_EQ(s21EmptyIntList.max_size(), stlEmptyIntList.max_size());
}

// TEST(List_iterators, begin) {
//   s21::list<int> s21EmptyIntList{};
//   EXPECT_EQ(s21EmptyIntList.begin(), NULL);
// }

// TEST(List_iterators, end) {
//   s21::list<int> s21EmptyIntList{};
//   EXPECT_EQ(s21EmptyIntList.end(), NULL);
// }