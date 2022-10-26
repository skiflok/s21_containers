#include <gtest/gtest.h>

#include <utility>

#include "../src/for_testing.h"

using namespace s21;

class SuiteName : public ::testing::Test {
 protected:
  void SetUp() override {
    testing_.SetA(5);
    testing_2_.SetA(144);
  }

  For_testing testing_;
  For_testing testing_1_;
  For_testing testing_2_;
};

TEST_F(SuiteName, TestName) {
  testing_.print();
  testing_2_.SetA(121231);
  std::cout << testing_.GetA() << "\n";
}

TEST_F(SuiteName, TestName1) {
  testing_.print();
  std::cout << testing_2_.GetA() << "\n";
}



//TEST(TEST, test) {
//  std::cout << "start test" << "\n";
//  For_testing t;
//  t.print();
//  t.printParam(123);
//  auto a = t.sum(2, 4);
//  std::cout << a << "\n";
//  auto b = t.sum(23.3, (double )234);
//  std::cout << b << "\n";
//}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}