// Copyright 2020 Konina Tatiana
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_
#include "object.h"
#include "cell.h"
#include "ocean.h"
#include "common.h"

//class Cell;
//class Ocean;
class Prey :public Object {
  friend Cell; friend Ocean;
 public:
  Prey(Cell* cell);
  ~Prey() {};
  void live();
  char getSymbol()override;
  void move();
  void makeChild();
};


#endif  // INCLUDE_PREY_H_




