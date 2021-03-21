// Copyright 2021 Rogov Andrey

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include <string>
#include <iostream>
#include "../include/object.h"

class Prey : public Object {
protected:
  int healthPoints;
  int breedCounter = 0;
  int breedRate;
  virtual void breed();
  void move() override;

public:
  Prey(Cell* newCell = nullptr,
    int newHealthpoints = 6, int newBreedRate = 2) :
    Object(ObjType::PREY, newCell),
    healthPoints(newHealthpoints), breedRate(newBreedRate) {}
  ~Prey();
  void live() override;
  void death() override;
};

#endif  // INCLUDE_PREY_H_
