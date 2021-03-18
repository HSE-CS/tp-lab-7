// Copyright 2020 GHA Test Team
#include "stone.h"
#include "cell.h"


Stone::Stone() {
  this->cell = nullptr;
  // isAlive_ = false;
  obj_type = ObjType::STONE;
}

void Stone::live() {}
