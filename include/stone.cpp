// Copyright <Roman Balayan> @ 2021

#include "stone.h"
#include "common.h"

Stone::Stone(std::weak_ptr<Cell> cell) : Object(cell) {
    this->type = ObjType::STONE;
}

void Stone::live() {
}
