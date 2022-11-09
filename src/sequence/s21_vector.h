//
// Created by Lok on 01.11.2022.
//

#ifndef S21_CONTAINERS_SRC_S21_VECTOR_H_
#define S21_CONTAINERS_SRC_S21_VECTOR_H_

#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <utility>
#include <valarray>

namespace s21 {

template <class T>
class S21Vector {
 public:
  // Vector Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  // default constructor (simplified syntax for assigning values to attributes)
  S21Vector() : size_(0U), capacity_(0U), arr_(nullptr) {}
  // parametrized constructor for fixed size vector (explicit was used in order
  // to avoid automatic type conversion)
  explicit S21Vector(size_type n)
      : size_(n), capacity_(n), arr_(n ? new T[n] : nullptr) {}
  // initializer list constructor (allows creating lists with initializer lists,
  // see main.cpp)
  S21Vector(std::initializer_list<value_type> const &items);
  // copy constructor with simplified syntax
  S21Vector(const S21Vector &v)
      : size_(v.size_), capacity_(v.capacity_), arr_(v.arr_){};
  // move constructor with simplified syntax
  S21Vector(S21Vector &&v) noexcept
      : size_(v.size_), capacity_(v.capacity_), arr_(v.arr_) {
    v.arr_ = nullptr;
    v.size_ = 0;
  }

  // destructor
  ~S21Vector() { delete[] arr_; }

  // Assignment operator
  S21Vector &operator=(const S21Vector &v);
  S21Vector &operator=(S21Vector &&v) noexcept;

  //  Vector Element access

  reference at(size_type pos);  // access specified element with bounds checking
  reference operator[](size_type pos);  // access specified element
  const_reference front();              // access the first element
  const_reference back();               // access the last element
  T *data();                            // direct access to the underlying array

  // Vector Iterators

  iterator begin();  // returns an iterator to the beginning
  iterator end();    // returns an iterator to the end

  // Vector Capacity

  bool empty();      // checks whether the container is empty
  size_type size();  // returns the number of elements
  size_type max_size()
      const noexcept;  // returns the maximum possible number of elements
  void reserve(
      size_type size);  // allocate storage of size elements and copies current
  // array elements to a newely allocated array
  size_type capacity()
      const;  // returns the number of elements that can be held in
  // currently allocated storage
  void
  shrink_to_fit() noexcept;  // reduces memory usage by freeing unused memory

  // Vector Modifiers

  void clear();  // clears the contents
  iterator insert(
      iterator pos,
      const_reference value);  // inserts elements into concrete pos and returns
  // the iterator that points to the new element
  void erase(iterator pos);               // erases element at pos
  void push_back(const_reference value);  // adds an element to the end
  void pop_back();                        // removes the last element
  void swap(S21Vector &other);            // swaps the contents

  // MY TESTS
  void TestPrint() { std::cout << "TestPrint" << std::endl; }

  bool operator==(const S21Vector<value_type> &other) {
    bool equal = false;
    bool skip = false;

    if (this == &other) {
      equal = true;
      skip = true;
    }

    if (!skip) {
      if (this->size_ != other.size_ || this->capacity_ != other.capacity_) {
        equal = false;
        skip = true;
      }
    }

    if (!skip) {
      equal = true;
      for (int i = 0; i < this->size_; ++i) {
        if ((this)->arr_[i] != other.arr_[i]) {
          equal = false;
          break;
        }
      }
    }

    return equal;
  }

