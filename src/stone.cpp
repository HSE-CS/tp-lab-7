//  Copyright 2021 Nikita Naumov

#include "../include/stone.h"
#include "../include/cell.h"

void Stone::live() {
    if (lifespan <= 0) {
        this->cell->killMe();
    }
    --(this->lifespan);
}
void Stone::setType() {
    this->type = ObjType::STONE;
}

void Coral::live() {
    if (lifespan >= 36) {
        int x = this->cell->getX(), y = this->cell->getY();
        Ocean* thisOcean = this->cell->getCurrentOcean();
        std::vector<Cell> nearCells = thisOcean->getNearbyCells(x,y);
        for (auto cell : nearCells) {
            if (cell.isFree()) {
                Pair p = {cell.getX(),cell.getY()};
                Cell* newCell = new Cell(p, thisOcean);
                thisOcean->setObjectToCell(dynamic_cast<Object*>(new Coral(newCell)),cell.getX(), cell.getY());
                Object* objToAdd = thisOcean->returnByCoords(cell.getX(), cell.getY());
                thisOcean->addToVector(objToAdd);
                lifespan = 0;
            }
        }
        ++lifespan;
    } else {
        ++lifespan;
    }
}

void Coral::setType() {
    this->type = ObjType::CORAL;
}