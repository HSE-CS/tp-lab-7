// Copyright 2020 GHA Test Team
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_
#include <utility>
#include <iostream>
#include "object.h"
#include "cell.h"



class Prey : public Object {
 protected:
  unsigned live_count, max_live_count;
  unsigned food_n_to_reproduce, init_food_n_to_reproduce;

 public:
  Prey();
  Prey(unsigned live_count,
    unsigned food_n_to_reproduce);
  ~Prey() = default;
  Prey(const Prey&) = default;
  Prey& operator=(const Prey&) = default;
  virtual void move(Pair cur_pos, Pair new_pos, Ocean* ocean);
  Pair findPosition(Ocean* ocean);
  virtual bool reproduce(Pair new_pos, Ocean* ocean);
  void live();
};
#endif  // INCLUDE_PREY_H_
