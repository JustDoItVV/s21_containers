#include <set>

#include "../s21_containers_test.h"

TEST(set, constructorDefault) {
  s21::set<char> setMy;
  std::set<char> setBase;

  EXPECT_EQ(setMy.empty(), setBase.empty());
}

TEST(set, constructorInitializer) {
  s21::set<char> setMy = {'a', 'b', 'c'};
  std::set<char> setBase = {'a', 'b', 'c'};
  auto iterMy = setMy.begin();
  auto iterBase = setBase.begin();

  EXPECT_EQ(setMy.size(), setBase.size());
  for (; iterMy != setMy.end(); ++iterMy, ++iterBase) {
    EXPECT_TRUE(*iterBase == *iterMy);
  }
}

TEST(set, constructorInitializer2) {
  s21::set<char> setMy = {};
  std::set<char> setBase = {};
  auto iterMy = setMy.begin();
  auto iterBase = setBase.begin();

  EXPECT_EQ(setMy.size(), setBase.size());
  for (; iterMy != setMy.end(); ++iterMy, ++iterBase) {
    EXPECT_TRUE(*iterBase == *iterMy);
  }
}

TEST(set, constructorCopy) {
  s21::set<int> setMy = {1, 2, 3, 4, 5};
  std::set<int> setBase = {1, 2, 3, 4, 5};
  s21::set<int> setMy_copy = setMy;
  std::set<int> setBase_copy = setBase;
  auto iterMy = setMy_copy.begin();
  auto iterBase = setBase_copy.begin();

  EXPECT_EQ(setMy_copy.size(), setBase_copy.size());
  for (; iterMy != setMy_copy.end(); ++iterMy, ++iterBase) {
    EXPECT_TRUE(*iterBase == *iterMy);
  }
}

TEST(set, constructorMove) {
  s21::set<int> setMy = {1, 2, 3, 4, 5};
  std::set<int> setBase = {1, 2, 3, 4, 5};
  s21::set<int> setMy_copy = std::move(setMy);
  std::set<int> setBase_copy = std::move(setBase);
  auto iterMy = setMy_copy.begin();
  auto iterBase = setBase_copy.begin();

  EXPECT_EQ(setMy.size(), setBase.size());
  EXPECT_EQ(setMy_copy.size(), setBase_copy.size());
  for (; iterMy != setMy_copy.end(); ++iterMy, ++iterBase) {
    EXPECT_TRUE(*iterBase == *iterMy);
  }
}

TEST(set, setIterators) {
  s21::set<std::string> setMy = {"This", "is", "my", "set"};
  std::set<std::string> setBase = {"This", "is", "my", "set"};
  auto iterMy = setMy.begin();
  auto iterBase = setBase.begin();

  EXPECT_TRUE(*iterBase == *iterMy);
  iterMy = setMy.end();
  iterBase = setBase.end();
  --iterMy;
  --iterBase;
  EXPECT_TRUE(*iterBase == *iterMy);
}

TEST(set, capacity) {
  s21::set<char> setMy;
  std::set<char> setBase;

  EXPECT_EQ(setMy.empty(), setBase.empty());
  EXPECT_EQ(setMy.size(), setBase.size());
  setMy.insert('b');
  setBase.insert('c');
  EXPECT_EQ(setMy.empty(), setBase.empty());
  EXPECT_EQ(setMy.size(), setBase.size());
}

TEST(set, clear) {
  s21::set<char> setMy;
  std::set<char> setBase;
  setMy.clear();
  setBase.clear();

  EXPECT_EQ(setMy.empty(), setBase.empty());
  EXPECT_EQ(setMy.size(), setBase.size());
  setMy.insert('a');
  setBase.insert('b');
  EXPECT_EQ(setMy.empty(), setBase.empty());
  EXPECT_EQ(setMy.size(), setBase.size());
  setMy.clear();
  setBase.clear();
  EXPECT_EQ(setMy.empty(), setBase.empty());
  EXPECT_EQ(setMy.size(), setBase.size());
}

TEST(set, insert) {
  s21::set<std::string> setMy = {"This", "is", "my", "set"};
  std::set<std::string> setBase = {"This", "is", "my", "set"};
  auto my_pr = setMy.insert("best");
  auto orig_pr = setBase.insert("best");

  EXPECT_TRUE(my_pr.second == orig_pr.second);
  EXPECT_TRUE(*my_pr.first == *orig_pr.first);
  my_pr = setMy.insert("is");
  orig_pr = setBase.insert("is");
  EXPECT_TRUE(my_pr.second == orig_pr.second);
  EXPECT_TRUE(*my_pr.first == *orig_pr.first);
}

TEST(set, erase) {
  s21::set<int> setMy = {5, 4, 3, 2, 7, 8, 9};
  std::set<int> setBase = {5, 4, 3, 2, 7, 8, 9};
  auto size = setMy.size();
  setMy.erase(setMy.end());
  auto new_size = setMy.size();

  EXPECT_NE(size, new_size);
  setMy.erase(setMy.begin());
  setBase.erase(setBase.begin());
  auto iterMy = setMy.begin();
  auto iterBase = setBase.begin();

  for (; iterMy != setMy.end(); ++iterMy, ++iterBase) {
    EXPECT_TRUE(*iterBase == *iterMy);
  }
}

TEST(set, swap) {
  s21::set<int> setMy = {1};
  s21::set<int> my_swap_set = {3, 4, 5};

  setMy.swap(my_swap_set);
  EXPECT_EQ(setMy.size(), 3);
  EXPECT_EQ(my_swap_set.size(), 1);
  EXPECT_EQ(*setMy.begin(), 3);
  EXPECT_EQ(*my_swap_set.begin(), 1);
}

TEST(set, merge) {
  s21::set<int> setMy = {1};
  s21::set<int> my_merge_set = {3, 4, 5};
  setMy.merge(my_merge_set);

  std::set<int> setBase = {1};
  std::set<int> orig_merge_set = {3, 4, 5};
  setBase.merge(orig_merge_set);
  auto iterMy = setMy.begin();
  auto iterBase = setBase.begin();
  for (; iterMy != setMy.end(); ++iterMy, ++iterBase) {
    EXPECT_TRUE(*iterBase == *iterMy);
  }
  EXPECT_EQ(setBase.size(), setMy.size());
  EXPECT_EQ(my_merge_set.size(), orig_merge_set.size());
}

TEST(set, find) {
  s21::set<double> setMy = {2.1, 2.2, 2.3, 2.4, 2.5, 2.6};
  s21::set<double> setBase = {2.1, 2.2, 2.3, 2.4, 2.5, 2.6};
  auto iterMy = setMy.find(2.4);
  auto iterBase = setBase.find(2.4);
  EXPECT_TRUE(*iterBase == *iterMy);
}

TEST(set, contains) {
  s21::set<double> setMy = {2.1, 2.2, 2.3, 2.4, 2.5, 2.6};
  s21::set<double> setBase = {2.1, 2.2, 2.3, 2.4, 2.5, 2.6};
  EXPECT_EQ(setMy.contains(2), false);
  EXPECT_EQ(setMy.contains(2.1), true);
}