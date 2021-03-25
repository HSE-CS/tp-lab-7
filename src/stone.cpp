// Copyright 2021 Egor Trukhin
#include "stone.h"

Stone::Stone(Cell* cell) : Object(cell) { this->type = object_t::STONE; }

void Stone::live() {
  // stay calm
  // just chill
}
