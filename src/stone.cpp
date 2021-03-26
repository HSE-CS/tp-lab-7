// Copyright 2021 Shirokov Alexander

#include "../include/stone.h"

Stone::Stone(Cell* cell) : Object{ cell } {
  this->setType(ObjType::STONE); 
}

void Stone::live() {
	return;
}
