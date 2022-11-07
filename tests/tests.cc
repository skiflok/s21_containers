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
//  EXPECT_EQ(s_21_vector_empty, vector_1_);
}

TEST_F(S21Vector_test, _operatorMove) {
  s_21_vector_empty = std::move(vector_1_);
//  EXPECT_EQ(s_21_vector_empty, vector_1_);
}


//TEST_F(S21Vector_test, FirstTest) {
//  test.insert(test.begin() + 2, test2.begin(), test2.begin() + 10);
//  for (int a : test) {
//    std::cout << a << '\t';
//  }
//}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}