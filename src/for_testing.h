//
// Created by Lok on 23.10.2022.
//

#ifndef SRC_FOR_TESTING_H_
#define SRC_FOR_TESTING_H_
#include "pair.h"

namespace s21 {
template<class T1, class T2>
class For_testing {

 public:

  int GetA() const {
    return a_;
  }
  void SetA(int a) {
    this->a_ = a;
  }

  Pair<T1, T2> &GetPair()  {
    return pair_;
  }
  void SetPair(const Pair<T1, T2> &pair) {
    pair_ = pair;
  }

 private:
  int a_{};

//  class Iterator {
//
//   public:
//
//   private:
//
//   public:
//    Iterator();
//  };
//
//  Iterator iterator_;


  Pair<T1, T2> pair_;

};

} // s21

#endif //SRC_FOR_TESTING_H_
