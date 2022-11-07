#include <gtest/gtest.h>

//#include <utility>
#include <vector>

#include "../src/sequence/s21_vector.h"

using namespace s21;

class S21Vector_test : public ::testing::Test {
 protected:
  void SetUp() override {
  }
  S21Vector<int> s_21_vector_empty;
  S21Vector<int> vector_1_ = {1, 2, 3, 4, 5};
  S21Vector<int> vector_2_ = S21Vector<int>(10);
  std::vector<int> test =  {1, 2, 3, 4, 5};
  std::vector<int> test2 = {10, 20, 30, 40};
};

TEST_F(S21Vector_test, _operatorCopy) {
  s_21_vector_empty = vector_1_;
  test = test2;
  EXPECT_EQ(test, test2);

  std::cout << (s_21_vector_empty == vector_1_) << std::endl;
  EXPECT_TRUE(s_21_vector_empty == vector_1_);
}

TEST_F(S21Vector_test, _operatorMove) {
  s_21_vector_empty = std::move(vector_1_);
}

TEST_F(S21Vector_test, at) {

}

TEST_F(S21Vector_test, brackets) {

}

TEST_F(S21Vector_test, front) {
  EXPECT_EQ(vector_1_.front(), 1);
}

TEST_F(S21Vector_test, back) {
  EXPECT_EQ(vector_1_.back(), 5);

}

TEST_F(S21Vector_test, data) {
  EXPECT_EQ(*vector_1_.data(), 1);
}

TEST_F(S21Vector_test, iterator_begin) {
  EXPECT_EQ(*vector_1_.begin(), 1);
}

TEST_F(S21Vector_test, iterator_end) {
  EXPECT_EQ(*vector_1_.end(), 5);
}

TEST_F(S21Vector_test, empty) {
  EXPECT_TRUE(s_21_vector_empty.empty());
  EXPECT_FALSE(vector_1_.empty());
}

TEST_F(S21Vector_test, size) {
  EXPECT_EQ(s_21_vector_empty.size(), 0);
  EXPECT_EQ(vector_1_.size(), 5);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}