// Copyright 2021 FOM
#include "object.h"

Object::Object(Cell* cell) {
    this->cell = cell;
}

Object::~Object() {
    this->cell = nullptr;
}

void Object::setCell(Cell* cell) {
    this->cell = cell;
}

Cell* Object::getCell() {
    return cell;
}

char Object::getType() {
    return type;
}

void Object::setType(char type) {
    this->type = type;
}
