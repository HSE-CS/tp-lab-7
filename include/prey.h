// Copyright 2021 Egor Buzanov
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include <random>

#include "../include/object.h"

class Prey : public Object {
 protected:
  unsigned int lifetime;
  unsigned int age;
  unsigned int reproduction;

 public:
  explicit Prey(Cell *_cell = nullptr) : Object(_cell) {
    type = PREY;
    std::random_device rd;
    std::mt19937 mersenne(rd());
    lifetime = mersenne() % 30 + 1;
    age = 0;
    reproduction = lifetime / 3;
  }
  void live() override;
};

#endif  // INCLUDE_PREY_H_
