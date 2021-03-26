// Copyright 2021 Andrey Bakurskii

#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'S'
#define EMPTY_N '~'

#include "common.h"
#include "cell.h"


enum class ObjType { STONE, PREY, PREDATOR, EMPTY };

class Object {
 public:
  Object(Cell*, ObjType);
  ~Object();

  ObjType getObjectType();
  Pair getCoord();
  virtual void live() = 0;
  void setCell(Cell *);

 private:
  Cell *cell;
  ObjType obj_type;
};

#endif  // INCLUDE_OBJECT_H_
