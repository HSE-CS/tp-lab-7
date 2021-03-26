// Copyright 2021 Elise
#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_
#include "../include/object.h"
#include "../include/cell.h"
#include "../include/ocean.h"
class Cell;

class Predator : public Object {
  friend Cell;

 private:
  int food;
  int time;
 public:
  explicit Predator(Cell* c);
  ~Predator() {}
  void live();
  void sail();
  void eat();
  void babies();
};

#endif  // INCLUDE_PREDATOR_H_
