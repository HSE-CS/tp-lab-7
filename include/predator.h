// Copyright GN 2021
#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "../include/prey.h"

class Predator : public Object {
 private:
  int time_of_life = 1;
  int time_of_hunger = 0;

 public:
  void setCell(Cell* c);
  void setObjectType();
  void reproduction();
  int hunting();
  void die();
  void move();
  void live();
  void printObject();
  int getTimeOfHunger();
  void init(Cell* c);
  int getObjectINT();
  char getObjectChar();
};
#endif  // INCLUDE_PREDATOR_H_
