// Copyright 2021 Egor Buzanov
#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "common.h"

#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum ObjType { STONE, PREY, PREDATOR };

class Cell;

class Object {
 protected:
  Cell *cell;
  ObjType type;

 public:
  Object(Cell * = nullptr);
  virtual ~Object();
  virtual void live() = 0;
  void setCell(Cell *);
};

#endif  // INCLUDE_OBJECT_H_
