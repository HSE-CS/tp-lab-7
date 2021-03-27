// Copyright 2021 Lab_7 TiNa
#include "stone.h"

Stone::Stone(Cell* cell) : Object(cell) { type = STONE; }

void Stone::live() { return; }