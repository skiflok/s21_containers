//
// Created by Lok on 23.10.2022.
//

#ifndef SRC_FOR_TESTING_H_
#define SRC_FOR_TESTING_H_
#include <cstddef>

namespace s21 {
template <typename T>
class Vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  Vector() : m_size_(0U), m_capacity_(0U), arr_(nullptr){};
  explicit Vector(size_type n)
      : m_size_(n), m_capacity_(n), arr_(n ? new T[n] : nullptr) {}
  //  Vector(std::initializer_list<value_type> const &items);
  Vector(const Vector &v)
      : m_size_(v.m_size_), m_capacity_(v.m_capacity_), arr_(v.arr_){};
  Vector(Vector &&v)
      : m_size_(v.m_size_), m_capacity_(v.m_capacity_), arr_(v.arr_) {
    v.arr_ = nullptr;
    v.m_size_ = 0;
  };
  ~Vector() { delete[] arr_; }
  void reserve_more_capacity(size_type size_);

 private:
  size_t m_size_{};
  size_t m_capacity_{};
  T *arr_{};
  //   void reserve_more_capacity(size_type size);
};

}  // namespace s21

#endif  // SRC_FOR_TESTING_H_
