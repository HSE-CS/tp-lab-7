// Copyright 26.03.21 DenisKabanov

#include <predator.h>

Predator::Predator(Cell *cell) : Prey(cell) {
  color = RED;
  timeToDie = PREDATORLIFECYCLE;
  timeToReproduce = PREDATORREPRODUCECYCLE;
}

void Predator::live() {
  if (timeToDie-- <= 0) {
    cell->killMe();
    return;
  }

  Cell *newCell = cell->findCellWithPrey();
  if (newCell) {
    newCell->killMe();
    cell->setObject(nullptr);
    cell = newCell;
    cell->setObject(this);
    timeToDie += 3;
  } else {
    newCell = cell->findCellAround();
    if (newCell) {
      cell->setObject(nullptr);
      cell = newCell;
      cell->setObject(this);
    }
  }
  reproduce();
}

void Predator::reproduce() {
  if (timeToReproduce-- <= 0) {
    Cell *foundedCell = cell->findCellAround();
    if (foundedCell) {
      auto *newPredator = new Predator(foundedCell);
      foundedCell->setObject(newPredator);
      foundedCell->GetOcean()->addObject(newPredator);
		}
  }
}
