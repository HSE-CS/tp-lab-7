// Copyright 2021 mkhorosh

#include "object.h"
#include <iostream>

void Object::printObj() {
  if (this == nullptr) {
    std::cout << ' ';
  } else if (type == ObjType::STONE) {
    std::cout << STONE_N;
  } else if (type == ObjType::PREY) {
    std::cout << PREY_N;
  } else if (type == ObjType::PREDATOR) {
    std::cout << PREDATOR_N;
  } else {
    std::cout << ' ';
  }
}
Object::Object(ObjType type, Cell *c) {
  this->cell = c;
  this->type = type;
  this->alive = true;
}
void Object::setCell(Cell *c) {
  this->cell = c;
}
Object::~Object() {
  this->cell = nullptr;
}
void Object::death() {
  this->alive = false;
}
bool Object::isAlive() {
  return alive;
}
ObjType Object::getType() {
  return this->type;
}
Cell *Object::getCell() {
  return this->cell;
}
