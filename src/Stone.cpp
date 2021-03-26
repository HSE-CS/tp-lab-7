// Copyright 2021 Krayushkina
#include "Stone.h"
Stone::Stone(Cell * c) :Object(c) {
    this->lifetime = LTStone;
    type = ObjType::STONE;
};
void Stone::live() {
    lifetime--;
};
char Stone::getSymbol() {
    return STONE_N;
};
