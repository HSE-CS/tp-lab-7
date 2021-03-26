// Copyright Mushka Nikita 2021

#include "cell.h"
#include "prey.h"
#include "object.h"
#include <iostream>

#define DEATH_TIME 5;
#define BIRTH_TIME 2;

Prey::Prey(Cell *cell) : Object(cell) {
    this->symbol = '*';
    this->cell = cell;
    this->deathCounter = DEATH_TIME;
    this->birthCounter = BIRTH_TIME;

}

void Prey::step() {
    this->deathCounter--;
    this->birthCounter--;

    if (this->deathCounter == 0) {
        this->die();
        return;
    }

    std::cout << "fuckme";
    std::cout << this->cell->getCoords().x;
    Cell * cell_toMove = this->cell->findPlaceToMove();


    if (cell_toMove) {
        this->cell->setObject(nullptr);
        this->cell = cell_toMove;
        this->cell->setObject(this);
    }

    if (!birthCounter) {
        birthCounter = BIRTH_TIME;
        this->giveBirth();
    }
}



void Prey::giveBirth() {
    Cell *cell_toBirth = this->cell->findPlaceToMove();
    if (cell_toBirth) {
        cell_toBirth->setObject(this);
    }
}
