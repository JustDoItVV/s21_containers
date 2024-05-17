#include "../s21_containers_test.h"

class Point {
 public:
  Point(double x = 0, double y = 0) : x_(x), y_(y) {}
  bool operator<(const Point& other) const {
    return (x_ * x_ + y_ * y_) < (other.x_ * other.x_ + other.y_ * other.y_);
  }
  bool operator==(const Point& other) const {
    return x_ == other.x_ && y_ == other.y_;
  }

 private:
  double x_, y_;
};

TEST(multiset, constructorDefault) {
  EXPECT_NO_THROW(s21::multiset<int>());
  EXPECT_NO_THROW(s21::multiset<char>());
  EXPECT_NO_THROW(s21::multiset<double>());
  EXPECT_NO_THROW(s21::multiset<s21::list<int>>());
  EXPECT_NO_THROW(s21::multiset<Point>());
}

TEST(multiset, constructorInitializerList) {
  EXPECT_NO_THROW(s21::multiset<int>({0, 1, 2, 3, 3, 4, 2, 1}));
  EXPECT_NO_THROW(s21::multiset<char>({'1', 'a', '[', '\n'}));
  EXPECT_NO_THROW(s21::multiset<double>({12.34, 56.78, 0, -346.76}));
  EXPECT_NO_THROW(s21::multiset<Point>({Point(1, 2), Point(12, 4), Point()}));
}

TEST(multiset, constructorCopy) {
  s21::multiset<int> multiset_int({0, 1, 2, 3, 3, 2, 1, 2, 3});
  s21::multiset<int> multiset_other_int = multiset_int;
  s21::multiset<int>::iterator it_multiset_int = multiset_int.begin(),
                               it_multiset_other_int =
                                   multiset_other_int.begin();
  for (; it_multiset_int != multiset_int.end() &&
         it_multiset_other_int != multiset_other_int.end();
       ++it_multiset_int, ++it_multiset_other_int) {
    EXPECT_EQ(*it_multiset_int, *it_multiset_other_int);
  }
  EXPECT_EQ(it_multiset_int, multiset_int.end());
  EXPECT_EQ(it_multiset_other_int, multiset_other_int.end());

  s21::multiset<char> multiset_char({'1', 'a', '[', '\t', '1', '2', '3', 'a'});
  s21::multiset<char> multiset_other_char = multiset_char;
  s21::multiset<char>::iterator it_multiset_char = multiset_char.begin(),
                                it_multiset_other_char =
                                    multiset_other_char.begin();
  for (; it_multiset_char != multiset_char.end() &&
         it_multiset_other_char != multiset_other_char.end();
       ++it_multiset_char, ++it_multiset_other_char) {
    EXPECT_EQ(*it_multiset_char, *it_multiset_other_char);
  }
  EXPECT_EQ(it_multiset_char, multiset_char.end());
  EXPECT_EQ(it_multiset_other_char, multiset_other_char.end());

  s21::multiset<double> multiset_double({12.34, 45, 9348.2, 0.0, 23, 0.0});
  s21::multiset<double> multiset_other_double = multiset_double;
  s21::multiset<double>::iterator it_multiset_double = multiset_double.begin(),
                                  it_multiset_other_double =
                                      multiset_other_double.begin();
  for (; it_multiset_double != multiset_double.end() &&
         it_multiset_other_double != multiset_other_double.end();
       ++it_multiset_double, ++it_multiset_other_double) {
    EXPECT_EQ(*it_multiset_double, *it_multiset_other_double);
  }
  EXPECT_EQ(it_multiset_double, multiset_double.end());
  EXPECT_EQ(it_multiset_other_double, multiset_other_double.end());

  s21::multiset<Point> multiset_point(
      {Point(1, 2), Point(12, 4), Point(), Point(), Point(12, 4), Point(12)});
  s21::multiset<Point> multiset_other_point = multiset_point;
  s21::multiset<Point>::iterator it_multiset_point = multiset_point.begin(),
                                 it_multiset_other_point =
                                     multiset_other_point.begin();
  for (; it_multiset_point != multiset_point.end() &&
         it_multiset_other_point != multiset_other_point.end();
       ++it_multiset_point, ++it_multiset_other_point) {
    EXPECT_EQ(*it_multiset_point, *it_multiset_other_point);
  }
  EXPECT_EQ(it_multiset_point, multiset_point.end());
  EXPECT_EQ(it_multiset_other_point, multiset_other_point.end());
}

