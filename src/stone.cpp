// Copyright dmitrycvetkov 2021
#include "stone.h"

Stone::Stone(std::weak_ptr<Cell> cell) : Object(cell) {
}

void Stone::live() {
}

ObjType Stone::type() const {
    return ObjType::STONE;
}
