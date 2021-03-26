// Copyright 2021 Ryzhova
#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "../include/common.h"

class Cell;
class Pair;

class Object {
protected:
  Cell *cell;
  ObjType type;
  unsigned int lifetime = 0;

 public:
  Object(ObjType, Cell * = nullptr);
  virtual ~Object();
  virtual void live() = 0; // жизнь объекта
  virtual void propagation();
  virtual void moving(Cell*);
  void setCell(Cell*);
  void setLifetime(unsigned int);
  ObjType getType() const;
  unsigned int getLifetime() const;
  Cell* findEmpty(Cell*);
  Cell* findPrey(Cell*);
};

#endif  // INCLUDE_OBJECT_H_