TEST(multiset, constructorMove) {
  s21::multiset<int> multiset_int({0, 1, 2, 3, 3, 2, 1, 2, 3});
  s21::multiset<int> multiset_int_tmp = multiset_int;
  s21::multiset<int> multiset_other_int = std::move(multiset_int_tmp);
  s21::multiset<int>::iterator it_multiset_int = multiset_int.begin(),
                               it_multiset_other_int =
                                   multiset_other_int.begin();
  for (; it_multiset_other_int != multiset_other_int.end();
       ++it_multiset_int, ++it_multiset_other_int) {
    EXPECT_EQ(*it_multiset_int, *it_multiset_other_int);
  }
  EXPECT_EQ(it_multiset_int, multiset_int.end());
  EXPECT_EQ(it_multiset_other_int, multiset_other_int.end());

  s21::multiset<char> multiset_char({'1', 'a', '[', '\t', '1', '2', '3', 'a'});
  s21::multiset<char> multiset_char_tmp = multiset_char;
  s21::multiset<char> multiset_other_char = std::move(multiset_char_tmp);
  s21::multiset<char>::iterator it_multiset_char = multiset_char.begin(),
                                it_multiset_other_char =
                                    multiset_other_char.begin();
  for (; it_multiset_char != multiset_char.end() &&
         it_multiset_other_char != multiset_other_char.end();
       ++it_multiset_char, ++it_multiset_other_char) {
    EXPECT_EQ(*it_multiset_char, *it_multiset_other_char);
  }
  EXPECT_EQ(it_multiset_char, multiset_char.end());
  EXPECT_EQ(it_multiset_other_char, multiset_other_char.end());

  s21::multiset<double> multiset_double({12.34, 45, 9348.2, 0.0, 23, 0.0});
  s21::multiset<double> multiset_double_tmp = multiset_double;
  s21::multiset<double> multiset_other_double = std::move(multiset_double_tmp);
  s21::multiset<double>::iterator it_multiset_double = multiset_double.begin(),
                                  it_multiset_other_double =
                                      multiset_other_double.begin();
  for (; it_multiset_double != multiset_double.end() &&
         it_multiset_other_double != multiset_other_double.end();
       ++it_multiset_double, ++it_multiset_other_double) {
    EXPECT_EQ(*it_multiset_double, *it_multiset_other_double);
  }
  EXPECT_EQ(it_multiset_double, multiset_double.end());
  EXPECT_EQ(it_multiset_other_double, multiset_other_double.end());

  s21::multiset<Point> multiset_point(
      {Point(1, 2), Point(12, 4), Point(), Point(), Point(12, 4), Point(12)});
  s21::multiset<Point> multiset_point_tmp = multiset_point;
  s21::multiset<Point> multiset_other_point = std::move(multiset_point_tmp);
  s21::multiset<Point>::iterator it_multiset_point = multiset_point.begin(),
                                 it_multiset_other_point =
                                     multiset_other_point.begin();
  for (; it_multiset_point != multiset_point.end() &&
         it_multiset_other_point != multiset_other_point.end();
       ++it_multiset_point, ++it_multiset_other_point) {
    EXPECT_EQ(*it_multiset_point, *it_multiset_other_point);
  }
  EXPECT_EQ(it_multiset_point, multiset_point.end());
  EXPECT_EQ(it_multiset_other_point, multiset_other_point.end());
}

TEST(multiset, capacityEmpty) {
  EXPECT_EQ((s21::multiset<int>()).empty(), true);
  EXPECT_EQ((s21::multiset<char>()).empty(), true);
  EXPECT_EQ((s21::multiset<double>()).empty(), true);
  EXPECT_EQ((s21::multiset<s21::list<int>>()).empty(), true);
  EXPECT_EQ((s21::multiset<Point>()).empty(), true);

  EXPECT_EQ((s21::multiset<int>({0, 1, 2, 3, 3, 2, 4, 5, 2})).empty(), false);
  EXPECT_EQ((s21::multiset<char>({'1', 'a', '[', '\n', '1'})).empty(), false);
  EXPECT_EQ((s21::multiset<double>({12.34, 56.78, 0, -346.76})).empty(), false);
  EXPECT_EQ(
      (s21::multiset<Point>({Point(1, 2), Point(12, 4), Point(), Point()}))
          .empty(),
      false);
}

