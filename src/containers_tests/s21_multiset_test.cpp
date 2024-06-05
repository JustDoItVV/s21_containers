#include "../s21_containers_test.h"

TEST(multiset, defaultConstructor) {
  s21::multiset<int> s21IntMultiset;
  s21::multiset<char> s21CharMultiset;
  s21::multiset<double> s21DoubleMultiset;
  std::multiset<int> stlIntMultiset;
  std::multiset<char> stlCharMultiset;
  std::multiset<double> stlDoubleMultiset;
  EXPECT_EQ(s21IntMultiset.empty(), stlIntMultiset.empty());
  EXPECT_EQ(s21CharMultiset.empty(), stlCharMultiset.empty());
  EXPECT_EQ(s21DoubleMultiset.empty(), stlDoubleMultiset.empty());
}

TEST(multiset, initializerConstructor1) {
  s21::multiset<int> s21EmptyMultiset{};
  std::multiset<int> stlEmptyMultiset{};
  auto s21Iter = s21EmptyMultiset.begin();
  auto stlIter = stlEmptyMultiset.begin();
  auto s21IterEnd = s21EmptyMultiset.end();
  EXPECT_EQ(s21EmptyMultiset.size(), stlEmptyMultiset.size());
  for (; s21Iter != s21IterEnd; ++s21Iter, ++stlIter)
    EXPECT_EQ(*s21Iter, *stlIter);
}

TEST(multiset, initializerConstructor2) {
  s21::multiset<int> s21Multiset{0, 1, 2, 3, 4, 5, 6, 7};
  std::multiset<int> stlMultiset{0, 1, 2, 3, 4, 5, 6, 7};
  auto s21Iter = s21Multiset.begin();
  auto stlIter = stlMultiset.begin();
  auto s21IterEnd = s21Multiset.end();
  EXPECT_EQ(s21Multiset.size(), stlMultiset.size());
  for (; s21Iter != s21IterEnd; ++s21Iter, ++stlIter)
    EXPECT_EQ(*s21Iter, *stlIter);
}

TEST(multiset, initializerConstructor3) {
  s21::multiset<int> s21Multiset{0, 1, 2, 3, 3, 1, 6, 7, 6};
  std::multiset<int> stlMultiset{0, 1, 2, 3, 3, 1, 6, 7, 6};
  auto s21Iter = s21Multiset.begin();
  auto stlIter = stlMultiset.begin();
  auto s21IterEnd = s21Multiset.end();
  EXPECT_EQ(s21Multiset.size(), stlMultiset.size());
  for (; s21Iter != s21IterEnd; ++s21Iter, ++stlIter)
    EXPECT_EQ(*s21Iter, *stlIter);
}

TEST(multiset, copyConstructor) {
  s21::multiset<int> s21Multiset{0, 1, 2, 3, 3, 1, 6, 7, 6};
  std::multiset<int> stlMultiset{0, 1, 2, 3, 3, 1, 6, 7, 6};
  s21::multiset<int> s21MultisetCopy = s21Multiset;
  std::multiset<int> stlMultisetCopy = stlMultiset;
  auto s21Iter = s21MultisetCopy.begin();
  auto stlIter = stlMultisetCopy.begin();
  auto s21IterEnd = s21MultisetCopy.end();
  EXPECT_EQ(s21MultisetCopy.size(), stlMultisetCopy.size());
  for (; s21Iter != s21IterEnd; ++s21Iter, ++stlIter)
    EXPECT_EQ(*s21Iter, *stlIter);
}

TEST(multiset, moveConstructor) {
  s21::multiset<int> s21Multiset{0, 1, 2, 3, 3, 1, 6, 7, 6};
  std::multiset<int> stlMultiset{0, 1, 2, 3, 3, 1, 6, 7, 6};
  s21::multiset<int> s21MultisetMove = s21Multiset;
  std::multiset<int> stlMultisetMove = stlMultiset;
  auto s21Iter = s21MultisetMove.begin();
  auto stlIter = stlMultisetMove.begin();
  auto s21IterEnd = s21MultisetMove.end();
  EXPECT_EQ(s21MultisetMove.size(), stlMultisetMove.size());
  for (; s21Iter != s21IterEnd; ++s21Iter, ++stlIter)
    EXPECT_EQ(*s21Iter, *stlIter);
}