// Copyright 2021 ArinaMonicheva

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include <ctime>
#include <cstdlib>
#include <vector>
#include "../include/stone.h"
#include "../include/ocean.h"
#include "../include/cell.h"

class Prey : public Stone {
 public:
  explicit Prey(Cell* newCell);
  ~Prey() = default;
  virtual void live();
  virtual bool tryToMove();
  virtual void die();
};

#endif  // INCLUDE_PREY_H_
