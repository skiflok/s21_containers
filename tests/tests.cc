#include <gtest/gtest.h>

//#include <utility>
#include <vector>


#include "../src/sequence/s21_vector.h"

using namespace s21;

class S21Vector_test : public ::testing::Test {
 protected:
  void SetUp() override {
  }
  S21Vector<int> vector_;
};


TEST_F(S21Vector_test, FirstTest) {
  vector_.print();
}


int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}