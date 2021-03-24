// Copyright 2021 Igumnova Natasha
#include "prey.h"
#include "cell.h"
#include "ocean.h"
#include <fstream>
#include <string>
#include <cmath>

Prey::~Prey() {
    delete cell;
}
void Prey::live() {
    if (health == 0) {
        delete this;
        return;
    }
    if (multCounter >= multiPoint) {
        multCounter = 0;
        multi();
    }
    else {
        multCounter++;
        move();
    }
    health -= 1;
}
void Prey::move() {
    Cell* cell_for_move = cell->getOcean()->findCell(cell);
    if (cell_for_move != nullptr) {
        cell->setObject(nullptr);
        cell_for_move->setObject(this);
        setCell(cell_for_move);
    }
}
void Prey::multi() {
    Cell* cell_for_mult = cell->getOcean()->findCell(cell);
    if (cell_for_mult != nullptr) {
        Prey* new_prey = new Prey(cell_for_mult);
        cell_for_mult->setObject(new_prey);
        cell->getOcean()->addObject(new_prey);
    }
}
void Prey::setCell(Cell* cell_) {
    cell = cell_;
}
