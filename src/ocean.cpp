// Copyright 2021 Kriss Egorova


#include <stdlib.h>
#include <unistd.h>
#include <ctime>
#include <cstdlib>


#include "ocean.h"

Ocean::Ocean(Pair newSize) {
  size = newSize;
  cells = new Cell*[size.x];
  for (int i = 0; i < size.x; i++) {
    cells[i] = new Cell[size.y];
    for (int j = 0; j < size.y; j++) {
      cells[i][j].init({i, j}, this);
    }
  }
}

Ocean::~Ocean() {
  for (unsigned i = 0; i < size.x; i++)
    delete [] cells[i];
  delete [] cells;
}

void Ocean::print() const {
  std::cout << "\x1b[36m";
  for (unsigned i = 0; i < size.x; i++) {
    for (unsigned j = 0; j < size.y; j++) {
      std::string cell_v = "";

      if (cells[i][j].obj == nullptr)
          cell_v = "~~";
      else if (cells[i][j].obj->getObjType() == ObjType::CORAL)
        cell_v = "\U0001F5FF";
      else if (cells[i][j].obj->getObjType() == ObjType::PREY)
        cell_v = "\U0001F419";
      else if (cells[i][j].obj->getObjType() == ObjType::PREDATOR)
        cell_v = "\U0001F988";

      std::cout << cell_v;
    }
    std::cout << std::endl;
  }
  std::cout << "\x1b[0m";
  std::cout << std::endl;
}

void Ocean::createInitial(float preyPercent,
                          float predatorPercent,
                          float stonePercent,
                          unsigned* seed) {
  unsigned preyNum =
  static_cast<unsigned>(preyPercent * size.x * size.y);
  unsigned predatorNum =
  static_cast<unsigned>(predatorPercent * size.x * size.y);
  unsigned stoneNum =
  static_cast<unsigned>(stonePercent * size.x * size.y);
  // spawn preys
  for (unsigned i = 0; i < preyNum; i++) {
    while (true) {
      unsigned x = rand_r(seed) % size.x;
      unsigned y = rand_r(seed) % size.y;
      if (cells[x][y].obj == nullptr) {
        Prey* newPrey = new Prey(&cells[x][y]);
        cells[x][y].obj = newPrey;
        stuff.push_back(newPrey);
        break;
      }
    }
  }
  // spawn Predators
  for (unsigned i = 0; i < predatorNum; i++) {
    while (true) {
      unsigned x = rand_r(seed) % size.x;
      unsigned y = rand_r(seed) % size.y;
      if (cells[x][y].obj == nullptr) {
        Predator* newPredator = new Predator(&cells[x][y]);
        cells[x][y].obj = newPredator;
        stuff.push_back(newPredator);
        break;
      }
    }
  }
  // spawn Stones
  for (unsigned i = 0; i < stoneNum; i++) {
    while (true) {
      unsigned x = rand_r(seed) % size.x;
      unsigned y = rand_r(seed) % size.y;
      if (cells[x][y].obj == nullptr) {
        Stone* newStone = new Stone(&cells[x][y]);
        cells[x][y].obj = newStone;
        stuff.push_back(newStone);
        break;
      }
    }
  }
}

void Ocean::run() {
  sleep(2);
  while (true) {
    for (Object* obj : stuff) {
      if (obj == nullptr || obj->isDead())
        continue;
      obj->live();
    }
    deleteCandidates();
    print();
    sleep(1);
  }
}

void Ocean::addObject(Object *newObject) {
  stuff.push_back(newObject);
}

void Ocean::deleteObject(Object* oldObject) {
  stuff.remove(oldObject);
  delete oldObject;
}
void Ocean::addDeleteCandidate(Object* oldObject) {
  deleteCandidatesList.push_back(oldObject);
}

void Ocean::deleteCandidates() {
  for (Object* obj : deleteCandidatesList)
    deleteObject(obj);
  deleteCandidatesList.clear();
}

Cell* Ocean::getCell(Pair crd) {
  if (crd.x < 0 || crd.x >= size.x || crd.y < 0 || crd.y >= size.y)
    return nullptr;
  return &cells[crd.x][crd.y];
}

Cell* Ocean::find(Cell *centerCell, bool (*condition)(Cell*)) {
  Pair crd = centerCell->crd;
  std::vector<Cell*> availableCells;

  // upper row
  if (crd.x > 0) {
    if (condition(getCell({crd.x-1, crd.y})))
      availableCells.push_back(getCell({crd.x-1, crd.y}));

    if (crd.y > 0 && condition(getCell({crd.x-1, crd.y-1})))
      availableCells.push_back(getCell({crd.x-1, crd.y-1}));

    if (crd.y + 1 < size.y && condition(getCell({crd.x-1, crd.y+1})))
      availableCells.push_back(getCell({crd.x-1, crd.y+1}));
  }
  // lower row
  if (crd.x + 1 < size.x) {
    if (condition(getCell({crd.x+1, crd.y})))
      availableCells.push_back(getCell({crd.x+1, crd.y}));

    if (crd.y > 0 && condition(getCell({crd.x+1, crd.y-1})))
      availableCells.push_back(getCell({crd.x+1, crd.y-1}));

    if (crd.y + 1 < size.y && condition(getCell({crd.x+1, crd.y+1})))
      availableCells.push_back(getCell({crd.x+1, crd.y+1}));
  }
  // left
  if (crd.y > 0 && condition(getCell({crd.x, crd.y - 1})))
    availableCells.push_back(getCell({crd.x, crd.y - 1}));
  // right
  if (crd.y + 1 < size.y && condition(getCell({crd.x, crd.y + 1})))
    availableCells.push_back(getCell({crd.x, crd.y + 1}));

  if (availableCells.size() == 0)
    return nullptr;

  unsigned seed = time(0);
  unsigned* seed_p = &seed;
  unsigned random_choice = rand_r(seed_p) % availableCells.size();
  return availableCells[random_choice];
}

bool Ocean::isPreyCell(Cell* checkCell) {
  if (checkCell->obj == nullptr)
    return false;
  else if (checkCell->obj->getObjType() == ObjType::PREY)
    return true;
  else
    return false;
}

bool Ocean::isEmptyCell(Cell *checkCell) {
  return checkCell->isEmpty();
}

Cell* Ocean::findPrey(Cell *centerCell) {
  return find(centerCell, Ocean::isPreyCell);
}

Cell* Ocean::findEmpty(Cell *centerCell) {
  return find(centerCell, Ocean::isEmptyCell);
}