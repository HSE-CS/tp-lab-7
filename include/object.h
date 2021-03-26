// Copyright 2021 Shirokov Alexander

#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "../include/common.h"

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType { STONE, CORAL, PREY, PREDATOR };

class Cell;
class Object {
 protected:
  Cell* cell;
  ObjType type{};
  char symbol;

 public:
  explicit Object(Cell* cell = nullptr);
  virtual ~Object();
  virtual void live() = 0;
  void setCell(Cell* cell);
  Cell* getCell();
  void setType(ObjType type);
  ObjType getType();
  char getSymbol();
};
#endif  // INCLUDE_OBJECT_H_
