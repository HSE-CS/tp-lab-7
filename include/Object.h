// Copyright 2021 by me
#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "common.h"

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType { EMPTY, STONE, CORAL, PREY, PREDATOR };

class Cell;

class Object {
 protected:
  Cell *cell = nullptr;
  ObjType type = ObjType::EMPTY;

 public:
  explicit Object(Cell *cell_, ObjType type_) : cell(cell_), type(type_) {};
  //virtual ~Object();
  virtual void live() = 0;
  void setCell(Cell *);
  void print();
  Pair getCoord();
  Cell *getCell();
  ObjType getType();
};

#endif  // INCLUDE_OBJECT_H_
