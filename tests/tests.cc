#include <gtest/gtest.h>

#include <utility>

#include "../src/for_testing.h"

using namespace s21;

class SuiteName : public ::testing::Test {
 protected:
  void SetUp() override {
//    testing_.SetA(5);
  }

  For_testing<int, int> testing_;
  Pair<int, int> pair_;

};

TEST_F(SuiteName, TestName) {
  EXPECT_EQ(testing_.GetA(), 0);
  testing_.SetA(10);
  EXPECT_EQ(testing_.GetA(), 10);
  std::cout << testing_.GetA() << "\n";

  EXPECT_EQ(pair_.GetFirst(), 0);
  EXPECT_EQ(pair_.GetSecond(), 0);
  pair_.SetFirst(2);
  pair_.SetSecond(3);
  EXPECT_EQ(pair_.GetFirst(), 2);
  EXPECT_EQ(pair_.GetSecond(), 3);

  testing_.GetPair().GetFirst();

  std::cout << "testing_.GetPair().GetFirst() = " << testing_.GetPair().GetFirst() << "\n";
}




int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}