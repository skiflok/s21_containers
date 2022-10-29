#include "vector.h"


// Constructors

template <typename T>
void s21::Vector<T>::reserve_more_capacity(size_t size) {
  if (size > m_capacity_) {
    value_type *buff = new value_type[size];
    for (size_t i = 0; i < m_size_; ++i) buff[i] = std::move(arr_[i]);
    delete[] arr_;
    arr_ = buff;
    m_capacity_ = size;
  }
}

// initializer list constructor (allows creating lists with initializer lists,
// see main.cpp)
template <typename T>
s21::Vector<T>::Vector(std::initializer_list<value_type> const &items) {
  arr_ = new value_type[items.size()];
  int i = 0;
  //  std::initializer_list<int>::iterator itr
  for (std::initializer_list<int>::iterator itr = items.begin(); itr != items.end(); itr++) {
    arr_[i] = *itr;
    i++;
  }
  m_size_ = items.size();
  m_capacity_ = items.size();
};

template <typename T>
size_t s21::Vector<T>::size() {
  return m_size_;
}

template <typename T>
T s21::Vector<T>::at(size_type i) {
  return arr_[i];
}

template <typename T>
void s21::Vector<T>::push_back(T v) {
  if (m_size_ == m_capacity_) {
    reserve_more_capacity(m_size_ * 2);
  }
  arr_[m_size_++] = v;
}

// externalizing template instances for correct linking, feel free to find more
// information
template class s21::Vector<int>;
