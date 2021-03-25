//Copyright GN 2021
#include "../include/predator.h"
#include "../include/Object.h"
#include "../include/prey.h"

void Predator::setObjectType() { this->objType = 3; }
void Predator::setCell(Cell* c) { this->cell = c; }
void Predator::init(Cell* c) {
  this->setObjectType();
  this->setCell(c);
}
void Predator::reproduction() {
  Pair p = this->cell->getCoordinates();
  Pair p_1 = this->cell->getCoordinates();
  int flag = 0;
  for (int x = p.x_cord-1; x <= p.x_cord + 1; x++) {
    if (flag == 1) {
      break;
    }
    for (int y = p.y_cord-1; y <= p.y_cord + 1; y++) {
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
      Cell* cell_ = this->cell->getOcean()->getCell(p);
      if (cell_->getObject() == nullptr) {
        flag = 1;
        Cell* cell__ = this->cell->getOcean()->getCell(p);
        Predator* new_predator = new Predator;
        new_predator->init(cell__);
        cell__->setObject(new_predator);
        this->cell->getOcean()->addObject(new_predator);
      }
      p = p_1;
    }
  }
}
void Predator::printObject() { std::cout << PREDATOR_N; }
int Predator::hunting() {
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
      if (new_cell->getObject() != nullptr) {
        if (new_cell->getObject()->getObjectINT() == 2) {
          flag = 1;
          Cell* cell_ = this->cell->getOcean()->getCell(p);
          cell_->delObj();
        }
      }
      p = p_1;
    }
  }
  return flag;
}
void Predator::live() {
  if (time_of_life <= 10 && this->getTimeOfHunger() <= 5) {
    int hunting = this->hunting();
    this->move();
    if (time_of_life % 4 == 0) {
      this->reproduction();
    }
    time_of_life++;
    if (hunting == 0) {
      time_of_hunger++;
    } else {
      time_of_hunger = 0;
    }
  } else {
    this->die();
  }
}

void Predator::move() {
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
      if ((x < 0 || x > N - 1) || (y < 0 || y > M - 1)) {
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

void Predator::die() {
  this->cell->killMe(this);
  this->objType = -1;
}
int Predator::getObjectINT() { return objType; }
int Predator::getTimeOfHunger() { return this->time_of_hunger; }
char Predator::getObjectChar() { return PREDATOR_N; }
