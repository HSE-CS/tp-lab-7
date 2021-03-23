// Copyright 2021 Dev-will-work
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_
#include <iostream>
#include <string>
#include "Stone.h"
#include "Cell.h"
#include "Ocean.h"

class Prey : public Stone {
 public:
  Prey();
  virtual ~Prey();
  virtual void live();  // object logic
  virtual void print();

 private:
};
#endif  // INCLUDE_PREY_H_
