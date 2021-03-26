// Copyright 2021 Elise
#include "../include/stone.h"

Stone::Stone(Cell* cell) : Object(cell) {
    this->type_object = STONE_N;
}
void Stone::live() { return; }
