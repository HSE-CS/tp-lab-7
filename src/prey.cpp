// Copyright 2021 Bogomazov
#include "../include/prey.h"
#include "../include/common.h"
#include "../include/ocean.h"


Prey::Prey(Cell* cell) : Object(cell) {
    this->type = PREY_N;
    this->life_time = 15;
}


void Prey::live() {
    if (life_time > 0) {
        Cell* ptr_cell = cell->seachEmptyPlace();
        if (ptr_cell) {
            this->cell->setObject(nullptr);
            this->cell = ptr_cell;
            this->cell->setObject(this);
        }
        this->breeding();
        life_time--;
    } else {
        this->cell->killMe();
    }
}


void Prey::breeding() {
    Cell* ptr_cell = cell->seachEmptyPlace();
    if (ptr_cell) {
        Prey* ptr_prey = new Prey(ptr_cell);
        ptr_cell->setObject(ptr_prey);
        ptr_cell->getOcean()->addObject(ptr_prey);
    }
}
