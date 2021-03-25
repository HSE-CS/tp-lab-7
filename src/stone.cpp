// Copyright 2021 MalininDmitry
#include "stone.h"

Stone::Stone(Cell* cell) : Object(cell, ObjType::STONE) {
    this->type = ObjType::STONE;
}

Stone::~Stone() {
}

void Stone::live() {
}
