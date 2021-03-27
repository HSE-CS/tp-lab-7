//  Copyright 2021 Nikita Naumov

#include "../include/prey.h"
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
        std::vector<Cell> nearby = ocean->getNearbyCells(this->cell->getX(),
                                                         this->cell->getY());
        for (auto cells : nearby) {
            if (!(this->cooldown)) {
                if (cells.isFree()) {
                    Pair curPair = {cells.getX(), cells.getY()};
                    ocean->setObjectToCell(this, curPair.x, curPair.y);
                    this->cooldown = true;
                }
                this->steps = 0;
            }
        }
        --(this->lifespan);
        ++(this->steps);
    } else {
        if (this->cooldown && (steps == preyBreedCooldown)) {
            this->cooldown = false;
        }
        std::vector<Cell> nearby =
                (this->cell->getCurrentOcean())->
                getNearbyCells(this->cell->getX(), this->cell->getY());
        for (auto cells : nearby) {
            if (cells.isFree()) {
                this->cell = &cells;
                cells.setObject(this);
                None* _none = new None(this->cell);
                this->cell->setObject(_none);
                break;
            }
        }
        --(this->lifespan);
        ++(this->steps);
    }
}
