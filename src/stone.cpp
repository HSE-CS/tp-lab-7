// copyright 2021 Victor Shatilov

#include "../include/stone.h"

void stone::live() {
    // Stone just exists lmao
}

Object *stone::divide() {
    // I think that stone cannot divide
    return nullptr;
}

stone::stone(int x,
             int y,
             int energy,
             int type,
             Cell *cell) : Object(x, y, energy, type, cell) { }

char stone::getFiller() {
    return stone_symbol;
}
