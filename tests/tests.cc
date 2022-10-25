#include <gtest/gtest.h>

#include <utility>

#include "../src/for_testing.h"

using namespace s21;

class SuiteName : public ::testing::Test {
 protected:


};


TEST(TEST, test) {
  std::cout << "start test" << "\n";
  For_testing t;
  t.print();
  t.printParam(123);
  auto a = t.sum(2, 4);
  std::cout << a << "\n";
  auto b = t.sum(23.3, (double )234);
  std::cout << b << "\n";
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}