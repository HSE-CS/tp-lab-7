// Copyright 2021 Khoroshavina Ekaterina
#include "../include/prey.h"

Prey::Prey(ObjType newObjType, Cell* cell) : Object(newObjType, cell) {
    this->objType = newObjType;
    this->hp = HP_PREY;
}

Prey::~Prey() {
}

void Prey::live() {
    move();
    hp--;
    if (hp == 0) {
        death();
    } else if (hp % 3) {
        breed();
    }
}

void Prey::move() {
    Cell* newCell = cell->makeNewCell();
    if (cell->getObject() == nullptr) {
        cell->setObject(nullptr);
        this->setCell(nullptr);
        newCell->setObject(this);
        cell = newCell;
    }
}

void Prey::breed() {
    Cell* newCell = cell->makeNewCell();
    if (newCell->getObject() == nullptr) {
        Object* small_prey = new Prey(ObjType::PREY, newCell);
        cell->getOcean()->addObject(small_prey);
        newCell->setObject(small_prey);
    }
}
