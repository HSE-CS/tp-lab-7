// Copyright 2021 Ryzhova
#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "../include/object.h"

class Predator : public Object {
 private:
  unsigned int victimCounter;

 public:
  explicit Predator(Cell* cell);
  ~Predator() {}
  void live() override;
  void propagation() override;
  void moving(Cell* newCell) override;
  void murder(Cell*);
};

#endif  // INCLUDE_PREDATOR_H_
