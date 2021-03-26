// Copyright 2021 Shirokov Alexander

#ifndef _OBJECT_H_
#define _OBJECT_H_

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
  Object(Cell* cell = nullptr);
  virtual ~Object();
  virtual void live() = 0; // жизнь объекта
  void setCell(Cell*);
  Cell* getCell();
  void setType(ObjType type);
  ObjType getType();
  char getSymbol();
};
#endif
