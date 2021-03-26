// Copyright 2021 by me
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include<typeinfo>

#include "Object.h"

class Prey : public Object {
 private:
  size_t lifeTime;
  size_t breedTime;
  size_t breedCoolDawn;

 public:
  explicit Prey(Cell *cell_ = nullptr,
       size_t lifeTime_ = 0, size_t breedCoolDawn_ = 0);
  void live() override;
  void breedingTime();
  void death();
  void move();
};

#endif  // INCLUDE_PREY_H_
