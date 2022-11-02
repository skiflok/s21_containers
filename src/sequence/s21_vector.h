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
  // Vector Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

 private:
  size_type size_;
  size_type capacity_;
  T *arr;

 public:

//  Vector Member functions

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
  S21Vector(S21Vector &&v) noexcept: size_(v.size_), capacity_(v.capacity_), arr(v.arr) {
    v.arr = nullptr;
    v.size_ = 0;
  }

  // destructor
  ~S21Vector() { delete[] arr; }

  S21Vector &operator=(const S21Vector &v);
  S21Vector &operator=(S21Vector &&v) noexcept;

//  Vector Element access

  reference at(size_type pos);    // access specified element with bounds checking
  reference operator[](size_type pos);    //access specified element
  const_reference front();    //access the first element
  const_reference back();    //access the last element
  T *data();    //direct access to the underlying array

  // Vector Iterators

  iterator begin();    //returns an iterator to the beginning
  iterator end();    //returns an iterator to the end

  // Vector Capacity

  bool empty();    //checks whether the container is empty
  size_type size();    //returns the number of elements
  size_type max_size();    //returns the maximum possible number of elements
  void reserve(size_type size);    //allocate storage of size elements and copies current array elements to a newely allocated array
  size_type capacity();    //returns the number of elements that can be held in currently allocated storage
  void shrink_to_fit(); //reduces memory usage by freeing unused memory

  // Vector Modifiers

  void clear();    //clears the contents
  iterator insert(iterator pos,
                  const_reference value);    //inserts elements into concrete pos and returns the iterator that points to the new element
  void erase(iterator pos);    //erases element at pos
  void push_back(const_reference value);    //adds an element to the end
  void pop_back();    //removes the last element
  void swap(S21Vector &other);    //swaps the contents

// MY TESTS
  void TestPrint() {
    std::cout << "TestPrint" << std::endl;
  }

};

template<class value_type>
S21Vector<value_type>::S21Vector(const std::initializer_list<value_type> &items) {
  arr = new value_type[items.size()];
  int i = 0;
  for (auto it = items.begin(); it != items.end(); it++)
  {
    arr[i] = *it;
    i++;
  }
  size_ = items.size();
  capacity_ = items.size();
}

// not ready
template<class value_type>
S21Vector<value_type> &S21Vector<value_type>::operator=(const S21Vector &v) {
  return *this;
}

// not ready
template<class value_type>
S21Vector<value_type> &S21Vector<value_type>::operator=(S21Vector &&v) noexcept {

  return *this;
}



} // s21

#endif //S21_CONTAINERS_SRC_S21_VECTOR_H_
