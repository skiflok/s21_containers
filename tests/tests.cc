#include <gtest/gtest.h>

#include <utility>

#include "../src/s21_vector.h"

using namespace s21;

class TestS21Vector : public ::testing::Test {
 protected:
  void SetUp() override {

  }
  S21Vector<int> vector_;

};

TEST_F(TestS21Vector, TestName) {

  std::cout << vector_.GetMCapacity() << '\n';
  std::cout << vector_.GetMSize() << '\n';


}

TEST_F(TestS21Vector, TestName1) {

}



int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}