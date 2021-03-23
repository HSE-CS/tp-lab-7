// Copyright <Roman Balayan> @ 2021

#include "../include/prey.h"
#include "../include/common.h"
#include "../include/cell.h"
#include "../include/ocean.h"

Prey::Prey(std::weak_ptr<Cell> cell) : Object(cell) {
    this->type = ObjType::PREY;
    this->health = Constants::preyHealth;
}

void Prey::live() {
    if (--health <= 0) {
        this->cell.lock()->killMe();
        return;
    }
    auto neighbourCell = this->cell.lock()->getNeighbour();
    if (!neighbourCell)
        return;
    if (neighbourCell->getObjType() == ObjType::EMPTY) {
        this->moveTo(neighbourCell);
    } else if (neighbourCell->getObjType() == ObjType::PREY) {
        this->reproduction();
    } else if (neighbourCell->getObjType() == ObjType::PREDATOR) {
        this->cell.lock()->killMe();
    }
    //  in the case of stone do nothing
}

void Prey::reproduction() {
    std::shared_ptr<Cell> emptyCell =
        this->cell.lock()->getOcean()->getEmptyCellAround(this->cell.lock());
    if (!emptyCell) {
        int casino = rand() % 100; // NOLINT [build/c++11]
        if (casino >= 70) {
            emptyCell = this->cell.lock()->getOcean()->getEmptyCell();
        }
    }
    if (emptyCell) {
        std::shared_ptr<Object> child = std::make_shared<Prey>(emptyCell);
        emptyCell->setObject(child);
        this->cell.lock()->getOcean()->addObject(child);
    }
}
