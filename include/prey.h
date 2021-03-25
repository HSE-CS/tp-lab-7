// Copyright NikDemoShow 2021
#ifndef _PREY_H_
#define _PREY_H_
#include"object.h"
class Prey : public Object {
 public:
  unsigned int timeToReproduction;
  unsigned int timeLive;
  unsigned int reproduction;
 public:
  Prey(Cell* newCell = nullptr);
  virtual void live() override;

};

#endif // _PREY_H_
