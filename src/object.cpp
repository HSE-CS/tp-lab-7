// Copyright 2021 Elise
#include "../include/object.h"

Object::Object(Cell* cell) {
    this->cell = cell;
}

Object::~Object() {
    this->cell = nullptr;
}

void Object::setCell(Cell* cell) {
    this->cell = cell;
}

char Object::get_type() {
    return type_object;
}

void Object::set_type(char new_type) {
    this->type_object = new_type;
}
