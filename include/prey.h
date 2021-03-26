//// Copyright 2021 Lukicheva Polina

#ifndef _PREY_H_
#define _PREY_H_

#include "stone.h"
#include "object.h"

class Prey : public Object {
private:
  ObjType objT;
  int health;
  int mulP;
public:
  explicit Prey(Cell* cell, int life, int mulP) : Object(ObjType::PREY, cell), health(PREY_LIFE), mulP(3) {}
  ~Prey();
  void move() override;
  void live() override;
  
};
#endif
