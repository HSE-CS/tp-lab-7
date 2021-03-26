// Copyright 2021 VladimirUspensky

#include "stone.h"

Stone::Stone(Cell *cell) : Object(cell) {
    type = ObjType::STONE;
}

Stone::~Stone() {}

void Stone::live() {}
