// Copyright 2021 LongaBonga

#include "stone.h"
Stone::Stone(Cell *c) : Object(c) {
  this->livetime = LTStone;
  type = ObjType::STONE;
}
void Stone::live() { livetime--; }
char Stone::getSymbol() { return STONE_N; }
