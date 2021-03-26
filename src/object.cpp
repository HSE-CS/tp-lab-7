// Copyright 2021 Andrey Bakurskii

#include "..\include\object.h"

Object::Object(Cell *c, ObjType ot) {
  this->setCell(c);
  this->obj_type = ot;
}

Object::~Object() { this->cell->setObj(nullptr); }

ObjType Object::getObjectType() { return this->obj_type; }

Pair Object::getCoord() { return this->cell->getCoord(); }

void Object::setCell(Cell *c) { this->cell = c; }
