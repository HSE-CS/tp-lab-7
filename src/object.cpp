// Copyright 2021 Dev-will-work
#include "../include/object.h"
#include "../include/common.h"

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
