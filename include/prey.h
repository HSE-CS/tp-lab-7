// Copyright 2021 Dev-will-work
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_
#include <iostream>
#include <string>
#include "include/stone.h"
#include "include/cell.h"
#include "include/ocean.h"

class Prey : public Stone {
 public:
  Prey();
  virtual ~Prey();
  virtual void live();  // object logic
  virtual void print();

 private:
};
#endif  // INCLUDE_PREY_H_
