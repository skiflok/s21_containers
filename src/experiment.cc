#include "experiment.h"

template <typename T>
void abstract<T>::Print() {
  std::cout << "key = " << key_ << std::endl;
  std::cout << "name = " << name_ << std::endl;
  for (auto i = 0; i < size_; ++i) {
    std::cout << in_class_[i] << std::endl;
  }
}
template <typename T>
void abstract<T>::SetKey(int key) { key_ = key; }

template <typename T>
void abstract<T>::SetName(std::string name) { name_ = name; }

template <typename T>
void heir<T>::Print() {
  std::cout << "_____________" << std::endl;
  abstract<T>::Print();
  std::cout << (brain_ ? "has brain" : "hasn't brain") << std::endl;
}
//template <typename T>
//void abstract<T>::InClass::Print() {
//  std::cout << "__________________" << std::endl;
//  std::cout << "I am class encapsulate in __abstract_class__";
//}

int main() {
  abstract<int> test(1, "abstract", 5);
  test.Print();

//  heir test2(2, "heir", false);
//  test2.Print();
//
//  abstract::InClass test3(3, "InClass");
//  test3.Print();
}