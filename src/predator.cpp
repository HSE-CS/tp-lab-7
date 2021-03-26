// Copyright Mushka Nikita 2021

#include "predator.h"
#include <iostream>

#define DEATH_START 3;
#define BIRTH_START 2;


Predator::Predator(Cell *cell) : Prey(cell) {
    this->symbol = 'x';
    this->cell = cell;
    this->deathCounter = DEATH_START;
    this->birthCounter = BIRTH_START;
}

void Predator::step() {

    Cell * prey_cell = this->cell->findPrey();
    if (prey_cell) {
        this->deathCounter = DEATH_START;
        this->birthCounter --;
        prey_cell->getObject()->die();
        this->cell->setObject(nullptr);
        this->cell = prey_cell;
        this->cell->setObject(this);
    } else {
        this->deathCounter--;
    }
    if (!birthCounter){
        this->giveBirth();
    }
}

void Predator::giveBirth() {
    Prey::giveBirth();
}


