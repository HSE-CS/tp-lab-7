// Copyright 2021 Shirokov Alexander

#include "../include/object.h"

Object::Object(Cell* cell) {
  this->cell = cell;
}

Object::~Object() {
  this->cell = nullptr;
}

void Object::setCell(Cell* cell) {
  this->cell = cell;
}

Cell* Object::getCell() {
  return this->cell;
}

void Object::setType(ObjType type) {
  this->type = type;
  switch (this->getType()) {
    case ObjType::STONE:
      this->symbol = STONE_N;
      break;
    case ObjType::PREY:
      this->symbol = PREY_N;
      break;
    case ObjType::CORAL:
      this->symbol = CORAL_N;
      break;
    case ObjType::PREDATOR:
      this->symbol = PREDATOR_N;
  }
}

ObjType Object::getType() {
  return type;
}

char Object::getSymbol() {
  return this->symbol;
}
