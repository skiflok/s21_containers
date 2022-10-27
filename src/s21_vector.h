//
// Created by Lok on 27.10.2022.
//
#include <iostream>

#ifndef S21_CONTAINERS_SRC_S21_VECTOR_H_
#define S21_CONTAINERS_SRC_S21_VECTOR_H_

namespace s21 {

template<class T>
class S21Vector {
 public:
  size_t GetMSize() const {
    return m_size_;
  }
  size_t GetMCapacity() const {
    return m_capacity_;
  }
  
  // default constructor (simplified syntax for assigning values to attributes)
  S21Vector() : m_size_(0U), m_capacity_(0U), arr_(nullptr) {}
  // parametrized constructor for fixed size S21Vector (explicit was used in order to
  // avoid automatic type conversion)
  explicit S21Vector(size_t n) : m_size_(n), m_capacity_(n), arr_(n ? new T[n] : nullptr) {}
  // initializer list constructor (allows creating lists with initializer lists, see main.cpp)
//  S21Vector(std::initializer_list<value_type> const &items);
  // copy constructor with simplified syntax
  S21Vector(const S21Vector &v) : m_size_(v.m_size_), m_capacity_(v.m_capacity_), arr_(v.arr_) {};
  // move constructor with simplified syntax
  S21Vector(S21Vector &&v) : m_size_(v.m_size_), m_capacity_(v.m_capacity_), arr_(v.arr_)
  {
    v.arr_ = nullptr;
    v.m_size_ = 0;
  }

  // destructor
  ~S21Vector() { delete[] arr_; }

 private:
  size_t m_size_;
  size_t m_capacity_;
  T *arr_;

};

} // s21

#endif //S21_CONTAINERS_SRC_S21_VECTOR_H_
