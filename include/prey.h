// Copyright TimurZaytsev 2021
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_
#include "../include/object.h"
class Prey : public Object {
 public:
  unsigned int ReproductionTime;
  unsigned int LiveTime;
  unsigned int reproduct;

 public:
  explicit Prey(Cell* newCell = nullptr);
  void live() override;
};

#endif  // INCLUDE_PREY_H_
