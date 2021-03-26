// Copyright 2021 ArinaMonicheva

#include "prey.h"

Prey::Prey(Cell* newCell) : Stone(newCell) {
  type = ObjType::PREY;
  reproduceCycle = P_REPRODUCE;
}

void Prey::live() {
  bool moved = false;
  Cell* prev = inCell;
  if (livesCount > 1) { 
    moved = tryToMove();
  } 
  else if (reproduceCycle == 1) {
    reproduceCycle = P_REPRODUCE;
    inCell->freeMe();
    Prey* child = new Prey(inCell);
    inCell->getOcean()->addToBiosphere(child);
    return;
  }

  if (moved && reproduceCycle == 1) {
    reproduceCycle = P_REPRODUCE;
    Prey* child = new Prey(prev);
    prev->getOcean()->addToBiosphere(child);
  } else {
    reproduceCycle--;
  }

  livesCount--;
}

bool Prey::tryToMove() {  // randfunc
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
  int step = rand() % attempt;

  while (!inCell->getOcean()->movement(cds, availableSteps[step], this)) {
    availableSteps.erase(availableSteps.begin() + step);
    attempt--;
    if (!attempt) {
      break;
    }
    step = rand() % attempt;
  }

  return attempt;
}

void Prey::die() {
  inCell->freeMe();
  livesCount = 0;
}
