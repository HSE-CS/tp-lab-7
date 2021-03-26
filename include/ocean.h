// Copyright 2020 S. BOR
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include "cell.h"

class Cell;
class Prey;
class Predator;

class Ocean {
 private:
  Cell ***cells;
 public:
  Ocean();
  void addObject(Object * obj, int i, int j);
  void run();
  void print();
  friend Cell;
  friend Prey;
  friend Predator;
};

#endif  // INCLUDE_OCEAN_H_

