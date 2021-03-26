// Copyright JMax 2021

#include <iostream>
#include <vector>

#include "../include/Prey.h"

Prey::Prey(Cell *cell, int minSize) : Object(PREY, cell) {
    size = getRandom(MAX_PREY_SIZE - 1) + minSize;
}

void Prey::live() {
    if (isAlive()) {
        if (!checkAge()) {
            death();
            return;
        }
        increaseAge();
        reproductionCycle++;
        move();
    }
}

void Prey::move() {
    Pair crd = cell->getCoordinates();

    std::vector<Cell*> emptyCells;
    bool hasFriends = false;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            Cell* cellToMove = cell->getCell({ crd.x + i, crd.y + j });
            if (isEmpty(cellToMove)) {
                emptyCells.push_back(cellToMove);
            } else if(isFriend(cellToMove)) {
                hasFriends = true;
            }
        }
    }
    if (!emptyCells.empty()) {
        makeStep(getCell(emptyCells),
                 doReproduction(), hasFriends);
    }
}

Cell* Prey::getCell(std::vector<Cell*> &availableCells) {
    int idx = getRandom(availableCells.size());
    return availableCells[idx];
}

bool Prey::doReproduction(int cycle) {
    if (reproductionCycle >= cycle) {
        reproductionCycle = 0;
        if (getRandom(2)) {
            return true;
        }
    }
    return false;
}

void Prey::makeStep(Cell* dest, bool doReproduction, bool hasFriends) {
    Cell* previousCell = cell;
    changeCell(dest);

    if (doReproduction) {
        int minSize = 1;
        if (hasFriends) {
            minSize = getRandom(MAX_PREY_SIZE / 2);
        }

        Object* object = new Prey(previousCell, minSize);
        previousCell->setObject(object);
        previousCell->addToStuff(object);
    }
}

bool Prey::isFriend(Cell *cell) const {
    return cell->getType() == getType();
}

bool Prey::isEmpty(Cell *cell) {
    return cell->getType() == NOTHING;
}
