// Copyright <Roman Balayan> @ 2021

#include "../include/stone.h"
#include "../include/common.h"

Stone::Stone(std::weak_ptr<Cell> cell) : Object(cell) {
    this->type = ObjType::STONE;
}

void Stone::live() {
}
