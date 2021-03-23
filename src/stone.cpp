// Copyright 2021 Ilya Urtyukov
#include "stone.h"
#include "cell.h"


Stone::Stone() {
  this->cell = nullptr;
  obj_type = ObjType::STONE;
}

void Stone::live() {}

