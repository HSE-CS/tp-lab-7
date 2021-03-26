// Copyright 2020 Osmanov Islam

#include <iostream>
#include <string>
#include <cmath>
#include "../include/stone.h"

Stone::Stone(Cell* cell1) :Object(ObjType::STONE, cell1) {
    this->cell = cell1;
}

void Stone::setCell(Cell* cell1) {
    cell = cell1;
}

void Stone::live() {
    return;
}

