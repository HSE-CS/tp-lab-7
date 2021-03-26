// Copyright 2021 mkhorosh

#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "../include/common.h"

#define STONE_N 'O'
#define PREY_N '='
#define PREDATOR_N '<'

enum class ObjType { STONE, PREY, PREDATOR, EMPTY };

class Cell;

class Object {
  friend Cell;
 protected:
  Cell *cell;
  ObjType type;
  bool alive;
 public:
  explicit Object(ObjType type, Cell *c = nullptr);
  virtual ~Object();
  virtual void live() = 0;  // жизнь объекта
  void setCell(Cell *c);
  void death();
  bool isAlive();
  ObjType getType();
  Cell *getCell();
  void printObj();
};

#endif  // INCLUDE_OBJECT_H_
