//  Copyright 2021 Nikita Naumov

#include "../include/predator.h"
#include "../include/Object.h"
#include "../include/cell.h"
#include "../include/None.h"

void Predator::setType() {
    this->type = ObjType::PREDATOR;
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
        if ((this->fullness > predatorFullnessToBreed) && (this->step > predatorBreedtime)) {
            for (auto cells : nearby) {
                if (cells.isFree()) {
                    Pair curPair = {cells.getX(), cells.getY()};
                    Cell* newCell = new Cell(curPair, thisOcean);
                    thisOcean->setObjectToCell(static_cast<Object*>(new Predator(newCell)),curPair.x,curPair.y);
                    Object* objToAdd = thisOcean->returnByCoords(curPair.x,curPair.y);
                    thisOcean->addToVector(objToAdd);
                    this->fullness = predatorFullnessAfterBreed;
                    this->step = 0;
                    break;
                }
            }
        }
        for (auto cells : nearby) {
            if (!(cells.isFree())) {
                Object *obj = cells.getObject();
                if (obj->getType() == ObjType::PREY) {  //  If the object in busy cell is a prey
                    cells.killMe();
                    this->fullness = 100;
                    cells.setObject(this);
                    None* _none = new None(this->cell);
                    this->cell->setObject(_none);
                    break;
                } else if ((obj->getType() == ObjType::STONE) ||
                           (obj->getType() == ObjType::CORAL) ||
                        (obj->getType() == ObjType::PREDATOR)) {  //  If the object in cell is a stone/coral/predator
                    --(this->fullness);
                    continue;
                }
            } else {
                --(this->fullness);
                cells.setObject(this);
                None* _none = new None(this->cell);
                this->cell->setObject(_none);
                break;
            }
        }
    }
}
