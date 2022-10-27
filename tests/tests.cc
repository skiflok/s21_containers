#include <gtest/gtest.h>

#include <utility>

#include "../src/vector.h"
using namespace s21;


TEST(TEST, test) {
//  template <typename T>
  Vector<int> a(3);
  a.reserve_more_capacity(3.5);

}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}