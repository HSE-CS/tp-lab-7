// Copyright 2021 Khoroshavina Ekaterina
#include "stone.h"

Stone::Stone(ObjType newObjType, Cell* cell) : Object(newObjType, cell) {
    this->objType = newObjType;
    this->hp = HP_STONE;
}

Stone::~Stone() {
}

void Stone::live() {
    hp--;
    if (hp == 0) {
        death();
    }
}
