// Copyright 2021 mkhorosh

#include "../include/stone.h"

Stone::Stone(ObjType type, Cell *cell) : Object(type, cell) {
  this->type = type;
  this->cell = cell;
}
Stone::~Stone() {
}

void Stone::live() {
}
