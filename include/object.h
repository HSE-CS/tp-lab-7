//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "common.h"

enum class ObjType {CORAL,PREY,PREDATOR, DEAD};

class Cell;

class Object {
 protected:
  Cell* cell;
  ObjType objType;
  virtual void move();

 public:
  Object(ObjType newObjType, Cell* startCell = nullptr):
  cell(startCell), objType(newObjType) {}
  virtual ~Object();
  virtual void live() = 0;
  virtual void death() = 0;
  void setCell(Cell* newCell);
  ObjType getObjType();
  bool isDead();
};

#endif // INCLUDE_OBJECT_H_