TEST(multiset, capacitySize) {
  EXPECT_EQ((s21::multiset<int>()).size(), (s21::multiset<int>::size_type)0);
  EXPECT_EQ((s21::multiset<char>()).size(), (s21::multiset<char>::size_type)0);
  EXPECT_EQ((s21::multiset<double>()).size(),
            (s21::multiset<double>::size_type)0);
  EXPECT_EQ((s21::multiset<s21::list<int>>()).size(),
            (s21::multiset<s21::list<int>>::size_type)0);
  EXPECT_EQ((s21::multiset<Point>()).size(),
            (s21::multiset<Point>::size_type)0);

  EXPECT_EQ((s21::multiset<int>({0, 1, 2, 3})).size(),
            (s21::multiset<int>::size_type)4);
  EXPECT_EQ((s21::multiset<char>({'1', 'a', '[', '\n'})).size(),
            (s21::multiset<char>::size_type)4);
  EXPECT_EQ((s21::multiset<double>({12.34, 56.78, 0, -346.76})).size(),
            (s21::multiset<double>::size_type)4);
  EXPECT_EQ((s21::multiset<Point>({Point(1, 2), Point(12, 4), Point()})).size(),
            (s21::multiset<Point>::size_type)3);
}

TEST(multiset, modifiersClear) {
  s21::multiset<int> multiset_int;
  multiset_int.clear();
  EXPECT_EQ(multiset_int.empty(), true);

  s21::multiset<char> multiset_char({'1', 'a', '[', '\t'});
  multiset_char.clear();
  EXPECT_EQ(multiset_char.empty(), true);

  s21::multiset<double> multiset_double({0.0});
  multiset_double.clear();
  EXPECT_EQ(multiset_double.empty(), true);

  s21::multiset<Point> multiset_point({Point(1, 2), Point(), Point(12, 43.09)});
  multiset_point.clear();
  EXPECT_EQ(multiset_point.empty(), true);
}

TEST(multiset, modifiersInsert) {
  for (int i = 0; i < 100; ++i) {
    int q, n = rand() % 20 + 1;
    s21::multiset<int> test;
    std::multiset<int> check;
    for (int j = 0; j < n; ++j) {
      q = rand() % 20;
      test.insert(q);
      check.insert(q);
    }

    s21::multiset<int>::iterator it_test = test.begin();
    std::multiset<int>::iterator it_check = check.begin();

    EXPECT_EQ(test.size(), check.size());

    it_test = test.begin(), it_check = check.begin();
    for (; it_test != test.end() && it_check != check.end();
         ++it_test, ++it_check)
      EXPECT_EQ(*it_test, *it_check);

    EXPECT_EQ(it_test, test.end());
    EXPECT_EQ(it_check, check.end());
  }
}

TEST(multiset, modifiersErase) {
  for (int i = 0; i < 100; ++i) {
    int n = rand() % 20 + 1, q;
    s21::multiset<int> test;
    std::multiset<int> check;
    for (int j = 0; j < n; ++j) {
      q = rand() % 20 + 1;
      test.insert(q);
      check.insert(q);
    }

    // test.print_tree();

    s21::multiset<int>::iterator it_test;
    std::multiset<int>::iterator it_check;

    n = rand() % 20 + 1;
    for (int j = 0; j < n; ++j) {
      q = rand() % 20 + 1;
      EXPECT_EQ(test.contains(q), check.find(q) != check.end());
      it_test = test.begin(), it_check = check.begin();
      // for (; it_test != test.end() && it_check != check.end();
      //    ++it_test, ++it_check)
      // std::cout << "|" <<  *it_test << " " << *it_check << std::endl;
      // EXPECT_EQ(*it_test, *it_check);

      if (test.contains(q)) {
        it_test = test.find(q);
        test.erase(it_test);
      }
      if (check.find(q) != check.end()) {
        it_check = check.find(q);
        check.erase(it_check);
      }
    }
    // test.print_tree();

    EXPECT_EQ(test.size(), check.size());

    it_test = test.begin(), it_check = check.begin();
    for (; it_test != test.end() && it_check != check.end();
         ++it_test, ++it_check)
      EXPECT_EQ(*it_test, *it_check);

    EXPECT_EQ(it_test, test.end());
    EXPECT_EQ(it_check, check.end());
    // std::cout << "||||||||||||||||||||||||||||||||||||||||\n";
  }
}

