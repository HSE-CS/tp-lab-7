// Copyright 2021 VadMack

#include <prey.h>
void Prey::live() {
  if (timeToDie-- > 0) {
    Cell *newCell = cell->findCellAround();
    if (newCell) {
      cell->setObject(nullptr);
      cell = newCell;
      cell->setObject(this);
    }
    reproduce();
  } else {
    cell->killMe();
  }
}

Prey::Prey(Cell *cell) : Object(cell) {
  color = PINK;
  timeToDie = PREYLIFECYCLE;
  timeToReproduce = PREYREPRODUCECYCLE;
}

void Prey::reproduce() {
  if (timeToReproduce-- <= 0) {
    Cell *foundedCell = cell->findCellAround();
    if (foundedCell) {
      Prey *newPrey = new Prey(foundedCell);
      foundedCell->setObject(newPrey);
      foundedCell->GetOcean()->addObject(newPrey);
    }
  }
}
size_t Prey::GetTimeToDie() const {
  return timeToDie;
}


