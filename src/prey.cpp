// Copyright 2020 S. BOR

#include "../include/prey.h"
#include <iostream>
#include <exception>

void Prey::step() {
  for (int i = currentCell->coords.x - 1; i <= currentCell->coords.x + 1; i++)
    for (int j = currentCell->coords.y - 1;
     j <= currentCell->coords.y + 1; j++) {
      try {
          if (i >= 0 && i < N && j >= 0 && j < M) {
            if (currentCell->ocean->cells[i][j]->getObject() == nullptr) {
              currentCell->setObject(nullptr);
              currentCell->ocean->cells[i][j]->setObject(this);
              return;
            }
          }
      }
      catch (std::exception e) { }
    }
}

void Prey::createNew() {
  for (int i = currentCell->coords.x - 1; i <= currentCell->coords.x + 1; i++)
    for (int j = currentCell->coords.y - 1;
     j <= currentCell->coords.y + 1; j++) {
      try {
        if (i >= 0 && i < N && j >= 0 && j < M) {
          if (currentCell->ocean->cells[i][j]->getObject() == nullptr) {
            currentCell->ocean->cells[i][j]->setObject(new Prey);
            return;
          }
        }
      }
      catch (std::exception e) { }
    }
}

void Prey::nextTurn() {
  if (numberOfTurns == 0) {
    currentCell->setObject(nullptr);
    delete this;
    return;
  }
  step();
  if (numberOfTurns == 6 || numberOfTurns == 3) {
    createNew();
  }
  this->numberOfTurns--;
}

void Prey::printSymb() {
  std::cout << "P";
}
