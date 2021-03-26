// Copyright 2021 Kriss Egorova


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
