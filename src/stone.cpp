// Copyright 2021 Stolbov Yaroslav

#include "../include/stone.h"

Stone::Stone(Cell* c) :Object(c) {
    setTimeOfLive(TIME_STONE);
    this->type = ObjType::STONE;
}

void Stone::live() {
    time_of_life--;
    if (time_of_life == 0) {
        die();
    }
}


char Stone::getSymbol() {
    return STONE_N;
}
