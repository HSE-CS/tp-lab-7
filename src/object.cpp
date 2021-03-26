// Copyright 2021 Egor Buzanov

#include "../include/object.h"

void Object::setCell(Cell* _cell) { cell = _cell; }

ObjType Object::getType() const { return type; }

Cell* Object::getCell() const { return cell; }
