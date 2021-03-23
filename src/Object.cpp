// Copyright 2021 Dev-will-work
#include "Object.h"
#include "Common.h"

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
