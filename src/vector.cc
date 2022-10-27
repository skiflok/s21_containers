//
// Created by Lok on 23.10.2022.
//

#include "vector.h"

#include <iostream>
//#include <vector>

template <typename T>
void s21::Vector<T>::reserve_more_capacity(size_type size_) {
  std::cout << "in" << std::endl;

}

//template <typename T>
//void s21::Vector<T>::reserve_more_capacity(size_t size) {
//  if (size > m_capacity_) {
//    value_type *buff = new value_type[size];
//    for (size_t i = 0; i < m_size_; ++i) buff[i] = std::move(arr_[i]);
//    delete[] arr_;
//    arr_ = buff;
//    m_capacity_ = size;
//  }
//}


//template <typename T>
//T mtr(T x, T y , size_t size) {
//  vector<vector<T> > a(x, vector<T>(y, size));
//  for (auto i = 0; i < x; ++i) {
//    for (auto j = 0; j < y; ++j) {
//      cout << a[i][j] << " ";
//    }
//    cout << endl;
//  }
//
//  return x + y;
//}




//int main() {
//  int x = 8;
//  int y = 10;
//  mtr(x, y, 4);
//  //  cout << "size = " << vtr.size() << endl;
//  //  std::vector<int> vtr = {1, 3, 4, 5, 5};
//  //  for (auto i = 0; i < vtr.size(); ++i) {
//  //    cout << vtr.at(i) << endl;
//  //  }
//  //
//  //  std::vector<int>::iterator it;
//  //  it = vtr.begin();
//  //
//  //  std::cout << "_______________________" << std::endl;
//  ////  for (auto i = 0; i < vtr.size(); ++i) {
//  ////    std::cout << vtr.at(i) << std::endl;
//  ////  }
//  ////  std::cout << "int a  = " << a << std::endl;
//  //
//  //  std::cout << "data =    " << vtr.data() << std::endl;
//  //  std::cout << "pointer = " << &vtr[0] << std::endl;
//  //  std::cout << "iterator = " << it.  << std::endl;
//  //  std::cout << "capacity = " << vtr.capacity() << std::endl;
//  //  std::cout << "size = " << vtr. << std::endl;
//  //  std::cout << "size = " << vtr.size() << std::endl;
//  //  std::cout << "size = " << vtr.size() << std::endl;
//  //  std::cout << "size = " << vtr.size() << std::endl;
//
//  return 0;
//}