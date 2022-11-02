//
// Created by Lok on 30.10.2022.
//

#ifndef S21_CONTAINERS_SRC_SEQUENCE_CONTAINER_H_
#define S21_CONTAINERS_SRC_SEQUENCE_CONTAINER_H_

#include "container.h"

namespace s21 {

template<class T>
class SequenceContainer : public Container {

 public:
  SequenceContainer(){}
  virtual ~SequenceContainer() =0;

 private:

};

template<class T>
SequenceContainer::~SequenceContainer() {}

} // s21

#endif //S21_CONTAINERS_SRC_SEQUENCE_CONTAINER_H_
