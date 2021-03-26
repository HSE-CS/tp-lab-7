// Copyright 2021 ArinaMonicheva

#include "stone.h"
#include "cell.h"

Stone::Stone(Cell* newCell) : Object(newCell) {
  type = ObjType::STONE;
}

void Stone::live() {
  return;
}

void Stone::die() {
  return;
}
