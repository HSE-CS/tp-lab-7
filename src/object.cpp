// Copyright 2021 Rogov Andrey

#include "../include/object.h"
#include "../include/cell.h"
#include "../include/ocean.h"

Object::~Object() {
  cell->setObject(nullptr);
}

void Object::move() {
  return;
}

void Object::setCell(Cell* newCell) {
  this->cell = newCell;
}

ObjType Object::getObjType() {
  return this->objType;
}

void Object::live() {
  return;
}

bool Object::isDead() {
  return objType == ObjType::DEAD;
}
