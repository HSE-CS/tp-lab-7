// Copyright 2020 S. BOR

#include "predator.h"
#include <iostream>
#include <exception>

bool Predator::tryEat() {
  for (int i = currentCell->coords.x - 1; i <= currentCell->coords.x + 1; i++)
    for (int j = currentCell->coords.y - 1; j <= currentCell->coords.y + 1;
    j++) {
      try {
        if (i >= 0 && i < N && j >= 0 && j < M) {
          if (currentCell->ocean->cells[i][j]->getObject() != nullptr) {
            if (currentCell->ocean->cells[i][j]->getObject()->isPrey()) {
              delete currentCell->ocean->cells[i][j]->getObject();
              currentCell->ocean->cells[i][j]->setObject(nullptr);
              return true;
            }
          }
        }
      }
      catch (std::exception e) { }
    }
    return false;
}

void Predator::step() {
  for (int i = currentCell->coords.x - 1; i <= currentCell->coords.x + 1; i++)
    for (int j = currentCell->coords.y - 1; j <= currentCell->coords.y + 1; j++) {
      try {
        if (i >= 0 && i < N && j >= 0 && j < M)
          if (currentCell->ocean->cells[i][j]->getObject() == nullptr) {
            currentCell->setObject(nullptr);
            currentCell->ocean->cells[i][j]->setObject(this);
            return;
        }
      }
      catch (std::exception e) { }
    }
}

void Predator::createNew() {
  for (int i = currentCell->coords.x - 1; i <= currentCell->coords.x + 1; i++)
    for (int j = currentCell->coords.y - 1; j <= currentCell->coords.y + 1; j++) {
      try {
        if (i >= 0 && i < N && j >= 0 && j < M)
          if (currentCell->ocean->cells[i][j]->getObject() == nullptr) {
            currentCell->ocean->cells[i][j]->setObject(new Predator);
            return;
          }
      }
      catch (std::exception e) { }
    }
}

void Predator::nextTurn() {
  if (numberOfTurns == 0) {
    currentCell->setObject(nullptr);
    delete this;
    return;
  }
  step();
  if (isEat = tryEat())
    createNew();
  this->numberOfTurns--;
}

void Predator::printSymb() {
  std::cout << "H";
}
