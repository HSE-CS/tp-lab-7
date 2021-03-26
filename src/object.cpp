// Copyright TimurZaytsev 2021
#include "../include/object.h"

#include "../include/cell.h"
void Object::set(Cell* newCell) { this->cell = newCell; }
Cell* Object::getCell() { return this->cell; }
