// Copyright 2021 Ilya Urtyukov
#include "object.h"


void Object::setCell(Cell* cell) {
  this->cell = cell;
}

ObjType Object::getObjType() {
  return obj_type;
}

Cell* Object::getCell() const {
  return cell;
}
