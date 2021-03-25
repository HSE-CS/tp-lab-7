// Copyright 2021 Dumarevskaya
#include "Predator.h"
#include "Cell.h"

void Predator::eat() {
  Prey* victim = new Prey(cell->findPreyAround());
  if (victim == nullptr) {
    hungry = true;
  } else {
    victim->getCell()->killMe();
    hungry = false;
  }
}

void Predator::live() {
  int timeHungry = 0;
  if (lifeTime-- != 0 && !hungry) {
    eat();
    if (!hungry) {
      timeHungry++;
      hungry = false;
    }
    if (lifeTime % timeToReproduce == 0 && hungry) {
      reproduce();
    } else {
      move();
    }
    if (timeHungry == 3)
      hungry = true;
  } else {
    cell->killMe();
  }
}
