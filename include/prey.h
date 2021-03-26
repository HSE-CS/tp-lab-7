// Copyright 2021 ArinaMonicheva

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "stone.h"
#include "ocean.h"
#include "cell.h"
#include <ctime>
#include <cstdlib>
#include <vector>

class Prey : public Stone {
 public:
  Prey(Cell* newCell);
  ~Prey() = default;
  virtual void live();
  virtual bool tryToMove();
  virtual void die();
};

#endif  // INCLUDE_PREY_H_
