// Copyright 2021 Egor Buzanov

#include "../include/predator.h"

void Predator::live() {
  ++age;
  --feed_num;
  if (age <= lifetime && feed_num > 0) {
    if (age >= reproduction && feed_num >= lifetime / 10) {
      reproduction += reproduction;
      cell->getOcean()->AddObject(new Prey());
    }
    cell->getOcean()->objectStep(cell);
  } else {
    cell->killMe();
  }
}

void Predator::refreshFeed() { feed_num = lifetime / 5; }
