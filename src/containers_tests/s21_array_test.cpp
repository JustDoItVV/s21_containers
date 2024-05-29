#include <array>
#include <iostream>

#include "../s21_containers_test.h"

TEST(array, defaultConstructor) {
  s21::array<int, 10> s21Array{};
  std::array<int, 10> stlArray{};
  for (auto s21It = s21Array.begin(), s21End = s21Array.end(),
            stlIt = stlArray.begin();
       s21It < s21End; s21It++, stlIt++) {
    EXPECT_EQ(*s21It, *stlIt);
  }
}