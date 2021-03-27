// Copyright [2020] <Olesya Nikolaeva>

#include "object.h"
#include "cell.h"

Object::~Object() {
  this->cell = nullptr;
}

void Object::live() {}

void Object::setCell(Cell* new_cell) {
    if (type != ObjType::EMPTY) {
        new_cell->changeStatus(false);
    }
    cell = new_cell;
    cell->setObject(this);
}

void Object::setObjType(ObjType type) {
    this->type = type;
}

ObjType Object::getObjType() {
    return type;
}
