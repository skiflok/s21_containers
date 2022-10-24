#include <gtest/gtest.h>

#include <utility>

#include "../src/for_testing.h"

using namespace s21;

TEST(TEST, test) {
  std::cout << "test1" << "\n";
  print();
  printParam(123);
  auto a = sum(2, 4);
  std::cout << a << "\n";
  auto b = sum(23.3, (double )234);
  std::cout << b << "\n";
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}