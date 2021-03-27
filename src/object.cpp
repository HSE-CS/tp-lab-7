// Copyright 2021 Lab_7 TiNa
#include "object.h"

Object::Object(Cell* cell) { this->cell = cell; }

Object::~Object() { this->cell = nullptr; }

void Object::setCell(Cell* cell) { this->cell = cell; }

ObjType Object::getType() { return type; }
