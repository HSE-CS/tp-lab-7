// Copyright 2021 Schenikova
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "./cell.h"
#include "./ocean.h"

class Prey : public Object {
 private:
  void step();
  int len = 10;
  int through = 3;
  int numberOfLive = 10;
  void create();
 public:
  bool IsPrey() override {return true;}
  void live() override;
  void printInfo() override;
};


#endif  // INCLUDE_PREY_H_
