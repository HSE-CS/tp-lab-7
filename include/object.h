//// Copyright 2021 Lukicheva Polina

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "common.h"
#include "ocean.h"
#include "object.h"
#include "cell.h"

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType { STONE, CORAL, PREY, PREDATOR };

class Object {
protected:
  Cell* cell;
  ObjType type;
  bool dead;
public:
  Object(ObjType t, Cell* c) : cell(c)
    type(t), dead(false) {}
  virtual ~Object();
  Cell* getCell();
  virtual void live() = 0;
  void setCell(Cell*);
  virtual void move();
  void die();
  ObjType getType();

}
#endif