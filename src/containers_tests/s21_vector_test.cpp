#include <vector>

#include "../s21_containers_test.h"

namespace {

TEST(vector, constructorDefault) {
  s21::vector<int> s21_vector;
  std::vector<int> std_vector;
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(vector, constructorInitializer) {
  s21::vector<int> s21_vector = {1, 2, 3, 4};
  std::vector<int> std_vector = {1, 2, 3, 4};
  EXPECT_EQ(s21_vector.front(), std_vector.front());
  EXPECT_EQ(s21_vector.back(), std_vector.back());
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(vector, constructorParameterized) {
  s21::vector<double> s21_vector(5);
  std::vector<double> std_vector(5);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}
TEST(vector, constructorCopy) {
  s21::vector<char> s21_vector_1 = {'a', 'b', 'c', 'd'};
  std::vector<char> std_vector_1 = {'a', 'b', 'c', 'd'};
  s21::vector<char> s21_vector_2 = s21_vector_1;
  std::vector<char> std_vector_2 = std_vector_1;

  EXPECT_EQ(s21_vector_1.size(), s21_vector_2.size());
  EXPECT_EQ(std_vector_1.size(), std_vector_2.size());
  auto it1 = s21_vector_1.begin();
  auto it2 = s21_vector_2.begin();
  while (it1 != s21_vector_1.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1, ++it2;
  }
}
TEST(vector, constructorMove) {
  s21::vector<char> s21_vector_1 = {'a', 'b', 'c', 'd'};
  std::vector<char> std_vector_1 = {'a', 'b', 'c', 'd'};
  s21::vector<char> s21_vector_2 = std::move(s21_vector_1);
  std::vector<char> std_vector_2 = std::move(std_vector_1);

  EXPECT_EQ(s21_vector_2.size(), std_vector_2.size());
  EXPECT_EQ(s21_vector_1.size(), std_vector_1.size());
  EXPECT_EQ(s21_vector_2.capacity(), std_vector_2.capacity());
  EXPECT_EQ(s21_vector_1.capacity(), std_vector_1.capacity());
  EXPECT_EQ(s21_vector_1.empty(), std_vector_1.empty());
  auto it1 = s21_vector_2.begin();
  auto it2 = std_vector_2.begin();
  while (it1 != s21_vector_2.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1, ++it2;
  }
}

TEST(vector, elementAccsessAt) {
  s21::vector<int> a{0, 1, 2, 3, 4, 5};
  s21::vector<int> b = a;
  EXPECT_EQ(a.at(3), 3);
  EXPECT_EQ(b.at(0), 0);
  EXPECT_EQ(a[4], 4);
  EXPECT_EQ(b[1], 1);
  EXPECT_THROW(a.at(43), std::out_of_range);
  EXPECT_THROW(b.at(37), std::out_of_range);

  EXPECT_NO_THROW(a[2] = 5);
  EXPECT_NO_THROW(a.at(4) = 7);
}

// TEST(vector, ModifierInsert) {
//   s21::vector<int> s21_vector_1 = {'a', 'c', 'd'};
//   s21::vector<int> s21_vector_2 = {'a', 'b', 'c', 'd'};

//   auto it = s21_vector_1.begin();
//   ++it;
//   s21_vector_1.insert(it, 'b');
//   auto it1 = s21_vector_1.begin();
//   auto it2 = s21_vector_2.begin();
//   while (it1 != s21_vector_1.end()) {
//     EXPECT_EQ(*it1, *it2);
//     ++it1, ++it2;
//   }
//   EXPECT_EQ(s21_vector_1.size(), s21_vector_2.size());
//   s21_vector_1.insert(s21_vector_1.end(), '5');
//   EXPECT_EQ(s21_vector_1.back(), '5');
// }

// TEST(vector, ModifierErase) {
//   s21::vector<int> s21_vector_1 = {'a', 'c', 'd'};
//   s21::vector<int> s21_vector_2 = {'a', 'b', 'c', 'd'};

//   auto it = s21_vector_2.begin();
//   ++it;
//   s21_vector_2.erase(it);
//   auto it1 = s21_vector_1.begin();
//   auto it2 = s21_vector_2.begin();
//   while (it1 != s21_vector_1.end()) {
//     EXPECT_EQ(*it1, *it2);
//     ++it1, ++it2;
//   }
//   EXPECT_EQ(s21_vector_1.size(), s21_vector_2.size());
// }

// TEST(vector, ModifierPush) {
//   s21::vector<int> s21_vector = {1, 2, 3, 4};
//   std::vector<int> std_vector = {1, 2, 3, 4};
//   s21_vector.push_back(5);
//   std_vector.push_back(5);
//   EXPECT_EQ(s21_vector.front(), std_vector.front());
//   EXPECT_EQ(s21_vector.back(), std_vector.back());
//   EXPECT_EQ(s21_vector.size(), std_vector.size());
//   EXPECT_EQ(s21_vector.empty(), std_vector.empty());
//   auto it1 = s21_vector.begin();
//   auto it2 = std_vector.begin();
//   while (it1 != s21_vector.end()) {
//     EXPECT_EQ(*it1, *it2);
//     ++it1, ++it2;
//   }
// }

// TEST(vector, ModifierPop) {
//   s21::vector<int> s21_vector = {1, 2, 3, 4};
//   std::vector<int> std_vector = {1, 2, 3, 4};
//   s21_vector.pop_back();
//   std_vector.pop_back();
//   EXPECT_EQ(s21_vector.front(), std_vector.front());
//   EXPECT_EQ(s21_vector.back(), std_vector.back());
//   EXPECT_EQ(s21_vector.size(), std_vector.size());
//   EXPECT_EQ(s21_vector.empty(), std_vector.empty());
//   auto it1 = s21_vector.begin();
//   auto it2 = std_vector.begin();
//   while (it1 != s21_vector.end()) {
//     EXPECT_EQ(*it1, *it2);
//     ++it1, ++it2;
//   }
// }

TEST(vector, capacityMaxSize) {
  s21::vector<int> v;
  // You can't predict the exact max size, but it should be a very large value
  EXPECT_GT(v.max_size(), 0);
}

TEST(vector, capacityReserveIncreaseCapacity) {
  s21::vector<int> v;
  size_t initialCapacity = v.capacity();
  size_t newCapacity = initialCapacity + 10;
  v.reserve(newCapacity);
  EXPECT_GE(v.capacity(), newCapacity);
}

TEST(vector, capacityReserveDecreaseCapacity) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  size_t initialCapacity = v.capacity();
  size_t newCapacity = initialCapacity - 2;
  v.reserve(newCapacity);
  // Capacity may not decrease immediately, but it shouldn't exceed the
  // requested value
  EXPECT_LE(v.capacity(), initialCapacity);
  EXPECT_GE(v.capacity(), newCapacity);
}

TEST(vector, capacityShrinkToFitNonEmptyVector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  size_t initialCapacity = v.capacity();
  v.pop_back();  // Simulate a reduction in size
  v.shrink_to_fit();
  // After shrink_to_fit(), the capacity should not exceed the new size
  EXPECT_LE(v.capacity(), v.size());
  // The capacity may not necessarily decrease, but it should not be larger than
  // the initial capacity
  EXPECT_LE(v.capacity(), initialCapacity);
}

TEST(vector, modifiersSwap) {
  s21::vector<char> s21_vector_1 = {'a', 'b', 'o', 'b', 'a'};
  s21::vector<char> s21_vector_2 = {'s', 'h', 'l', 'e', 'p', 'p', 'a'};
  s21::vector<char> s21_vector_3 = {'a', 'b', 'o', 'b', 'a'};
  s21::vector<char> s21_vector_4 = {'s', 'h', 'l', 'e', 'p', 'p', 'a'};
  s21_vector_1.swap(s21_vector_2);
  auto it1 = s21_vector_1.begin();
  auto it2 = s21_vector_2.begin();
  auto it3 = s21_vector_3.begin();
  auto it4 = s21_vector_4.begin();
  while (it1 != s21_vector_1.end()) {
    EXPECT_EQ(*it1, *it4);
    ++it1, ++it4;
  }
  while (it2 != s21_vector_2.end()) {
    EXPECT_EQ(*it2, *it3);
    ++it2, ++it3;
  }
  EXPECT_EQ(s21_vector_1.size(), s21_vector_4.size());
  EXPECT_EQ(s21_vector_2.size(), s21_vector_3.size());
}

} // namespace