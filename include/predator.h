// Copyright 2021 Schenikova
#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "./cell.h"

class Predator : public Object{
 private:
  int numberOfLive = 10;
  bool isHungry;
 public:
  // void eat();
  void step();
  void create();
  void live() override;
  void printInfo() override;
  bool IsPredator() override {return true;}
};


#endif  // INCLUDE_PREDATOR_H_
