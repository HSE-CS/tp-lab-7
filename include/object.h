// Copyright 2021 ArinaMonicheva

#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "../include/common.h"

#define STONE_N 'o'
#define CORAL_N '*'
#define PREY_N '&'
#define PREDATOR_N 'w'
#define LIVES 12
#define HUNGER 3
#define REPRODUCE 4
#define P_REPRODUCE 3

enum class ObjType { EMPTY = -1, STONE, PREY, PREDATOR };

class Cell;

class Object {
 protected:
  Cell* inCell;
  ObjType type;
  int livesCount;
  int reproduceCycle;
  int hunger;

 public:
  explicit Object(Cell* newCell = nullptr);
  virtual ~Object() = default;
  virtual void live() = 0;
  void setCell(Cell* newCell);
  ObjType getType();
  virtual void die() = 0;
  int livesLeft();
};

#endif  // INCLUDE_OBJECT_H_
