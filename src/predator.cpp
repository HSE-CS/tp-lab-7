// Copyright 2021 Schenikova

#include "predator.h"
// void Predator::eat() {
//   for (size_t i = this->cell->coords.x - 1; i <= this->cell->coords.x + 1; i++) {
//     for (size_t j = this->cell->coords.y - 1; j < this->cell->coords.y + 1; j++) {
//       try {
//         if (this->cell->ocean->cells[i][j].getObject()->IsPrey()) {
//           this->cell->setObject(nullptr);
//           this->cell->ocean->cells[i][j].killMe();
//           this->cell->ocean->cells[i][j].setObject(this);
//           isHungry = false;
//           break;
//         }
//       }
//       catch(const std::exception& e) {
//         // std::cerr << e.what() << '\n';
//       }
//     }
//   }
// }


void Predator::step() {
  int x = this->cell->coords.x;
  int y = this->cell->coords.y;
   for (int i = x - 1; i <= x + 1; i++) {
    for (int j = y - 1; j <= y + 1; j++) {
      try {
        if (i >= 0 && i < N && j >= 0 && j < M)
        if (this->cell->ocean->cells[i][j].getObject() != nullptr)
        if (this->cell->ocean->cells[i][j].getObject()->IsPrey()) {
          this->cell->setObject(nullptr);
          this->cell->ocean->cells[i][j].killMe();
          this->cell->ocean->cells[i][j].setObject(this);
          isHungry = false;
          return;
        }
      }
      catch(const std::exception& e) {
        // std::cerr << e.what() << '\n';
      }
    }
  }
  for (int i = x - 1; i <= x + 1; i++) {
    for (int j = y - 1; j <= y + 1; j++) {
      try {
        if (i >= 0 && i < N && j >= 0 && j < M)
        if (this->cell->ocean->cells[i][j].getObject() == nullptr) {
          this->cell->setObject(nullptr);
          this->cell->ocean->cells[i][j].setObject(this);
          return;
        }
      }
      catch(const std::exception& e) {
        // std::cerr << e.what() << '\n';
      }
    }
  }
}

void Predator::create(){
  int x = this->cell->coords.x;
  int y = this->cell->coords.y;
  for (size_t i = x - 1; i <= x + 1; i++) {
    for (size_t j = y - 1; j <= y + 1; j++) {
      try {
        if (this->cell->ocean->cells[i][j].getObject() == nullptr) {
          Predator* tmp = new Predator;
          this->cell->ocean->cells[i][j].setObject(tmp);
          return;
        }
      }
      catch(const std::exception& e) {
      }
    }
  }
}

void Predator::live() {
  isHungry = true;
  if(!this->numberOfLive) {
    this->cell->killMe();
    return;
  }
  this->numberOfLive--;
  step();
  // eat();
  if (!isHungry)
    create();
}

void Predator::printInfo() {
  std::cout << "f";
}
