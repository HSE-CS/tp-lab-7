// Copyright 2021 Elise
#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "../include/common.h"

#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType { STONE, CORAL, PREY, PREDATOR };

class Cell;
class Object {
 protected:
  Cell *cell;
  char type_object;
 public:
  explicit Object(Cell * = nullptr);
  virtual ~Object();
  virtual void live() = 0;
  void setCell(Cell *);
  char get_type();
  void set_type(char type);
};
#endif  // INCLUDE_OBJECT_H_
