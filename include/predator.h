// Copyright 2021 Dev-will-work
#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_
#include <iostream>
#include <string>
#include "../include/prey.h"

class Predator : public Prey {
 public:
  Predator();
  virtual ~Predator();
  virtual void live();  // object logic
  virtual void print();

 private:
  size_t starvingLevel = STARVING;
};
#endif  // INCLUDE_PREDATOR_H_
