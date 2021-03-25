// Copyright 2021 Dumarevskaya
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "Object.h"

class Prey : public Object {
 protected:
  int lifeTime;
  int timeToReproduce;
 public:
  explicit Prey(Cell* cell, ObjType type = ObjType::PREY) : Object(type, cell) {
    lifeTime = PREY_LIFE;
    timeToReproduce = PREY_BREED;
  }
  ~Prey() {}
  void live() override;
  virtual void move();
  virtual void reproduce();
  Cell* getCell();
};

#endif  // INCLUDE_PREY_H_
