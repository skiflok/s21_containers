#include <gtest/gtest.h>

#include <utility>
#include <vector>
//#include "../src/vector.h"
// using namespace s21;

<<<<<<< HEAD
TEST(TEST, test) {
  //  s21::Vector<int> v{1, 2, 3, 4, 5};
  //  s21::Vector<int> v1(v);
  //  v.push_back(6);
  //  for (int i = 0; i < v.size(); i++) {
  //    std::cout << v.at(i) << " ";
  //  }
  //  std::cout << "\n_____________\n";
  //  for (int i = 0; i < v1.size(); i++) {
  //    std::cout << v1.at(i) << " ";
  //  }
  std::vector<int> v;
//  std::cout << "SIZE_MAX = " << SIZE_MAX/sizeof(int) << std::endl;
  std::cout << "SIZE_MAX = " << SIZE_MAX/sizeof(int) << std::endl;
  std::cout << "size = " <<  v.size() << std::endl;
  std::cout << "capacity = " << v.capacity() << std::endl;

  std::cout << "max_size = " <<v.max_size() << std::endl;

=======
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
>>>>>>> 3225524d6919a0b16a51dfd10183e2b4ce93a4c5
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}