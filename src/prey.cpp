// Copyright 2021 Rogov Andrey

#include "../include/predator.h"
#include "../include/cell.h"
#include "../include/ocean.h"

Prey::~Prey() {
    return;
}

void Prey::move() {
    Cell* newCell = cell->getOcean()->findEmpty(cell);
    if (newCell == nullptr)
        return;
    cell->setObject(nullptr);
    newCell->setObject(this);
    setCell(newCell);
}

void Prey::breed() {
    Cell* newCell = cell->getOcean()->findEmpty(cell);
    if (newCell == nullptr)
        return;
    Prey* preyChild = new Prey(newCell);
    newCell->setObject(preyChild);
    cell->getOcean()->addObject(preyChild);
}

void Prey::live() {
    if (healthPoints == 0) {
        death();
        return;
    }

    if (breedCounter >= breedRate) {
        breedCounter = 0;
        breed();
    } else {
        breedCounter++;
        move();
    }
    healthPoints--;
}

void Prey::death() {
    cell->getOcean()->addDeleteCandidate(this);
    objType = ObjType::DEAD;
}
