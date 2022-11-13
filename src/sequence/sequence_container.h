//
// Created by Lok on 30.10.2022.
//

#ifndef S21_CONTAINERS_SRC_SEQUENCE_CONTAINER_H_
#define S21_CONTAINERS_SRC_SEQUENCE_CONTAINER_H_

#include "../container.h"

namespace s21 {

template <class T>
class SequenceContainer {
 public:
  using reference = T &;
  using value_type = T;
  using pointer = T *;
  using size_type = size_t;

  SequenceContainer() {
    arr_ = new value_type[5]{1, 2, 3, 4, 5};
//    iterator_.SetData(arr_);
  }
  ~SequenceContainer() {}

//  class Iterator;
//  friend class Iterator;

  class Iterator {
   public:
    Iterator() {
      //      data_ = &SequenceContainer<T>::arr_;
    }
    Iterator(pointer pt) : data_(pt) {}

    Iterator(const Iterator &other) : data_(other.data_) {}

    void SetData(pointer data) {
      data_ = data;
    }

    value_type operator*() { return *data_; }
    Iterator operator+(size_type size) {
      return (data_ + size);
    }
    Iterator operator++() {
      return (++data_);
    }

   protected:
    pointer data_{};
  };

 public:
  using iterator = Iterator;
  pointer arr_{};
//  iterator iterator_;

  T *data() {
    return arr_;
  }

  iterator begin() {
    iterator temp(this->arr_);
    return temp;
  }
};

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
