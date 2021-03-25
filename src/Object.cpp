// Copyright 2021 Dumarevskaya
#include "Object.h"

void Object::setCell(Cell* new_cell) {
  cell = new_cell;
}

void Object::setObjType(ObjType type) {
  this->type = type;
}
ObjType Object::getObjType() {
  return type;
}

void Object::live() {}
