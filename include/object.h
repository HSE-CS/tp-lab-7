// Copyright 2021 Egor Trukhin
#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "common.h"

class Cell;

class Object {
 protected:
  object_t type;
  Cell* cell;

 public:
  explicit Object(Cell* = nullptr);
  object_t getType();

  void setCell(Cell*);
  Cell* getCell() const;

  virtual void live() = 0;
};

// Additional interface
class Alive {
 protected:
  bool isAlive;
  uint32_t health;
  uint32_t stamina;

  virtual void move() = 0;
  virtual void reproduce() = 0;
};

#endif  // INCLUDE_OBJECT_H_
