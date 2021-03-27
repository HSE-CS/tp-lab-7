// Copyright 2021 Lab_7 TiNa
#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "common.h"

#define STONE_N '*'
#define PREY_N 'o'
#define PREDATOR_N 'E'

enum ObjType { STONE, CORAL, PREY, PREDATOR };

class Cell;
class Object {
 protected:
  Cell *cell;
  ObjType type;

 public:
  explicit Object(Cell * = nullptr);
  virtual ~Object();
  virtual void live() = 0;
  void setCell(Cell * cell);
  ObjType getType();

};

#endif  // INCLUDE_OBJECT_H_