TEST(multiset, modifiersSwap) {
  s21::multiset<int> multiset_int({0, 1, 2, 3});
  s21::multiset<int> multiset_copy_int = multiset_int;
  s21::multiset<int> multiset_other_int({0, 4, 45, 23, 54});
  s21::multiset<int> multiset_other_copy_int = multiset_other_int;

  multiset_int.swap(multiset_other_int);

  s21::multiset<int>::iterator it_multiset_int = multiset_int.begin(),
                               it_multiset_other_int =
                                   multiset_other_copy_int.begin();
  for (; it_multiset_int != multiset_int.end() &&
         it_multiset_other_int != multiset_other_copy_int.end();
       ++it_multiset_int, ++it_multiset_other_int) {
    EXPECT_EQ(*it_multiset_int, *it_multiset_other_int);
  }
  it_multiset_int = multiset_other_int.begin(),
  it_multiset_other_int = multiset_copy_int.begin();
  for (; it_multiset_int != multiset_other_int.end() &&
         it_multiset_other_int != multiset_copy_int.end();
       ++it_multiset_int, ++it_multiset_other_int) {
    EXPECT_EQ(*it_multiset_int, *it_multiset_other_int);
  }

  s21::multiset<char> multiset_char({'s', 'd', 'r', '\0'});
  s21::multiset<char> multiset_copy_char = multiset_char;
  s21::multiset<char> multiset_other_char({'3', '4'});
  s21::multiset<char> multiset_other_copy_char = multiset_other_char;

  multiset_char.swap(multiset_other_char);

  s21::multiset<char>::iterator it_multiset_char = multiset_char.begin(),
                                it_multiset_other_char =
                                    multiset_other_copy_char.begin();
  for (; it_multiset_char != multiset_char.end() &&
         it_multiset_other_char != multiset_other_copy_char.end();
       ++it_multiset_char, ++it_multiset_other_char) {
    EXPECT_EQ(*it_multiset_char, *it_multiset_other_char);
  }
  it_multiset_char = multiset_other_char.begin(),
  it_multiset_other_char = multiset_copy_char.begin();
  for (; it_multiset_char != multiset_other_char.end() &&
         it_multiset_other_char != multiset_copy_char.end();
       ++it_multiset_char, ++it_multiset_other_char) {
    EXPECT_EQ(*it_multiset_char, *it_multiset_other_char);
  }

  s21::multiset<double> multiset_double(
      {0.23, 123.2305, 239868.343, 2383.3434});
  s21::multiset<double> multiset_copy_double = multiset_double;
  s21::multiset<double> multiset_other_double({934.56, 34, 45.2});
  s21::multiset<double> multiset_other_copy_double = multiset_other_double;

  multiset_double.swap(multiset_other_double);

  s21::multiset<double>::iterator it_multiset_double = multiset_double.begin(),
                                  it_multiset_other_double =
                                      multiset_other_copy_double.begin();
  for (; it_multiset_double != multiset_double.end() &&
         it_multiset_other_double != multiset_other_copy_double.end();
       ++it_multiset_double, ++it_multiset_other_double) {
    EXPECT_EQ(*it_multiset_double, *it_multiset_other_double);
  }
  it_multiset_double = multiset_other_double.begin(),
  it_multiset_other_double = multiset_copy_double.begin();
  for (; it_multiset_double != multiset_other_double.end() &&
         it_multiset_other_double != multiset_copy_double.end();
       ++it_multiset_double, ++it_multiset_other_double) {
    EXPECT_EQ(*it_multiset_double, *it_multiset_other_double);
  }

  s21::multiset<Point> multiset_point({Point(1, 2), Point(12, 4), Point()});
  s21::multiset<Point> multiset_copy_point = multiset_point;
  s21::multiset<Point> multiset_other_point({Point(34, 65)});
  s21::multiset<Point> multiset_other_copy_point = multiset_other_point;

  multiset_point.swap(multiset_other_point);

  s21::multiset<Point>::iterator it_multiset_point = multiset_point.begin(),
                                 it_multiset_other_point =
                                     multiset_other_copy_point.begin();
  for (; it_multiset_point != multiset_point.end() &&
         it_multiset_other_point != multiset_other_copy_point.end();
       ++it_multiset_point, ++it_multiset_other_point) {
    EXPECT_EQ(*it_multiset_point, *it_multiset_other_point);
  }
  it_multiset_point = multiset_other_point.begin(),
  it_multiset_other_point = multiset_copy_point.begin();
  for (; it_multiset_point != multiset_other_point.end() &&
         it_multiset_other_point != multiset_copy_point.end();
       ++it_multiset_point, ++it_multiset_other_point) {
    EXPECT_EQ(*it_multiset_point, *it_multiset_other_point);
  }
}

