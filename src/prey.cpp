// Copyright GN 2021
#include "prey.h"
#include "object.h"

void Prey::setObjectType() { this->objType = 2; }
void Prey::setCell(Cell* c) { this->cell = c; }
void Prey::init(Cell* c) {
  this->setObjectType();
  this->setCell(c);
}
void Prey::reproduction() {
  Pair p = this->cell->getCoordinates();
  Pair p_1 = this->cell->getCoordinates();
  int flag = 0;
  for (int x = p.x_cord - 1; x <= p.x_cord + 1; x++) {
    if (flag == 1) {
      break;
    }
    for (int y = p.y_cord - 1; y <= p.y_cord + 1; y++) {
      if (flag == 1) {
        break;
      }
      p.x_cord = x;
      p.y_cord = y;
      if ((p.x_cord < 0 || p.x_cord > N - 1) ||
          (p.y_cord < 0 || p.y_cord > M - 1)) {
        p.x_cord = p_1.x_cord;
        p.y_cord = p_1.y_cord;
        continue;
      }
      Cell* now_cell = this->cell->getOcean()->getCell(p);
      if (now_cell->getObject() == nullptr) {
        flag = 1;
        Cell* now_cell = this->cell->getOcean()->getCell(p);
        Prey* new_fish = new Prey;
        new_fish->init(now_cell);
        now_cell->setObject(new_fish);
        this->cell->getOcean()->addObject(new_fish);
      }
      p = p_1;
    }
  }
}
void Prey::move() {
  Pair p = this->cell->getCoordinates();
  Pair p_1 = this->cell->getCoordinates();
  int flag = 0;
  for (int x = p.x_cord - 1; x <= p.x_cord + 1; x++) {
    if (flag == 1) {
      break;
    }
    for (int y = p.y_cord - 1; y <= p.y_cord + 1; y++) {
      if (flag == 1) {
        break;
      }
      p.x_cord = x;
      p.y_cord = y;
      if ((x < 0 || x > N - 1) ||
          (y < 0 || y > M - 1)) {
        p.x_cord = p_1.x_cord;
        p.y_cord = p_1.y_cord;
        continue;
      }
      Cell* new_cell = this->cell->getOcean()->getCell(p);
      if (new_cell->getObject() == nullptr) {
        flag = 1;
        new_cell->setObject(this);
        this->cell->delObj();
        this->setCell(new_cell);
        break;
      }
      p = p_1;
    }
  }
}
void Prey::live() {
  if (time_of_life <= 10) {
    this->move();
    if (time_of_life % 5 == 0) {
      this->reproduction();
    }
    time_of_life++;
  } else {
    this->die();
  }
}
void Prey::die() {
  this->cell->killMe(this);
  this->objType = -1;
}
int Prey::getObjectINT() { return objType; }
char Prey::getObjectChar() { return PREY_N; }
void Prey::printObject() { std::cout << PREY_N; }
