// Copyright 2021 Stifeev Nikita

#include <cstdlib>
#include "../include/prey.h"
#include "../include/cell.h"

Prey::Prey(Cell* cell, char sign) : Object(cell, sign), iterCounter(0) {}

bool Prey::live() {
    iterCounter++;
    vector<Cell*>* emptyCells = cell->getEmptyCells();
    if (emptyCells->size() != 0) {
        int index = rand() % emptyCells->size();
        (*emptyCells)[index]->setObject(this);
        if (iterCounter % PREY_REPRODUCE == 0) {
            auto* child = new Prey(nullptr, PREY_SYMBOL);
            reproduce(emptyCells, index, child);
        }
        else {
            cell->setObject(nullptr);
            cell = (*emptyCells)[index];
        }
    }
    return iterCounter < PREY_DEATH;
}

void Prey::reproduce(vector<Cell*>* emptyCells, int index,
    Object* child) {
    Cell* previous_cell = cell;
    previous_cell->setObject(nullptr);
    cell = (*emptyCells)[index];
    emptyCells->erase(emptyCells->begin() + index);
    emptyCells->push_back(previous_cell);
    index = rand() % emptyCells->size();
    child->setCell((*emptyCells)[index]);
    (*emptyCells)[index]->setObject(child);
    (*emptyCells)[index]->addToOcean(child);
}
