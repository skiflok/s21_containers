#include <gtest/gtest.h>

#include <utility>

//#include "../src/s21_matrix_oop.h"

TEST(TEST, test) {
    std::cout << "test1" << "\n";
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}