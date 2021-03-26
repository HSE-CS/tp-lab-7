//// Copyright 2021 Lukicheva Polina
#ifndef _PREDATOR_H_
#define _PREDATOR_H_
#include <iostream>
#include <string>
#include <vector>
#include "../include/prey.h"

class Predator : public Prey {
protected:
  int hunger = 0;
public:
  Predator(Cell* c,
    int health = PREDATOR_LIFE, int multi_ = 3, int hun = 2) :
    Prey(c, health, multi_) {
    this->hunger = 3;
    this->type = ObjType::PREDATOR;
  }
  ~Predator();
  void live() override;
  void eat();
  void setCell(Cell*);
};
#endif
