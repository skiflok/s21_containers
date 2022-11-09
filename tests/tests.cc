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
  std::vector<int> test_empty;
  std::vector<int> test = {1, 2, 3, 4, 5};
  std::vector<int> test2 = {10, 20, 30, 40};
};

TEST_F(S21Vector_test, _operatorCopy) {
  s_21_vector_empty = vector_1_;
  test = test2;
  EXPECT_EQ(test, test2);

  EXPECT_TRUE(s_21_vector_empty == vector_1_);
}

TEST_F(S21Vector_test, _operatorMove) {
  s_21_vector_empty = std::move(vector_1_);
}

TEST_F(S21Vector_test, at) {
  EXPECT_EQ(vector_1_.at(0), test.at(0));
  EXPECT_EQ(vector_1_.at(1), test.at(1));
  EXPECT_ANY_THROW(vector_1_.at(7));
  EXPECT_ANY_THROW(s_21_vector_empty.at(0));
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
  EXPECT_EQ(*(vector_1_.end() - 1), 5);
}

TEST_F(S21Vector_test, empty) {
  EXPECT_TRUE(s_21_vector_empty.empty());
  EXPECT_FALSE(vector_1_.empty());
}

TEST_F(S21Vector_test, size) {
  EXPECT_EQ(s_21_vector_empty.size(), 0);
  EXPECT_EQ(vector_1_.size(), 5);
}

//TEST_F(S21Vector_test, max_size) {
//  // не проходит на маке
//  EXPECT_EQ(test.max_size(), vector_1_.max_size());
////  std::cout << test.max_size() << std::endl;
////  std::cout << vector_1_.max_size() << std::endl;
////  std::cout << std::numeric_limits<int>::max() << std::endl;
////  std::cout << SIZE_MAX / sizeof(int) << std::endl;
//}

TEST_F(S21Vector_test, reserve) {
  EXPECT_ANY_THROW(vector_1_.reserve(vector_1_.max_size() + 1));
  EXPECT_EQ(vector_1_.capacity(), 5);
  vector_1_.reserve(10);
  EXPECT_EQ(vector_1_.capacity(), 10);
}

TEST_F(S21Vector_test, capasity) {
  EXPECT_EQ(vector_1_.capacity(), 5);
}

TEST_F(S21Vector_test, shrink_to_fit) {
  vector_1_.push_back(3);
  EXPECT_EQ(vector_1_.capacity(), 10);
  vector_1_.shrink_to_fit();
  EXPECT_EQ(vector_1_.capacity(), vector_1_.size());
  EXPECT_EQ(vector_1_.size(), 6);

}

TEST_F(S21Vector_test, push_back) {
  s_21_vector_empty.push_back(0);
  vector_1_.push_back(6);
  EXPECT_EQ(vector_1_.at(5), 6);
}

TEST_F(S21Vector_test, clear) {
  EXPECT_EQ(vector_1_.size(), 5);
  vector_1_.clear();
  EXPECT_EQ(vector_1_.size(), 0);
}



//TEST_F(S21Vector_test, userTest) {
//  std::cout << test.size() << std::endl;
//  std::cout << test.capacity() << std::endl;
//  test.clear();
//  std::cout << test.size() << std::endl;
//  std::cout << test.capacity() << std::endl;
//  for (int i = 0; i < 5; ++i) {
//    std::cout << test[i] << std::endl;
//  }
//}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}