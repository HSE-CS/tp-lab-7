// Copyright 2021 Stifeev Nikita

#include "../include/predator.h"
#include "../include/cell.h"
#include <vector>
#include <cstdlib>

using std::vector;

Predator::Predator(Cell* cell, char sigh) :
    Prey(cell, sigh), itersSinceEating(0) {}

bool Predator::live() {
    iterCounter++;
    itersSinceEating++;
    hunt();
    vector<Cell*>* emptyCells = cell->getEmptyCells();
    if (emptyCells->size() != 0) {
        int index = rand() % emptyCells->size();
        (*emptyCells)[index]->setObject(this);
        if (iterCounter % PREDATOR_REPRODUCE == 0 &&
            itersSinceEating <= PREDATOR_REPRODUCE_WO_EATING) {
            auto* child = new Predator(nullptr, PREDATOR_SYMBOL);
            reproduce(emptyCells, index, child);
        }
        else {
            cell->setObject(nullptr);
            cell = (*emptyCells)[index];
        }
    }
    return iterCounter < PREDATOR_DEATH &&
        itersSinceEating < PREDATOR_LIFE_WO_EATING;
}

void Predator::hunt() {
    vector<Cell*>* preyCells = cell->getPreyCells();
    if (!preyCells->empty()) {
        int index = rand() % preyCells->size();
        (*preyCells)[index]->killMe();
        itersSinceEating = 0;
    }
}
