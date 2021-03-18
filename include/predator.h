// Copyright 2020 GHA Test Team
#ifndef _PREDATOR_H_
#define _PREDATOR_H_
#include "prey.h"


class Predator : public Prey {
 public:
  Predator();
  Predator(unsigned live_count,
    unsigned food_n_to_reproduce);
  ~Predator() = default;
  Predator(const Predator&) = default;
  Predator& operator=(const Predator&) = default;
  void live() override;
  void move(Pair cur_pos, Pair new_pos, Ocean* ocean) override;
  bool reproduce(Pair new_pos, Ocean* ocean) override;
};
#endif  // INCLUDE_PREDATOR_H_
