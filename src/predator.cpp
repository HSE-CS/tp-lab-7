#include "../include/predator.h"
#include "../include/cell.h"

Predator::Predator(Cell* cell_, size_t lifeTime_, size_t breedCoolDawn_,
                   size_t _hungerLimit) : Object(cell_, ObjType::PREDATOR){
  lifeTime = lifeTime_;
  breedCoolDawn = breedCoolDawn_;
  breedTime = breedCoolDawn_;
  hungerLimit = _hungerLimit;
  hunger = _hungerLimit;
  cell->setObject(this);
}

void Predator::live() {
  if (lifeTime == 0 || hunger == 0) {
    death();
    return;
  }
  --hunger;
  --lifeTime;
  if (breedTime == 0) {
    Pair old(getCoord());
    breedingTime();
    breedTime = breedCoolDawn;
  } else {
    if (breedTime != 0) {
      --breedTime;
    }
  }
  move();
}

void Predator::breedingTime() {
  std::vector<Cell*> space(cell->getOcean()->emptyCells(cell->getCoord()));
  if (!space.size()) return;
  Predator* offspring = new Predator(space[std::rand() % space.size()],
                                     lifeTime, breedCoolDawn, hungerLimit);
  cell->getOcean()->pushObject(offspring);
}

void Predator::death() { cell->killMe(); }

void Predator::move() {
  std::vector<Cell*> food(cell->getOcean()->preyCells(cell->getCoord()));
  if (food.size() != 0) {
    int k = std::rand() % food.size();
    this->cell->setObject(nullptr);
    food[k]->killMe();
    food[k]->setObject(this);
    setCell(food[k]);
    hunger = hungerLimit;
    return;
  }
  std::vector<Cell*> space(cell->getOcean()->emptyCells(cell->getCoord()));
  if (space.size()) {
    this->cell->setObject(nullptr);
    int k = std::rand() % space.size();
    space[k]->setObject(this);
    setCell(space[k]);
  }
}
