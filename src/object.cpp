// Copyright 2021 VadMack

#include <object.h>

Object::Object(Cell *cell) : cell(cell) {
}

Object::~Object() {
  this->cell = nullptr;
}
