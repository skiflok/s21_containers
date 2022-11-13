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
  std::vector<int> v = {1,2,3,4,5};
  std::vector<int> v_null;
};

TEST_F(Sequence_test, test) {
  std::cout << *s.begin() <<std::endl;
  std::cout << *v.begin() <<std::endl;
  std::cout << *(s.begin()++) <<std::endl;
  std::cout << *(v.begin()++) <<std::endl;
  std::cout << *(v_null.begin()) <<std::endl;
}
