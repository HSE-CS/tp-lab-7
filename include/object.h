//// Copyright 2021 Ozhiganova Polina
#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_
#include "../include/common.h"

#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'S'
#define EMPTY_N '~'

enum class ObjType {
  STONE,
  PREY,
  PREDATOR,
  EMPTY
};

class Cell;

class Object {
 public:
  explicit Object(ObjType type, Cell *cl = nullptr);
  virtual ~Object();
  virtual void live() = 0;
  void setCell(Cell *sl);
  ObjType getObjType();
  void setObjType(ObjType obj_type);

 protected:
  Cell *cell;

 private:
  ObjType ot;
};

#endif  //  INCLUDE_OBJECT_H_
