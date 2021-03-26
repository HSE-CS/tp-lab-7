// Copyright NikDemoShow 2021
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_
#include "object.h"
class Prey : public Object {
 public:
  unsigned int ReproductionTime;
  unsigned int LiveTime;
  unsigned int reproduct;

 public:
  Prey(Cell* newCell = nullptr);
  void live() override;
};

#endif  // INCLUDE_PREY_H_
