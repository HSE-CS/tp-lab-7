// Copyright 2021 Artem Danyaev
#include "../include/prey.h"

Prey::Prey(Cell* c) : Object(ObjType::PREY, c) {}

void Prey::live() {
    Cell* newcell = findFreeNeighbour();
    if (newcell != nullptr) {
        newcell->setObject(this);
        if (reprTime == 0) {
            Prey* newprey = new Prey(cell);
            cell->setObject(newprey);
            cell->getOcean()->addObject(newprey);
            reprTime = preyReprTime;
        }
        else {
            cell->setObject(nullptr);
        }
        cell = newcell;
    }
    if (reprTime > 0) {
        reprTime--;
    }
    lifetime--;
    if (lifetime == 0) {
        cell->setObject(nullptr);
        cell->getOcean()->deleteObject(this);
    }
}
