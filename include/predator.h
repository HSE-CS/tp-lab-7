// Copyright 2021 Galex

#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "../include/prey.h"

class Predator : public Prey{
 protected:
  int satiety = PREDATOR_MAX_SATIETY - 1;
 public:
  explicit Predator(Cell *c = nullptr) : Prey(c) {
      this->lifetime = 1;
      this->type_ = TYPE::PREDATOR;
      this->cell = c;
  }
  void live() override;
  void reproduce() override;
  void move() override;
  std::string getOutput() override;
};

#endif  // INCLUDE_PREDATOR_H_
