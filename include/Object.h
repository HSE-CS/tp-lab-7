// Copyright GN 2021
#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "common.h"

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType { STONE, CORAL, PREY, PREDATOR};

class Cell;

class Object {
 protected:
  Cell* cell;
  int objType;

 public:
  Object() {
    cell = nullptr;
    objType = -1;
  }
  virtual ~Object() {
    cell = nullptr;
    objType = -1;
  };
  virtual void setCell(Cell* cl) = 0;
  virtual void live() = 0;
  virtual void printObject() = 0;
  virtual char getObjectChar() = 0;
  virtual int getObjectINT() = 0;
};
#endif
