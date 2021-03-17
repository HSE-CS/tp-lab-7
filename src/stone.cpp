// Copyright 2021 valvarl

#include "stone.h"

Stone::~Stone() {}

void Stone::live() {}

Stone::Stone(Cell *_cell) : Object(_cell) {
    type = ObjType::STONE;
}
