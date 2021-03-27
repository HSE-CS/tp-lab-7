// Copyright 2021 ArinaMonicheva

#include "../include/predator.h"

Predator::Predator(Cell* newCell) : Prey(newCell) {
  type = ObjType::PREDATOR;
  reproduceCycle = REPRODUCE;
}

void Predator::live() {
  bool moved = false;
  Cell* prev = inCell;
  if (livesCount > 1) {
    moved = tryToMove();
  } else if (reproduceCycle == 1) {
    reproduceCycle = REPRODUCE;
    inCell->freeMe();
    Predator* child = new Predator(inCell);
    inCell->getOcean()->addToBiosphere(child);
    return;
  }

  if (moved && reproduceCycle == 1) {
    reproduceCycle = REPRODUCE;
    Predator* child = new Predator(prev);
    prev->getOcean()->addToBiosphere(child);
  } else {
    reproduceCycle--;
  }

  livesCount--;
}

bool Predator::tryToMove() {
  time_t* n = NULL;
  unsigned* seed = 0;
  srand(time(n));

  coords cds = inCell->getCoords();
  int w = inCell->getOcean()->getWidth();
  int h = inCell->getOcean()->getHeight();
  std::vector <coords> availableSteps = { {cds.x, (cds.y + 1) % h},
   {(cds.x - 1) % w, cds.y}, {(cds.x + 1) % w, cds.y},
   {cds.x, (cds.y - 1) % h} };
  int attempt = 4;
  int step = rand_r(seed) % attempt;
  int eated = inCell->getOcean()->movement(cds, availableSteps[step], this);

  while (!eated) {
    availableSteps.erase(availableSteps.begin() + step);
    attempt--;
    if (!attempt) {
      break;
    }
    step = rand_r(seed) % attempt;
    eated = inCell->getOcean()->movement(cds, availableSteps[step], this);
  }

  if (eated == 2) {
    hunger = HUNGER;
  } else if (hunger == 1) {
    livesCount = 1;
  } else {
    hunger--;
  }

  return attempt;
}
