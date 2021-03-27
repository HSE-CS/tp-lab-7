// Copyright 2021 Smirnov Grigory
#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "../include/common.h"

#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'S'
#define NOTHING_N '.'

#define DEAD -1

enum class ObjType { STONE, PREY, PREDATOR };

class Cell;
class Object {
 protected:
	Cell* cell;
  char type;
  int status = 1;
 public:
  Object(Cell* c = nullptr);
  virtual void live() = 0; // жизнь объекта
  char getType();
  void setCell(Cell* c);
  void death();
  int getStatus();
};

#endif // INCLUDE_OBJECT_H_
