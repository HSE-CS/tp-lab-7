// Copyright 2021 Dumarevskaya
#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "common.h"
#include "Cell.h"

#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'S'
#define EMPTY_N '~'

enum class ObjType {
  STONE,
  PREY,
  PREDATOR,
  EMPTY
};

class Cell;

class Object {
 protected:
  Cell *cell;
  ObjType type;
 public:
  explicit Object(Cell* new_cell = nullptr) : cell{ new_cell } {}
  ~Object() {}
  virtual void live() = 0;
  void setCell(Cell*);
  void setObjType(ObjType);
  ObjType getObjType();
};

#endif  // INCLUDE_OBJECT_H_
