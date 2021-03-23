// Copyright <Roman Balayan> @ 2021

#include "../include/predator.h"
#include "../include/common.h"
#include "../include/cell.h"
#include "../include/ocean.h"

Predator::Predator(std::weak_ptr<Cell> cell) : Prey(cell) {
    this->type = ObjType::PREDATOR;
    this->health = Constants::predatorHealth;
}

void Predator::live() {
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
        this->eat();
        neighbourCell->killMe();
        this->moveTo(neighbourCell);
    } else if (neighbourCell->getObjType() == ObjType::PREDATOR) {
        this->reproduction();
    }
    //  in the case of stone do nothing
}

void Predator::reproduction() {
    std::shared_ptr<Cell> emptyCell =
          this->cell.lock()->getOcean()->getEmptyCellAround(this->cell.lock());
    if (!emptyCell) {
        int casino = rand() % 100;
        if (casino >= 90) {
            emptyCell = this->cell.lock()->getOcean()->getEmptyCell();
        }
    }
    if (emptyCell) {
        std::shared_ptr<Object> child = std::make_shared<Predator>(emptyCell);
        emptyCell->setObject(child);
        this->cell.lock()->getOcean()->addObject(child);
    }
}

void Predator::eat() {
    this->health += 2;
    this->health = this->health > Constants::predatorHealth ?
        Constants::predatorHealth : this->health;
}
