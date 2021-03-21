// Copyright 2020 GHA Test Team
#include "../include/stone.h"
#include "../include/cell.h"


Stone::Stone() {
  this->cell = nullptr;
  // isAlive_ = false;
  obj_type = ObjType::STONE;
}

void Stone::live() {}
