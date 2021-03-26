#include "../include/prey.h"
#include "../include/cell.h"


Prey::Prey(Cell *cell_, size_t lifeTime_, size_t breedCoolDawn_)
    : Object(cell_, ObjType::PREY) {
  lifeTime = lifeTime_;
  breedTime = breedCoolDawn_;
  breedCoolDawn = breedCoolDawn_;
}

void Prey::live() {
  if (lifeTime == 0) {
    death();
    return;
  }
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
  --lifeTime;
}

void Prey::breedingTime() {
  std::vector<Cell*> space(cell->getOcean()->emptyCells(cell->getCoord()));
  if (!space.size()) return;
  Prey *offspring = new Prey(space[std::rand() % space.size()], lifeTime,
                            breedCoolDawn);
  cell->getOcean()->pushObject(offspring);
}

void Prey::death() { cell->killMe(); }

void Prey::move() {
  std::vector<Cell*> space(cell->getOcean()->emptyCells(cell->getCoord()));
  if (space.size()) {
    this->cell->setObject(nullptr);
    int k = std::rand() % space.size();
    space[k]->setObject(this);
    setCell(space[k]);
  }
}
