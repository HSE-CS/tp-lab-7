// Copyright 2021 Galex

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include <string>
#include "../include/object.h"

class Prey : public Object {
 protected:
  unsigned int lifetime;
 public:
  explicit Prey(Cell *c = nullptr) : Object(c) {
    this->lifetime = 1;
    this->type_ = TYPE::PREY;
    this->cell = c;
  }
  void live() override;
  virtual void move();
  virtual void reproduce();
  std::string getOutput() override;
};
#endif  // INCLUDE_PREY_H_
