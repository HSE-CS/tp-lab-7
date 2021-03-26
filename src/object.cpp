// Copyright 2021 Galex

#include "../include/object.h"

void Object::setCell(Cell *c) {
  this->cell = c;
}
Object::Object(Cell *c) {
  this->cell = c;
}
void Object::live() {
}
void Object::setType(TYPE t) {
  this->type_ = t;
}
TYPE Object::getType() {
  return this->type_;
}
Object::~Object() = default;
