// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 20.03.2021.
//
#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_
#include "../include/common.h"



enum class ObjType {
  STONE,
  PREY,
  PREDATOR,
  EMPTY
};

class Cell;

class Object {
 protected:
  Cell *cell;

 private:
  ObjType ot;
 public:
  explicit Object(ObjType type, Cell *cl = nullptr);
  void setCell(Cell *sl);
  ObjType getObjType();
  void setObjType(ObjType objTypeValue);
  virtual ~Object();
  virtual void live() = 0;



};

#endif  //  INCLUDE_OBJECT_H_
