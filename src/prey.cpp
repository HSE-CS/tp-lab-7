// Copyright slavokeru 2021
#include<iostream>
#include"prey.h"
#include"cell.h"
#include"ocean.h"
Prey::Prey(Cell* newCell) {
    this->timeToReproduction = std::rand() % 3 + 3;
    this->reproduction = 0;
    this->cell = newCell;
    this->type = ObjType::PREY;
    this->timeLive = std::rand() % 10 + 10;
}
void Prey::live() {
    if (this->timeLive) {
        if (this->reproduction == this->timeToReproduction) {
            Cell* newCell{ this->cell->getFreeNeighbour() };
            if (newCell && !newCell->getObject()) {
                this->cell->addObject(this->type, newCell);
                this->reproduction = 0;
            }
        }
        else {
            Cell* newCell{ this->cell->getFreeNeighbour() };
            if (newCell && !newCell->getObject()) {
                this->cell->setObject(nullptr);
                this->setCell(newCell);
                this->cell->setObject(this);
            }
        }
        this->timeLive--;
        this->reproduction++;
    }
    else {
        this->cell->setObject(nullptr);
        this->setCell(nullptr);
    }
}