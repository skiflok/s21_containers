//
// Created by Lok on 30.10.2022.
//

#ifndef S21_CONTAINERS_SRC_SEQUENCE_CONTAINER_H_
#define S21_CONTAINERS_SRC_SEQUENCE_CONTAINER_H_

#include "../container.h"

namespace s21 {

template<class T>
class SequenceContainer {
 public:
  class Iterator;
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = Iterator;
  using const_iterator = const Iterator;
  using size_type = size_t;

  SequenceContainer() {
    arr_ = new value_type[5]{1, 2, 3, 4, 5};
  }

  ~SequenceContainer();

  class Iterator {
   public:
    Iterator() = default;
    explicit Iterator(T *pt) : data_(pt) {}
    Iterator(const Iterator &other) : data_(other.data_) {}
    Iterator& operator=(const Iterator& other) {
      this->data_ = other.data_;
      return *this;
    }
    ~Iterator() = default;

//    ConstIterator &operator++();
//    ConstIterator operator++(int);
//    ConstIterator &operator--();
//    ConstIterator operator--(int);
//    operator const_pointer() { return this->data_; }
//    const_reference operator*();
//    ConstIterator operator+(const size_t value);
//    bool operator!=(const ConstIterator &other) const;
//    bool operator==(const ConstIterator &other) const;

    reference operator*() { return *data_; }
    Iterator operator+(size_type size) {
      return (data_ + size);
    }
//    Iterator operator++() {
//      data_++;
//      return *this;
//    }
    Iterator operator++(int) {
      Iterator temp(*this);
      this->data_++;
      return temp;
    }
    Iterator operator--() {
      return (--data_);
    }

   protected:
    T* data_{};
  };

  virtual Iterator begin() {
    Iterator temp(this->arr_);
    return temp;
  }

  virtual Iterator end() {
    Iterator temp(this->arr_);
    return temp;
  }


 private:
  T *arr_;

};
template<class T>
SequenceContainer<T>::~SequenceContainer() = default;

// template <class value_type>
// typename S21Vector<value_type>::iterator S21Vector<value_type>::begin() {
//   return this->arr_;
// }

// template <class T>
// SequenceContainer<T>::SequenceContainer() {}

// template <class T>
// SequenceContainer<T>::~SequenceContainer() {}

// SequenceContainer::~SequenceContainer() {}

}  // namespace s21

#endif  // S21_CONTAINERS_SRC_SEQUENCE_CONTAINER_H_
