#ifndef TESTVECTOR_H
#define TESTVECTOR_H

#include <initializer_list>
#include <iostream>
#include <utility>

/*
HEADER FILE
*/

// Test vector class with some basic example operations and concepts
namespace s21 {
template <class T>
class Vector {
 public:
  // member types
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;
  // Constructors
  Vector() : m_size_(0U), m_capacity_(0U), arr_(nullptr){};
  explicit Vector(size_type n)
      : m_size_(n), m_capacity_(n), arr_(n ? new T[n] : nullptr){};
  Vector(std::initializer_list<value_type> const &items);
  Vector(const Vector &v){};
  Vector(Vector &&v) {}
  ~Vector() { delete[] arr_; }

  size_type size();
  value_type at(size_type i);
  void push_back(value_type v);

 private:
  size_t m_size_;
  size_t m_capacity_;
  T *arr_;
  void reserve_more_capacity(size_type size);
};

}  // namespace s21

#endif
