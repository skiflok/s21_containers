//
// Created by Lok on 01.11.2022.
//

#ifndef S21_CONTAINERS_SRC_S21_VECTOR_H_
#define S21_CONTAINERS_SRC_S21_VECTOR_H_



#include <utility>
#include <cstddef>
#include <initializer_list>

namespace s21 {

template<class T>
class S21Vector {

 public:
  // member types
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

 private:
  size_type size_;
  size_type capacity_;
  T* arr;

 public:

  // default constructor (simplified syntax for assigning values to attributes)
  S21Vector() : size_(0U), capacity_(0U), arr(nullptr) {}
  // parametrized constructor for fixed size vector (explicit was used in order to
  // avoid automatic type conversion)
  explicit S21Vector(size_type n) : size_(n), capacity_(n), arr(n ? new T[n] : nullptr) {}
  // initializer list constructor (allows creating lists with initializer lists, see main.cpp)
  S21Vector(std::initializer_list<value_type> const &items);
  // copy constructor with simplified syntax
  S21Vector(const S21Vector &v) : size_(v.size_), capacity_(v.capacity_), arr(v.arr) {};
  // move constructor with simplified syntax
  S21Vector(S21Vector &&v) : size_(v.size_), capacity_(v.capacity_), arr(v.arr)
  {
    v.arr = nullptr;
    v.size_ = 0;
  }

  // destructor
  ~S21Vector() { delete[] arr; }

  void print(){
    std::cout << "vector" << std::endl;
  }

};

template<class T>
S21Vector<T>::S21Vector(const std::initializer_list<value_type> &items) {

}

} // s21

#endif //S21_CONTAINERS_SRC_S21_VECTOR_H_
