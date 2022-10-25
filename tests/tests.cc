#include <gtest/gtest.h>

#include <utility>

#include "../src/for_testing.h"
using namespace s21;


TEST(TEST, test) {
  std::cout << "test1"
            << "\n";
  std::cout << sum(3, 5) << std::endl;
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}