// Copyright 2020 S. BOR
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "include/cell.h"
#include "include/ocean.h"

class Prey : public Object {
 public:
  void nextTurn() override;
  void printSymb() override;
  bool isPrey() override {return true;}
 private:
  int numberOfTurns = 10;
  void step();
  void createNew();
};

#endif  // INCLUDE_PREY_H_

