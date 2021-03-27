// Copyright 2021 Lab_7 TiNa
#include "predator.h"
#include "cell.h"

Predator::Predator(Cell* cell) : Prey(cell) {
  this->type = PREDATOR;
  time_of_life = 7;
  counter_of_eaten = 0;
}

void Predator::live() {
  if (time_of_life > 0) {
    Cell* predC = this->cell->eat();
    if (predC) {
      counter_of_eaten += 1;
      predC->killMe();
      cell->setObject(nullptr);
      cell = predC;
      cell->setObject(this);
      time_of_life += 1;
    } else {
      predC = cell->find();
      if (predC) {
        cell->setObject(nullptr);
        cell = predC;
        cell->setObject(this);
      }
    }
    reproduction();
    time_of_life--;
  } else {
    cell->killMe();
  }
}

void Predator::reproduction() {
  if (counter_of_eaten >= 2) {
    Cell* predC = cell->find();
    if (predC) {
      Object* pred = new Predator(predC);
      predC->setObject(pred);
      predC->getOcean()->addObjects(pred);
    }
    counter_of_eaten -= 2;
  }
}
