// Copyright 2021 Dev-will-work
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_
#include <iostream>
#include <string>
#include "../include/object.h"

class Stone : public Object {
 public:
  Stone();
  virtual ~Stone();
  virtual void live();  // object logic
  virtual void print();

 private:
};
#endif  // INCLUDE_STONE_H_
