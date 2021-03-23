// Copyright 2021 Khoroshavina Ekaterina
#include "object.h"

Object::Object(ObjType newObjType, Cell* cell) {
    this->cell = cell;
    this->objType = newObjType;
    this->alive = true;
}

Object::~Object() {
    this->cell = nullptr;
}

void Object::setCell(Cell*) {
    this->cell = cell;
}

void Object::death() {
    this->alive = false;
}

Cell* Object::getCell() {
    if (cell) {
        return this->cell;
    } else {
        return nullptr;
    }
}

ObjType Object::getType() {
    return this->objType;
}

bool Object::isAlive() const {
    return this->alive;
}
