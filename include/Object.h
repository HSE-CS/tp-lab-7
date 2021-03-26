// Copyright 2020 Uskova
#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "common.h"

#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'O'
#define EMPTY_N '.'

enum class ObjType { STONE, PREY, PREDATOR, EMPTY };

class Cell;

class Object {
 protected:
  Cell *cell;
  ObjType type;
 public:
  Object(Cell * = nullptr, ObjType = ObjType::EMPTY);
  virtual ~Object();
  virtual void live() = 0;  // жизнь объекта
  void setCell(Cell *);
  virtual char getObjSym() = 0;
  void setObjType(ObjType);
  ObjType getType();
};


#endif  // INCLUDE_OBJECT_H_
