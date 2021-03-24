// Copyright 2021 Kasyanov
#include "object.h"

Object::Object(Cell * _cell, ObjType _type) {
    cell = _cell;
    type = _type;
}

void Object::setCell(Cell * new_cell) {
    cell = new_cell;
}
