// Copyright 2021 Ilya Urtyukov
#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_
#include <utility>
#include "prey.h"


class Predator : public Prey {
 public:
  Predator();
  Predator(unsigned, unsigned);
  ~Predator() = default;
  Predator(const Predator&) = default;
  Predator& operator=(const Predator&) = default;
  void live() override;
  void move(Pair cur_pos, Pair new_pos, Ocean* ocean) override;
  bool reproduce(Pair new_pos, Ocean* ocean) override;
};
#endif  // INCLUDE_PREDATOR_H_
