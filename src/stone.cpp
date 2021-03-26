// Copyright 2020 Uskova

#include "stone.h"

Stone::Stone(Cell* c, ObjType objType) : Object(c, objType) {}


char Stone::getObjSym() {
    return STONE_N;
}


void Stone::live() {
}

/*ObjType Stone::getType() {
    return this->type;
}*/
