//  Copyright 2021 Nikita Naumov

#include "../include/prey.h"
#include "../include/Object.h"
#include "../include/cell.h"
#include "../include/None.h"

void Prey::setType() {
    this->type = ObjType::PREY;
}

Prey::Prey(Cell* thisCell) : Object(thisCell) {
        this->cell = thisCell;
        this->lifespan = preyLifespan;
        this->setType();
}

void Prey::live() {
    if (this->lifespan <= 0) {
        this->cell->killMe();
    } else if (this->steps >= preyBreedtime) {
        Ocean* ocean = this->cell->getCurrentOcean();
        std::vector<Cell> nearby = ocean->getNearbyCells(this->cell->getX(), this->cell->getY());
        for (auto cells : nearby) {
            if (!(this->cooldown)) {
                if (cells.isFree()) {
                    Pair curPair = {cells.getX(), cells.getY()};
                    Cell* newCell = new Cell(curPair, ocean);
                    ocean->setObjectToCell(static_cast<Object*>(new Prey(newCell)),curPair.x,curPair.y);
                    cooldown = true;
                }
                this->steps = 0;
                --lifespan;
            }
        }
    } else {
        if (cooldown && (steps == preyBreedCooldown)) {
            cooldown = false;
        }
        Ocean* ocean = this->cell->getCurrentOcean();
        std::vector<Cell> nearby = ocean->getNearbyCells(this->cell->getX(), this->cell->getY());
        for (auto cells : nearby) {
            if (cells.isFree()) {
                cells.setObject(this);
                None* _none = new None(this->cell);
                this->cell->setObject(_none);
                break;
            }
        }
    }
}
