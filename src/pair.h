//
// Created by Lok on 29.10.2022.
//

#ifndef SRC_PAIR_H_
#define SRC_PAIR_H_

#include "container.h"

namespace s21 {

template<class T1, class T2>
class Pair : public Container{

 public:
  Pair() : first_(0), second_(0) {};
  Pair(T1 first, T2 second) {
    this->first_ = first;
    this->second_ = second;
  }
  T1 GetFirst() const {
    return first_;
  }
  T2 GetSecond() const {
    return second_;
  }

  void SetFirst(T1 first) {
    first_ = first;
  }
  void SetSecond(T2 second) {
    second_ = second;
  }

 private:
  T1 first_;
  T2 second_;
};

} // s21

#endif //SRC_PAIR_H_
