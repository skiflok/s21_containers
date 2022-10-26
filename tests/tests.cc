#include <gtest/gtest.h>

#include <utility>

#include "../src/vector.h"
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