//  Copyright 2021 Nikita Naumov

#include "../include/prey.h"
#include "../include/Object.h"
#include "../include/cell.h"

Prey::Prey(Cell* thisCell) : Object(thisCell) {
        this->cell = thisCell;
        this->lifespan = 80;
}

void Prey::live() {
    if (this->lifespan == 0) {
        this->cell->killMe();
    }
    if (this->steps == 20) {
        Ocean* ocean = this->cell->getCurrentOcean();
        std::vector<Cell> nearby = ocean->getNearbyCells(this->cell->getX(), this->cell->getY());
        for (auto cell : nearby) {
            if (!(this->cooldown)) {
                if (cell.isFree()) {
                    Pair curPair; curPair.x = cell.getX(); curPair.y = cell.getY();
                    Cell* newCell = new Cell(curPair, ocean);
                    ocean->setObjectToCell(dynamic_cast<Object*>(new Prey(newCell)),curPair.x,curPair.y);
                }
            }
        }
    }

}
void Prey::setType() {
    this->type = static_cast<ObjType> (2);
}

