//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#include "../include/stone.h"
#include "../include/cell.h"
#include "../include/ocean.h"

Stone::~Stone() {
  return;
}

void Stone::live() {
  Object::live();
}

void Stone::death() {
  cell->getOcean()->addDeleteCandidate(this);
  objType = ObjType::DEAD;
}

