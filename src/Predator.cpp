// Copyright 2021 by Sid

#include "Predator.h"

void Predator::reproduce() {
    Cell* emptyCell = cell;
    if (emptyCell) {
        Prey* child = new Predator(emptyCell, lifetime);
        emptyCell->setObject(child);
    }
}

bool Predator::eat() {
    Cell* cellWithPrey = cell->findPrey();
    if (cellWithPrey) {
        cellWithPrey->getObject()->setLifetime(0);
        return true;
    }
    return false;
}

bool Predator::live() {
    if (lifetime-- <= 0) {
        return false;
    }
    bool isHungry = !eat();
    move();
    if (--reproduceTime <= 0) {
        if (!isHungry) {
            reproduce();
            reproduceTime = PREDATOR_REPRODUCE_PERIOD;
        }
    }
    return true;
}