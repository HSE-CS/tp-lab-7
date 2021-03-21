// Copyright 2020 GHA Test Team
#include "../include/object.h"


void Object::setCell(Cell* cell) {
  this->cell = cell;
}

ObjType Object::getObjectType() {
  return obj_type;
}

Cell* Object::getCell() const {
  return cell;
}
