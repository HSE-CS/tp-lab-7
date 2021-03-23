// Copyright 2021 Dev-will-work
#include "object.h"
#include "common.h"

Object::Object(Cell* arg) {
  this->cell = arg;
}

Object::~Object() {
}

void Object::setCell(Cell* cell) {
  this->cell = cell;
}

Cell* Object::getCell() {
  return this->cell;
}

ObjType Object::getType() {
  return this->type;
}
