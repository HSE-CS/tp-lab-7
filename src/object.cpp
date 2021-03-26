// Copyright [2020] <Olesya Nikolaeva>

#include "object.h"

void Object::live() {}

void Object::setCell(Cell* cell) {
    this->cell = cell;
}

void Object::setObjType(ObjType type) {
    this->type = type;
}

ObjType Object::getObjType() {
    return type;
}
