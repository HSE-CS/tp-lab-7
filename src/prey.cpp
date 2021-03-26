//  Copyright 2021 Nikita Naumov

#include "../include/prey.h"
#include "../include/Object.h"
#include "../include/cell.h"

void Prey::setType() {
    this->type = ObjType::PREY;
}

Prey::Prey(Cell* thisCell) : Object(thisCell) {
        this->cell = thisCell;
        this->lifespan = 80;
        this->setType();
}

void Prey::live() {
    if (this->lifespan <= 0) {
        this->cell->killMe();
    } else if (this->steps >= 20) {
        Ocean* ocean = this->cell->getCurrentOcean();
        std::vector<Cell> nearby = ocean->getNearbyCells(this->cell->getX(), this->cell->getY());
        for (auto cells : nearby) {
            if (!(this->cooldown)) {
                if (cells.isFree()) {
                    Pair curPair = {cells.getX(), cells.getY()};
                    Cell* newCell = new Cell(curPair, ocean);
                    ocean->setObjectToCell(dynamic_cast<Object*>(new Prey(newCell)),curPair.x,curPair.y);
                    cooldown = true;
                }
                this->steps = 0;
                --lifespan;
            }
        }
    } else {
        if (cooldown && (steps == 10)) {
            cooldown = false;
        }
        Ocean* ocean = this->cell->getCurrentOcean();
        std::vector<Cell> nearby = ocean->getNearbyCells(this->cell->getX(), this->cell->getY());
        for (auto cells : nearby) {
            if (cells.isFree()) {
                cells.setObject(this);
                this->cell->setObject(nullptr);
                break;
            }
        }
    }
}
