// Copyright 2021 Sozinov Kirill
#include "../include/stone.h"

Stone::Stone(Cell* cell) : Object(cell) {
    this->type = STONE_N;
}
void Stone::live() {
    return;
}
