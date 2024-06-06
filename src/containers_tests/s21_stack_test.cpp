#include "s21_stack.h"

#include <gtest/gtest.h>

#include <stack>

namespace {
TEST(Stack, сonstructorDefault) {
  s21::Stack<int> s21_stack;
  std::stack<int> std_stack;

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(Stack, сonstructorInitializeList) {
  s21::Stack<char> s21_stack_1 = {1, 2, 3, 4};
  for (int i = 4; i > 0; i--) {
    EXPECT_EQ(s21_stack_1.top(), i);
    s21_stack_1.pop();
  }
}

TEST(Stack, constructorCopy) {
  s21::Stack<char> s21_stack_1 = {'a', 'b', 'c', 'd'};
  s21::Stack<char> s21_stack_2 = s21_stack_1;

  EXPECT_EQ(s21_stack_1.size(), s21_stack_2.size());
  EXPECT_EQ(s21_stack_1.size(), 4);
  EXPECT_EQ(s21_stack_1.top(), s21_stack_2.top());
}

TEST(Stack, sizeAndTopAfterCopy) {
  s21::Stack<char> s21_stack_1 = {'a', 'b', 'c', 'd'};
  s21::Stack<char> s21_stack_2 = s21_stack_1;

  EXPECT_EQ(s21_stack_1.size(), 4);
  EXPECT_EQ(s21_stack_1.top(), 'd');
}

TEST(Stack, popOperations) {
  s21::Stack<char> s21_stack_1 = {'a', 'b', 'c', 'd'};

  s21_stack_1.pop();
  EXPECT_EQ(s21_stack_1.top(), 'c');
  s21_stack_1.pop();
  EXPECT_EQ(s21_stack_1.top(), 'b');
  s21_stack_1.pop();
  EXPECT_EQ(s21_stack_1.top(), 'a');
}

TEST(Stack, moveConstructor) {
  s21::Stack<int> s1 = {1, 2, 3, 4};
  s21::Stack<int> s2(std::move(s1));

  EXPECT_TRUE(s1.empty());
  EXPECT_EQ(s2.size(), 4);
  EXPECT_EQ(s2.top(), 4);
  s2.pop();
  EXPECT_EQ(s2.top(), 3);
}

TEST(Stack, moveAssignment) {
  s21::Stack<int> s1 = {1, 2, 3, 4};
  s21::Stack<int> s2 = {5, 6};
  s2 = std::move(s1);

  EXPECT_TRUE(s1.empty());
  EXPECT_EQ(s2.size(), 4);
  EXPECT_EQ(s2.top(), 4);
  s2.pop();
  EXPECT_EQ(s2.top(), 3);
}

TEST(Stack, pushTop) {
  s21::Stack<int> s21_stack;
  std::stack<int> std_stack;
  s21_stack.push(5);
  s21_stack.push(0);
  std_stack.push(5);
  std_stack.push(0);

  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(Stack, pushSize) {
  s21::Stack<int> s21_stack;
  std::stack<int> std_stack;
  s21_stack.push(5);
  s21_stack.push(0);
  std_stack.push(5);
  std_stack.push(0);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(Stack, pushEmptyState) {
  s21::Stack<int> s21_stack;
  std::stack<int> std_stack;
  s21_stack.push(5);
  s21_stack.push(0);
  std_stack.push(5);
  std_stack.push(0);

  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(Stack, popAfterInitialPush) {
  s21::Stack<int> s21_stack;
  std::stack<int> std_stack;
  s21_stack.push(5);
  s21_stack.push(0);
  std_stack.push(5);
  std_stack.push(0);

  s21_stack.pop();
  std_stack.pop();

  EXPECT_EQ(s21_stack.top(), std_stack.top());
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(Stack, popAfterPushAndPop) {
  s21::Stack<int> s21_stack;
  std::stack<int> std_stack;
  s21_stack.push(5);
  s21_stack.push(0);
  std_stack.push(5);
  std_stack.push(0);
  s21_stack.pop();
  std_stack.pop();
  s21_stack.pop();
  std_stack.pop();

  EXPECT_TRUE(s21_stack.empty());
  EXPECT_TRUE(std_stack.empty());
}

TEST(Stack, popAfterRepush) {
  s21::Stack<int> s21_stack;
  std::stack<int> std_stack;
  s21_stack.push(5);
  s21_stack.push(0);
  std_stack.push(5);
  std_stack.push(0);
  s21_stack.pop();
  std_stack.pop();
  s21_stack.pop();
  std_stack.pop();
  s21_stack.push(15);
  s21_stack.push(10);
  std_stack.push(15);
  std_stack.push(10);
  s21_stack.pop();
  std_stack.pop();

  EXPECT_EQ(s21_stack.top(), std_stack.top());
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(Stack, initialState) {
  s21::Stack<std::string> s21_stack_1 = {"The", "sun", "Is", "Far", "Away"};
  s21::Stack<std::string> s21_stack_2 = {"It", "Goes", "In", "Circles"};
  s21::Stack<std::string> s21_stack_3 = {"The", "sun", "Is", "Far", "Away"};
  s21::Stack<std::string> s21_stack_4 = {"It", "Goes", "In", "Circles"};

  EXPECT_EQ(s21_stack_1.size(), s21_stack_3.size());
  EXPECT_EQ(s21_stack_2.size(), s21_stack_4.size());
}

TEST(Stack, swapOperation) {
  s21::Stack<std::string> s21_stack_1 = {"The", "sun", "Is", "Far", "Away"};
  s21::Stack<std::string> s21_stack_2 = {"It", "Goes", "In", "Circles"};
  s21::Stack<std::string> s21_stack_3 = {"The", "sun", "Is", "Far", "Away"};
  s21::Stack<std::string> s21_stack_4 = {"It", "Goes", "In", "Circles"};

  s21_stack_1.swap(s21_stack_2);

  EXPECT_EQ(s21_stack_1.size(), s21_stack_4.size());
  EXPECT_EQ(s21_stack_2.size(), s21_stack_3.size());
}
TEST(Stack, swapAndPopOperationStack1) {
  s21::Stack<std::string> s21_stack_1 = {"The", "sun", "Is", "Far", "Away"};
  s21::Stack<std::string> s21_stack_2 = {"It", "Goes", "In", "Circles"};
  s21::Stack<std::string> s21_stack_4 = {"It", "Goes", "In", "Circles"};

  s21_stack_1.swap(s21_stack_2);

  for (int i = 0; i < 4; i++) {
    EXPECT_EQ(s21_stack_1.top(), s21_stack_4.top());
    s21_stack_1.pop();
    s21_stack_4.pop();
  }
}

TEST(Stack, swapAndPopOperationStack2) {
  s21::Stack<std::string> s21_stack_1 = {"The", "sun", "Is", "Far", "Away"};
  s21::Stack<std::string> s21_stack_2 = {"It", "Goes", "In", "Circles"};
  s21::Stack<std::string> s21_stack_3 = {"The", "sun", "Is", "Far", "Away"};

  s21_stack_1.swap(s21_stack_2);

  for (int i = 0; i < 4; i++) {
    EXPECT_EQ(s21_stack_2.top(), s21_stack_3.top());
    s21_stack_2.pop();
    s21_stack_3.pop();
  }
}
}  // namespace
