// Copyright 2021 BekusovMikhail

#include "../include/stone.h"

Stone::Stone(Cell *cell) : Object(cell) {
    this->type = STONE_N;
}

void Stone::live() {
}
