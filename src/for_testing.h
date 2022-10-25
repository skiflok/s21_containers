//
// Created by Lok on 23.10.2022.
//

#ifndef SRC_FOR_TESTING_H_
#define SRC_FOR_TESTING_H_

namespace s21 {

class For_testing {
 public:
template<typename T>
T sum(T a, T b) {
  return a + b;
}
void print();

template<typename T>
void printParam(T value) {
  std::cout << value << "\n";
}

};

} // s21

#endif //SRC_FOR_TESTING_H_
