//  Copyright 2021 Nikita Naumov

#include "../include/predator.h"
#include "../include/Object.h"
#include "../include/cell.h"

void Predator::setType() {
    this->type = static_cast<ObjType>(3);
}

Predator::Predator(Cell *thisCell) : Object(thisCell) {
    this->cell = thisCell;
    this->fullness = 100;
    this->setType();
}

void Predator::live() {
    if (this->fullness <= 0) {
        this->cell->killMe();
    } else {
        Ocean *thisOcean = this->cell->getCurrentOcean();
        std::vector<Cell> nearby = thisOcean->getNearbyCells(this->cell->getX(), this->cell->getY());
        if ((this->fullness > 70) && (this->step > 8)) {
            for (auto cells : nearby) {
                if (cells.isFree()) {
                    Pair curPair = {cells.getX(), cells.getY()};
                    Cell* newCell = new Cell(curPair, thisOcean);
                    thisOcean->setObjectToCell(dynamic_cast<Object*>(new Predator(newCell)),curPair.x,curPair.y);
                    this->fullness = 15;
                    this->step = 0;
                    break;
                }
            }
        }
        for (auto cells : nearby) {
            if (!(cells.isFree())) {
                Object *obj = cells.getObject();
                if (obj->getType() == static_cast<ObjType>(2)) {  //  If the object in busy cell is a prey
                    cells.killMe();
                    this->fullness = 100;
                    cells.setObject(this);
                    this->cell->killMe();
                    break;
                } else if ((obj->getType() == static_cast<ObjType>(0)) ||
                (obj->getType() == static_cast<ObjType>(1)) ||
                        (obj->getType() == static_cast<ObjType>(3))) {  //  If the object in cell is a stone/coral/predator
                    --(this->fullness);
                    continue;
                }
            } else {
                --(this->fullness);
                cells.setObject(this);
                this->cell->killMe();
                break;
            }
        }
    }
}
