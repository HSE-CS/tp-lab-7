#include "object.h"

Object::Object(Cell *cell) {
    this->cell = cell;
}

Cell *Object::getCell() {
    return this->cell;
}

void Object::setCell(Cell *c) {
    this->cell = c;
}

Object::~Object() = default;
