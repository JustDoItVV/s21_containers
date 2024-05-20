
#include <stack>

#include "../s21_containers_test.h"

namespace {
TEST(Stack, Constructor_Default) {
  s21::Stack<int> s21_stack;
  std::stack<int> std_stack;
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(Stack, Constructor_initialize_list) {
  s21::Stack<char> s21_stack_1 = {1, 2, 3, 4};
  for (int i = 4; i > 0; i--) {
    EXPECT_EQ(s21_stack_1.top(), i);
    s21_stack_1.pop();
  }
}

TEST(Stack, Constructor_Copy) {
  s21::Stack<char> s21_stack_1 = {'a', 'b', 'c', 'd'};
  s21::Stack<char> s21_stack_2 = s21_stack_1;
  EXPECT_EQ(s21_stack_1.size(), s21_stack_2.size());
  EXPECT_EQ(s21_stack_1.size(), 4);
  EXPECT_EQ(s21_stack_1.top(), 'd');
  s21_stack_1.pop();
  EXPECT_EQ(s21_stack_1.top(), 'c');
  s21_stack_1.pop();
  EXPECT_EQ(s21_stack_1.top(), 'b');
  s21_stack_1.pop();
  EXPECT_EQ(s21_stack_1.top(), 'a');
}

TEST(Stack, MoveConstructor) {
  s21::Stack<int> s1 = {1, 2, 3, 4};
  s21::Stack<int> s2(std::move(s1));
  EXPECT_TRUE(s1.empty());
  EXPECT_EQ(s2.size(), 4);
  EXPECT_EQ(s2.top(), 4);
  s2.pop();
  EXPECT_EQ(s2.top(), 3);
}

TEST(Stack, MoveAssignment) {
  s21::Stack<int> s1 = {1, 2, 3, 4};
  s21::Stack<int> s2 = {5, 6};
  s2 = std::move(s1);
  EXPECT_TRUE(s1.empty());
  EXPECT_EQ(s2.size(), 4);
  EXPECT_EQ(s2.top(), 4);
  s2.pop();
  EXPECT_EQ(s2.top(), 3);
}
TEST(Stack, Modifier_Push) {
  s21::Stack<int> s21_stack;
  std::stack<int> std_stack;
  s21_stack.push(5);
  s21_stack.push(0);
  std_stack.push(5);
  std_stack.push(0);
  EXPECT_EQ(s21_stack.top(), std_stack.top());
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(Stack, Modifier_Pop) {
  s21::Stack<int> s21_stack;
  std::stack<int> std_stack;
  s21_stack.push(5);
  s21_stack.push(0);
  std_stack.push(5);
  std_stack.push(0);
  s21_stack.pop();
  s21_stack.pop();
  std_stack.pop();
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

TEST(Stack, Modifier_Swap) {
  s21::Stack<std::string> s21_stack_1 = {"The", "sun", "Is", "Far", "Away"};
  s21::Stack<std::string> s21_stack_2 = {"It", "Goes", "In", "Circles"};
  s21::Stack<std::string> s21_stack_3 = {"The", "sun", "Is", "Far", "Away"};
  s21::Stack<std::string> s21_stack_4 = {"It", "Goes", "In", "Circles"};

  s21_stack_1.swap(s21_stack_2);

  EXPECT_EQ(s21_stack_1.size(), s21_stack_4.size());
  EXPECT_EQ(s21_stack_2.size(), s21_stack_3.size());
  for (auto i = 0; i < 4; i++) {
    EXPECT_EQ(s21_stack_3.top(), s21_stack_2.top());
    EXPECT_EQ(s21_stack_3.size(), s21_stack_2.size());
    s21_stack_3.pop(), s21_stack_2.pop();
  }
  for (auto i = 0; i < 3; i++) {
    EXPECT_EQ(s21_stack_1.top(), s21_stack_4.top());
    EXPECT_EQ(s21_stack_1.size(), s21_stack_4.size());
    s21_stack_1.pop(), s21_stack_4.pop();
  }
}
}  // namespace