 private:
  size_type size_;
  size_type capacity_;
  T *arr_;
  void reserve_more_capacity(size_t size);
};

//_____CONSTRUCTORS_____
template <class value_type>
S21Vector<value_type>::S21Vector(
    const std::initializer_list<value_type> &items) {
  arr_ = new value_type[items.size()];
  int i = 0;
  for (auto it = items.begin(); it != items.end(); it++) {
    arr_[i] = *it;
    i++;
  }
  size_ = items.size();
  capacity_ = items.size();
}

//_____ASSIGNMENT_OPERATORS_____
// not ready
template <class value_type>
S21Vector<value_type> &S21Vector<value_type>::operator=(const S21Vector &v) {
  bool is_not_ready_to_return = true;

  if (this->arr_ == v.arr_) {
    is_not_ready_to_return = false;
  }

  if (is_not_ready_to_return) {
    if (this->arr_ != nullptr) delete[] this->arr_;
    this->capacity_ = v.capacity_;
    this->size_ = v.size_;
    arr_ = new value_type[capacity_];
    if (!this->arr_) throw std::bad_alloc();
    std::copy(v.arr_, v.arr_ + size_, this->arr_);
  }
  std::cout << "EXECUTE operator=(const S21Vector &v)" << std::endl;
  return *this;
}

// not ready
template <class value_type>
S21Vector<value_type> &S21Vector<value_type>::operator=(
    S21Vector &&v) noexcept {
  if (this != &v) {
    if (this->arr_ != v.arr_) {
      if (this->arr_ != nullptr) {
        delete[] this->arr_;
        this->arr_ = nullptr;
        this->size_ = 0;
        this->capacity_ = 0;
      }
      std::swap(this->arr_, v.arr_);
      std::swap(this->size_, v.size_);
      std::swap(this->capacity_, v.capacity_);
    }
  }
  //  std::swap(*this, v);
  std::cout << "EXECUTE operator=(const S21Vector &&v)" << std::endl;
  return *this;
}

//_____VECTOR_ELEMENT_ACCESS_____

template <class value_type>
typename S21Vector<value_type>::reference S21Vector<value_type>::at(
    S21Vector::size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("pos < 0 or pos >= size_");
  }
  return arr_[pos];
}

template <class value_type>
typename S21Vector<value_type>::reference S21Vector<value_type>::operator[](
    S21Vector::size_type pos) {
  return arr_[pos];
}

template <class value_type>
typename S21Vector<value_type>::const_reference S21Vector<value_type>::front() {
  return at(0);
}

template <class value_type>
typename S21Vector<value_type>::const_reference S21Vector<value_type>::back() {
  return at(size_ - 1);
}

template <class T>
T *S21Vector<T>::data() {
  return arr_;
}

//_____VECTOR_ITERATORS_____
template <class value_type>
typename S21Vector<value_type>::iterator S21Vector<value_type>::begin() {
  return this->arr_;
}

template <class value_type>
typename S21Vector<value_type>::iterator S21Vector<value_type>::end() {
  return this->arr_ + size_;
}

//_____VECTOR_CAPACITY_____
template <class value_type>
bool S21Vector<value_type>::empty() {
  return size_ == 0;
}

template <class value_type>
typename S21Vector<value_type>::size_type S21Vector<value_type>::size() {
  return size_;
}

template <class value_type>
typename S21Vector<value_type>::size_type S21Vector<value_type>::max_size()
    const noexcept {
  //  char bits = 63;
  //  if (sizeof(void *) == 4) {
  //    bits = 31;
  //  }
  //  return static_cast<size_type>(pow(2, bits)) / sizeof(value_type) - 1;
  return SIZE_MAX / sizeof(value_type);
}

template <class value_type>
void S21Vector<value_type>::reserve(S21Vector::size_type size) {
  if (size > this->max_size()) throw std::length_error("size > max_size");

  if (size > capacity_) {
    if (arr_ != nullptr) {
      auto *temp = new value_type[size];
      if (!temp) throw std::bad_alloc();
      std::move(arr_, arr_ + size_, temp);
      std::swap(arr_, temp);
      delete[] temp;
      capacity_ = size;
    }
  }
}

template <class value_type>
typename S21Vector<value_type>::size_type S21Vector<value_type>::capacity()
    const {
  return capacity_;
}

template <class value_type>
void S21Vector<value_type>::shrink_to_fit() noexcept {
  if (size_ != capacity_) {
    S21Vector<value_type> temp(size_);
    std::move(arr_, arr_ + size_, temp.arr_);
    std::swap(arr_, temp.arr_);
    capacity_ = std::move(temp.capacity_);
  }
}

//_____VECTOR_MODIFIERS_____
template <class value_type>
void S21Vector<value_type>::push_back(const_reference value) {
  if (size_ == capacity_) {
    auto size = (size_) ? size_ : 1;
    reserve_more_capacity(size * 2);
  }
  arr_[size_++] = value;
}

//_____SUPPORT_FUN_____

template <typename T>
void S21Vector<T>::reserve_more_capacity(size_t size) {
  if (size > capacity_) {
    value_type *buff = new value_type[size];
    for (size_t i = 0; i < size_; ++i) buff[i] = std::move(arr_[i]);
    delete[] arr_;
    arr_ = buff;
    capacity_ = size;
  }
}

}  // namespace s21

#endif  // S21_CONTAINERS_SRC_S21_VECTOR_H_
