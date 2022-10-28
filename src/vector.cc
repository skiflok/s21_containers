#include "vector.h"

/*
IMPLEMENTATION FILE
*/

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

template <typename T>
s21::Vector<T>::Vector(const Vector<value_type> &v) {
  if (this != &v) {
    m_size_ = v.m_size_;
    m_capacity_ = v.m_capacity_;
    arr_ = new value_type[v.m_capacity_]{};
    std::memcpy(arr_, v.arr_, m_size_ * sizeof(value_type));
  }
}

template <typename T>
s21::Vector<T>::Vector(Vector<value_type> &&v)
    : m_size_(v.m_size_), m_capacity_(v.m_capacity_), arr_(v.arr_) {
  if (this != &v) {
    v.m_size_ = 0;
    v.m_capacity_ = 0;
    v.arr_ = nullptr;
  }
}

template <typename T>
s21::Vector<T>::Vector(std::initializer_list<value_type> const &items) {
  arr_ = new value_type[items.size()];
  int i = 0;
  //  std::initializer_list<int>::iterator itr
  for (std::initializer_list<int>::iterator itr = items.begin();
       itr != items.end(); itr++) {
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
