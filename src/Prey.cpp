// Copyright 2021 Vlad
#include "Prey.h"

void Prey::live() {
    if (timeToReproduction == 0) {
        Cell* newCell = reproduct();
        if (newCell) {
            Object* child = new Prey(newCell, reproduction, death);
            child->setCell(newCell);
            newCell->setObject(child);
        }
        timeToReproduction = reproduction + 1;
    }
    if (timeTodeath == 0) {
        cell->killMe();
        return;
    }
    move();
    timeToReproduction--;
    timeTodeath--;
}
