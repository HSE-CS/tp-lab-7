//  Copyright 2021 Kartseva Masha
#include "../include/stone.h"
Stone::Stone(Cell* c) :Object(c) {
    this->lifetime = LTStone;
    type = ObjType::STONE;
}
void Stone::live() {
    lifetime--;
}
char Stone::getSymbol() {
    return STONE_N;
}
