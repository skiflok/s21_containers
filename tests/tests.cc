#include <gtest/gtest.h>

#include <utility>

#include "../src/vector.h"
// using namespace s21;

TEST(TEST, test) {
  s21::Vector<int> v{1, 2, 3, 4, 5};
  s21::Vector<int> v2 = std::move(v);
  //  v.push_back(6); // надо добавить проверку и выделить память а то сега
  for (int i = 0; i < v.size(); i++) {
    std::cout << v.at(i) << " ";
  }
  std::cout << "\n____________________\n";
  for (int i = 0; i < v2.size(); i++) {
    std::cout << v2.at(i) << " ";
  }
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}