TEST(multiset, modifiersMerge) {
  for (int i = 0; i < 100; ++i) {
    int n, q;
    s21::multiset<int> test1, test2;
    std::multiset<int> check1, check2;

    n = rand() % 20 + 1;
    for (int j = 0; j < n; ++j) {
      q = rand() % 20 + 1;
      test1.insert(q);
      check1.insert(q);
    }

    n = rand() % 20 + 1;
    for (int j = 0; j < n; ++j) {
      q = rand() % 20 + 1;
      test2.insert(q);
      check2.insert(q);
    }

    test1.merge(test2);
    // check1.merge(check2);

    s21::multiset<int>::iterator it_test;
    std::multiset<int>::iterator it_check;

    it_test = test1.begin(), it_check = check1.begin();
    for (; it_test != test1.end() && it_check != check1.end();
         ++it_test, ++it_check)
      EXPECT_EQ(*it_test, *it_check);
    EXPECT_EQ(it_test, test1.end());
    EXPECT_EQ(it_check, check1.end());

    it_test = test2.begin(), it_check = check2.begin();
    for (; it_test != test2.end() && it_check != check2.end();
         ++it_test, ++it_check)
      EXPECT_EQ(*it_test, *it_check);
    EXPECT_EQ(it_test, test2.end());
    EXPECT_EQ(it_check, check2.end());
  }
}

TEST(multiset, lookupCountFindContains) {
  for (int i = 0; i < 100; ++i) {
    int q, n = rand() % 20 + 1;
    s21::multiset<int> test;
    std::multiset<int> check;
    for (int j = 0; j < n; ++j) {
      q = rand() % 20;
      test.insert(q);
      check.insert(q);
    }

    s21::multiset<int>::iterator it_test = test.begin();
    std::multiset<int>::iterator it_check = check.begin();

    EXPECT_EQ(test.size(), check.size());
    it_test = test.begin(), it_check = check.begin();
    for (; it_test != test.end() && it_check != check.end();
         ++it_test, ++it_check)
      EXPECT_EQ(*it_test, *it_check);

    EXPECT_EQ(it_test, test.end());
    EXPECT_EQ(it_check, check.end());

    n = rand() % 20 + 1;
    for (int j = 0; j < n; ++j) {
      q = rand() % 20;
      EXPECT_EQ(test.count(q), check.count(q));
      it_test = test.find(q);
      it_check = check.find(q);
      if (it_test == test.end()) {
        EXPECT_EQ(it_check, check.end());
      } else {
        EXPECT_EQ(*it_test, *it_check);
      }
      EXPECT_EQ(test.contains(q), check.find(q) != check.end());
    }
  }
}

TEST(multiset, lookupBounds) {
  for (int i = 0; i < 1000; ++i) {
    s21::multiset<int> test;
    std::multiset<int> check;
    int q;

    for (int j = 0; j < rand() % 20; ++j) {
      q = rand() % 20 + 1;
      test.insert(q);
      check.insert(q);
    }

    q = rand() % 20;
    s21::multiset<int>::iterator it_test;
    std::multiset<int>::iterator it_check;

    it_test = test.lower_bound(q);
    it_check = check.lower_bound(q);
    EXPECT_EQ(it_test != test.end(), it_check != check.end());
    if (it_test != test.end() && it_check != check.end()) {
      EXPECT_EQ(*it_test, *it_check);
    }

    it_test = test.upper_bound(q);
    it_check = check.upper_bound(q);
    EXPECT_EQ(it_test != test.end(), it_check != check.end());
    if (it_test != test.end() && it_check != check.end()) {
      EXPECT_EQ(*it_test, *it_check);
    }

    std::pair<s21::multiset<int>::iterator, s21::multiset<int>::iterator>
        it_pair_test;
    std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator>
        it_pair_check;
    it_pair_test = test.equal_range(q);
    it_pair_check = check.equal_range(q);
    EXPECT_EQ(it_pair_test.first != test.end(),
              it_pair_check.first != check.end());
    if (it_pair_test.first != test.end() &&
        it_pair_check.first != check.end()) {
      EXPECT_EQ(*it_pair_test.first, *it_pair_check.first);
    }
    EXPECT_EQ(it_pair_test.second != test.end(),
              it_pair_check.second != check.end());
    if (it_pair_test.second != test.end() &&
        it_pair_check.second != check.end()) {
      EXPECT_EQ(*it_pair_test.second, *it_pair_check.second);
    }
  }
}