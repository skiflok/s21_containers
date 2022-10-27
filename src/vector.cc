#include "vector.h"

/*
IMPLEMENTATION FILE
*/

template <typename T>
void s21::Vector<T>::reserve_more_capacity(size_t size) {
  if (size > m_capacity) {
    value_type *buff = new value_type[size];
    for (size_t i = 0; i < m_size; ++i) buff[i] = std::move(arr[i]);
    delete[] arr;
    arr = buff;
    m_capacity = size;
  }
}

// initializer list constructor (allows creating lists with initializer lists,
// see main.cpp)
template <typename T>
s21::Vector<T>::Vector(std::initializer_list<value_type> const &items) {
  arr = new value_type[items.size()];
  int i = 0;
  //  std::initializer_list<int>::iterator itr
  for (std::initializer_list<int>::iterator itr = items.begin(); itr != items.end(); itr++) {
    arr[i] = *itr;
    i++;
  }
  m_size = items.size();
  m_capacity = items.size();
};

template <typename T>
size_t s21::Vector<T>::size() {
  return m_size;
}

template <typename T>
T s21::Vector<T>::at(size_type i) {
  return arr[i];
}

template <typename T>
void s21::Vector<T>::push_back(T v) {
  if (m_size == m_capacity) {
    reserve_more_capacity(m_size * 2);
  }
  arr[m_size++] = v;
}

// externalizing template instances for correct linking, feel free to find more
// information
template class s21::Vector<int>;
