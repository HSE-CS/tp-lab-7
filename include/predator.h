#ifndef _PREDATOR_H_
#define _PREDATOR_H_

#include "cell.h"
#include "common.h"
#include "object.h"
#include "ocean.h"
class Predator : public Object {
  friend Cell;

 public:
  Predator(Cell* c);
  ~Predator(){};
  void copulation();
  void live() override;
  void move();
  bool eat();
  char getSymbol() override;
};

#endif
