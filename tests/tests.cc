#include <gtest/gtest.h>

#include <utility>

#include "../src/for_testing.h"

TEST(TEST, test) {
  std::cout << "test1" << "\n";
  s21::print();
  s21::printParam(123);
  auto a = s21::sum(2, 4);
  std::cout << a << "\n";

}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}