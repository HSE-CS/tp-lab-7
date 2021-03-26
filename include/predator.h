// Copyright 2020 S. BOR
#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "cell.h"
#include "ocean.h"


class Predator : public Object {
 private:
  bool isEat;
  int numberOfTurns = 10;
 public:
  bool tryEat();
  void createNew();
  void step();
  void nextTurn() override;
  void printSymb() override;
};

#endif  // INCLUDE_PREDATOR_H_

