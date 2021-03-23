// Copyright by Egor Bodrov 2021

#include "stone.h"

Stone::Stone(Cell* cell) : Object {cell} { this->setType(ObjectType::STONE); }

void Stone::live() { return; }
