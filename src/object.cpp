// Copyright TimurZaytsev 2021
#include "object.h"

#include "cell.h"
void Object::set(Cell* newCell) { this->cell = newCell; }
Cell* Object::getCell() { return this->cell; }
