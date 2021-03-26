// Copyright 2021 Galex

#include <cell.h>
#include <utility>

Cell::Cell(Pair p, Ocean *o) {
  this->coord.x = p.x;
  this->coord.y = p.y;
  this->object = nullptr;
  this->ocean = o;
}
void Cell::setObject(Object *obj) {
  this->object = obj;
}
bool Cell::isFree() {
  if (this->object != nullptr) {
    return false;
  } else {
    return true;
  }
}
Object *Cell::getObject() {
  return this->object;
}
Cell *Cell::getRandNeighbourCell() {
  int neighbour = std::rand() % 8;
  return checkNeighbour(neighbour);
}
Cell *Cell::getNeighbourCell() {
  for (int i = 0; i < 8; ++i) {
    Cell *newCell = checkNeighbour(i);
    if (newCell) {
      return newCell;
    }
  }
  return nullptr;
}
Cell *Cell::checkNeighbour(int neighbour) {
  switch (neighbour) {
    case 0:
      if (this->coord.x != 0 &&
          this->coord.y != 0 &&
          this->ocean->cells[this->coord.x - 1][this->coord.y - 1]->isFree())
        return this->ocean->cells[this->coord.x - 1][this->coord.y - 1];
      else
        return nullptr;
    case 1:
      if (this->coord.x != 0 &&
          this->ocean->cells[this->coord.x - 1][this->coord.y]->isFree())
        return this->ocean->cells[this->coord.x - 1][this->coord.y];
      else
        return nullptr;
    case 2:
      if (this->coord.x != 0 &&
          this->coord.y != COLUMNS - 1 &&
          this->ocean->cells[this->coord.x - 1][this->coord.y + 1]->isFree())
        return this->ocean->cells[this->coord.x - 1][this->coord.y + 1];
      else
        return nullptr;
    case 3:
      if (this->coord.y != 0 &&
          this->ocean->cells[this->coord.x][this->coord.y - 1]->isFree())
        return this->ocean->cells[this->coord.x][this->coord.y - 1];
      else
        return nullptr;
    case 4:
      if (this->coord.y != COLUMNS - 1 &&
          this->ocean->cells[this->coord.x][this->coord.y + 1]->isFree())
        return this->ocean->cells[this->coord.x][this->coord.y + 1];
      else
        return nullptr;
    case 5:
      if (this->coord.x != ROWS - 1 &&
          this->coord.y != 0 &&
          this->ocean->cells[this->coord.x + 1][this->coord.y - 1]->isFree())
        return this->ocean->cells[this->coord.x + 1][this->coord.y - 1];
      else
        return nullptr;
    case 6:
      if (this->coord.x != ROWS - 1 &&
          this->ocean->cells[this->coord.x + 1][this->coord.y]->isFree())
        return this->ocean->cells[this->coord.x + 1][this->coord.y];
      else
        return nullptr;
    case 7:
      if (this->coord.x != ROWS - 1 && this->coord.y != COLUMNS - 1 &&
          this->ocean->cells[this->coord.x + 1][this->coord.y + 1]->isFree())
        return this->ocean->cells[this->coord.x + 1][this->coord.y + 1];
      else
        return nullptr;
  }
  return nullptr;
}
void Cell::kill() {
  this->ocean->removeObject(this->getObject());
  switch (this->getObject()->getType()) {
    case TYPE::PREY: this->ocean->numOfPreys--;
    case TYPE::PREDATOR: this->ocean->numOfPredators--;
  }
  delete this->object;
  this->setObject(nullptr);
}
Cell *Cell::getRandPreyNeighbourCell() {
  int neighbour = std::rand() % 8;
  switch (neighbour) {
    case 0:
      if (this->coord.x != 0 && this->coord.y != 0 &&
          (this->ocean->cells[this->coord.x - 1][this->coord.y - 1]->isFree() ||
              this->ocean->cells[this->coord.x - 1][this->coord.y - 1]
                  ->getObject()->type_ == TYPE::PREY))
        return this->ocean->cells[this->coord.x - 1][this->coord.y - 1];
      else
        return nullptr;
    case 1:
      if (this->coord.x != 0 &&
          (this->ocean->cells[this->coord.x - 1][this->coord.y]->isFree() ||
              this->ocean->cells[this->coord.x - 1][this->coord.y]
                  ->getObject()->type_ == TYPE::PREY))
        return this->ocean->cells[this->coord.x - 1][this->coord.y];
      else
        return nullptr;
    case 2:
      if (this->coord.x != 0 && this->coord.y != COLUMNS - 1 &&
          (this->ocean->cells[this->coord.x - 1][this->coord.y + 1]->isFree() ||
              this->ocean->cells[this->coord.x - 1][this->coord.y + 1]
                  ->getObject()->type_ == TYPE::PREY))
        return this->ocean->cells[this->coord.x - 1][this->coord.y + 1];
      else
        return nullptr;
    case 3:
      if (this->coord.y != 0 &&
          (this->ocean->cells[this->coord.x][this->coord.y - 1]->isFree() ||
              this->ocean->cells[this->coord.x][this->coord.y - 1]
                  ->getObject()->type_ == TYPE::PREY))
        return this->ocean->cells[this->coord.x][this->coord.y - 1];
      else
        return nullptr;
    case 4:
      if (this->coord.y != COLUMNS - 1 &&
          (this->ocean->cells[this->coord.x][this->coord.y + 1]->isFree() ||
              this->ocean->cells[this->coord.x][this->coord.y + 1]
                  ->getObject()->type_ == TYPE::PREY))
        return this->ocean->cells[this->coord.x][this->coord.y + 1];
      else
        return nullptr;
    case 5:
      if (this->coord.x != ROWS - 1 && this->coord.y != 0 &&
          (this->ocean->cells[this->coord.x + 1][this->coord.y - 1]->isFree() ||
              this->ocean->cells[this->coord.x + 1][this->coord.y - 1]
                  ->getObject()->type_ == TYPE::PREY))
        return this->ocean->cells[this->coord.x + 1][this->coord.y - 1];
      else
        return nullptr;
    case 6:
      if (this->coord.x != ROWS - 1 &&
          (this->ocean->cells[this->coord.x + 1][this->coord.y]->isFree() ||
              this->ocean->cells[this->coord.x + 1][this->coord.y]
                  ->getObject()->type_ == TYPE::PREY))
        return this->ocean->cells[this->coord.x + 1][this->coord.y];
      else
        return nullptr;
    case 7:
      if (this->coord.x != ROWS - 1 && this->coord.y != COLUMNS - 1 &&
          (this->ocean->cells[this->coord.x + 1][this->coord.y + 1]->isFree() ||
              this->ocean->cells[this->coord.x + 1][this->coord.y + 1]
                  ->getObject()->type_ == TYPE::PREY))
        return this->ocean->cells[this->coord.x + 1][this->coord.y + 1];
      else
        return nullptr;
  }
}
Ocean *Cell::getOcean() {
  return this->ocean;
}
