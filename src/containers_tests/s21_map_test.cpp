#include <map>

#include "../s21_containers_test.h"

class Point {
 public:
  Point(double x = 0, double y = 0) : x_(x), y_(y) {}
  bool operator<(const Point& other) const {
    return (x_ * x_ + y_ * y_) < (other.x_ * other.x_ + other.y_ * other.y_);
  }
  bool operator>(const Point& other) const {
    return (x_ * x_ + y_ * y_) > (other.x_ * other.x_ + other.y_ * other.y_);
  }
  bool operator==(const Point& other) const {
    return x_ == other.x_ && y_ == other.y_;
  }

 private:
  double x_, y_;
};

TEST(map, constructorDefaultInteger) {
  s21::map<int, int> s21IntIntMap;
  s21::map<int, char> s21IntCharMap;
  s21::map<char, double> s21CharDoubleMap;
  s21::map<double, Point> s21DoubleClassMap;
  s21::map<Point, s21::map<int, int>> s21ClassContainerMap;
  std::map<int, int> stlIntIntMap;
  std::map<int, char> stlIntCharMap;
  std::map<char, double> stlCharDoubleMap;
  std::map<double, Point> stlDoubleClassMap;
  std::map<Point, std::map<int, int>> stlClassContainerMap;
  EXPECT_EQ(s21IntIntMap.empty(), stlIntIntMap.empty());
  EXPECT_EQ(s21IntCharMap.empty(), stlIntCharMap.empty());
  EXPECT_EQ(s21CharDoubleMap.empty(), stlCharDoubleMap.empty());
  EXPECT_EQ(s21DoubleClassMap.empty(), stlDoubleClassMap.empty());
  EXPECT_EQ(s21ClassContainerMap.empty(), stlClassContainerMap.empty());
}