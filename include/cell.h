// Copyright 2021 Andrey Bakurskii

#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "../include/object.h"
#include "../include/common.h"

class Ocean;

class Cell {
  friend Ocean;

 public:
  void initCell(Pair, Ocean*);
  
  Pair getCoord();
  Object* getObject();
  void setObj(Object*);
  void deleteObj();

 private:
  Ocean *ocean;
  Pair coord;
  Object *object;
  ObjType obj_type;
};


#endif  // INCLUDE_CELL_H_
