// Copyright 2021 Egor Trukhin
#include "object.h"

Object::Object(Cell* cell) { this->cell = cell; }

void Object::setCell(Cell* cell) { this->cell = cell; }

object_t Object::getType() { return this->type; }

Cell* Object::getCell() const { return this->cell; }
