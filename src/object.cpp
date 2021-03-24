// Copyright 2020 Vadukk

#include "../include/object.h"

Object::Object(Cell* cell) {
  this->cell = cell;
  this->dead = false;
}

void Object::setCell(Cell* cell) {
  this->cell = cell;
}
Cell* Object::getCell() {
  return cell;
}

void Object::setTimeOfLive(int time) {
  this->time_of_life = time;
}

void Object::die() {
  this->dead = true;
  this->time_of_life = 0;
}

int Object::getState() const {
  return this->dead;
}
