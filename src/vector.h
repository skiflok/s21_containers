//
// Created by Lok on 23.10.2022.
//

#ifndef SRC_FOR_TESTING_H_
#define SRC_FOR_TESTING_H_

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

  Vector() : m_size_(0U), m_capacity_(0U), arr_(nullptr) {};

 private:
   size_t m_size_{};
   size_t m_capacity_{};
   T *arr_{};
};


} // s21

#endif //SRC_FOR_TESTING_H_
