//
// Created by Lok on 23.10.2022.
//

#include <iostream>
#include "for_testing.h"

namespace s21 {

template<typename T>
T sum(T a, T b) {
  return a + b;
}

void print() {
  std::cout << "value" << std::endl;
}

void printParam(int value) {
  std::cout << value << std::endl;
}

} // s21

//int main() {
//  int a = s21::sum(2, 4);
//  std::cout << a << "\n";
//}

