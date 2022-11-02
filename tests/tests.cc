#include <gtest/gtest.h>

//#include <utility>
#include <vector>

#include "../src/for_testing.h"
#include "../src/s21_vector.h"

using namespace s21;

class SuiteName : public ::testing::Test {
 protected:
  void SetUp() override {
  }
  For_testing<int, int> testing_;
  Pair<int, int> pair_;
};

class S21Vector_test : public ::testing::Test {
 protected:
  void SetUp() override {
  }
  S21Vector<int> vector_;
};

TEST_F(SuiteName, TestPair) {
  EXPECT_EQ(pair_.GetFirst(), 0);
  EXPECT_EQ(pair_.GetSecond(), 0);
  pair_.SetFirst(2);
  pair_.SetSecond(3);
  EXPECT_EQ(pair_.GetFirst(), 2);
  EXPECT_EQ(pair_.GetSecond(), 3);

  EXPECT_EQ(testing_.GetPair().GetFirst(), 0);
  std::cout << "1st = " << testing_.GetPair().GetFirst() << "\n";
  testing_.GetPair().SetFirst(123);
  EXPECT_EQ(testing_.GetPair().GetFirst(), 123);
  std::cout << "1st = " << testing_.GetPair().GetFirst() << "\n";

}

TEST_F(SuiteName, TestData) {
  EXPECT_EQ(testing_.GetSize(), 0);
  EXPECT_EQ(testing_.GetCapacity(), 100);
  testing_.SetSize(5);
  testing_.SetCapacity(150);
  EXPECT_EQ(testing_.GetSize(), 5);
  EXPECT_EQ(testing_.GetCapacity(), 150);
}

TEST_F(S21Vector_test, FirstTest) {
  vector_.print();
}


int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}