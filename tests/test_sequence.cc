#include <gtest/gtest.h>

//#include <utility>
#include <vector>
//#include "../src/sequence/s21_vector.h"
#include "../src/sequence/sequence_container.h"
using namespace s21;

class Sequence_test : public ::testing::Test {
 protected:
  void SetUp() override {}
  SequenceContainer<int> s;
  std::vector<int> v = {1, 2, 3, 4, 5};
  std::vector<int> v1 = {1, 2, 3, 4, 5, 6};
  std::vector<int> v_null;
};

TEST_F(Sequence_test, operator_plus_plus) {
//  std::cout << *s.begin() <<std::endl;
//  std::cout << *(s.begin()++) <<std::endl;
//  std::cout << *(v.begin()) <<std::endl;
//  std::cout << *(v.begin()++) <<std::endl;
  auto it = (++v.begin());
  it++;
  std::cout << *it << std::endl;
  auto it2 = (++s.begin());
  it2++;
  std::cout << *it2 << std::endl;
//  std::cout << v.size() <<std::endl;
//  std::cout << v.capacity() <<std::endl;
//  std::cout << *(--v.end()) <<std::endl;
}

TEST_F(Sequence_test, operator_minus_minus) {
  std::cout << *(--s.begin()) << std::endl;
}

TEST_F(Sequence_test, operator_minus) {
  std::cout << (v.begin() - v.end()) << std::endl;
  std::cout << *(v.begin() - 2) << std::endl;
}

TEST_F(Sequence_test, operator_compare) {
  std::cout << (v.begin() == v1.begin() ? "Equal " : "Doesn't equal ") << std::endl;
  std::cout << (s.begin() == s.end() ? "Equal " : "Doesn't equal ") << std::endl;

}