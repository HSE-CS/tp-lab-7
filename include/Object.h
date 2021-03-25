// Copyright 2021 Dumarevskaya
#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "Common.h"

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
  explicit Object(ObjType ot, Cell* new_cell = nullptr)
    : type{ ot }, cell{ new_cell } {}
  ~Object() {
    cell = nullptr;
  }
  virtual void live() = 0;
  void setCell(Cell*);
  void setObjType(ObjType);
  ObjType getObjType();
};

#endif  // INCLUDE_OBJECT_H_
