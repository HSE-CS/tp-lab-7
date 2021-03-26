//  Copyright 2021 GHA created by Klykov Anton

#include "Object.h"
Object::Object(Cell* cell) {
  obj_cell = cell;
}
void Object::SetCell(Cell* cell) {
  obj_cell = cell;
}
std::string Object::getName() {
  return std::string();
}
Object::~Object() {
  obj_cell = nullptr;
}
