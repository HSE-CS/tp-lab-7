// Copyright 2021 Egor Buzanov
#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "../include/cell.h"
#include "../include/common.h"

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
  explicit Object(Cell *_cell = nullptr) {
    cell = _cell;
    type = STONE;
  }
  virtual void live() = 0;
  void setCell(Cell *);
  ObjType getType() const;
  Cell *getCell() const;
};

#endif  // INCLUDE_OBJECT_H_
