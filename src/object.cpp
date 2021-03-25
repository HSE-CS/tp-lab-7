// Copyright NikDemoShow 2021
#include"object.h"
#include"cell.h"
void Object::setCell(Cell *newCell) { this->cell = newCell; }
Cell* Object::getCell() { return this->cell; }
