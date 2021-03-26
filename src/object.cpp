// Copyright 2021 ArinaMonicheva

#include "object.h"
#include "cell.h"

Object::Object(Cell* newCell) {
  type = ObjType::EMPTY;
  setCell(newCell);
  livesCount = LIVES;
  hunger = HUNGER;
}

void Object::setCell(Cell* newCell) {
  this->inCell = newCell;
  this->inCell->setObject(this);
}

ObjType Object::getType() {
  return type;
}

int Object::livesLeft() {
  return livesCount;
}

void Object::live() {
  return;
}

void Object::die() {
  return;
}
