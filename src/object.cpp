// Copyright 2021 MalininDmitry

#include "object.h"

Object::Object(Cell * cell) {
    this->cell = cell;
}

Object::Object(Cell * cell, ObjType type) {
    this->cell = cell;
    this->type = type;
}

void Object::setCell(Cell *c) {
    cell = c;
}

Object::~Object() {}

ObjType Object::getType() {
    return this->type;
}
