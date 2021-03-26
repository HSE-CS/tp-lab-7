// Copyright 2021 by Sid

#include <stdio.h>
#include "Prey.h"


bool Prey::live() {
    if (lifetime-- <= 0) {
        return false;
    }
    move();
    if (reproduceTime-- <= 0) {
        reproduce();
        reproduceTime = PREY_REPRODUCE_PERIOD;
    }
    return true;
}

void Prey::move() {
    Cell* emptyCell = cell->findEmptyCell();
    if (emptyCell) {
        cell->setObject(nullptr);
        cell = emptyCell;
        cell->setObject(this);
    }
}

void Prey::reproduce() {
    Cell* emptyCell = cell->findEmptyCell();
    if (emptyCell) {
        Prey* child = new Prey(emptyCell, lifetime);
        emptyCell->setObject(child);
    }
}
