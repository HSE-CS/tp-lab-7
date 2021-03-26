// Copyright 2021 Bogomazov
#ifndef _PREY_H_
#define _PREY_H_

#include "../include/object.h"

class Prey : public Object {
 protected:
      unsigned int life_time;
 public:
      explicit Prey(Cell* cell);
      void live() override;
      void breeding();
};

#endif  // _PREY_H_
