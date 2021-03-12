//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#include "stone.h"
#include "cell.h"
#include "ocean.h"

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

