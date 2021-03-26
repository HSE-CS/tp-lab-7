// Copyright 2021 Kuznetsov Mikhail

#include "ocean.h"


Ocean::Ocean(unsigned int _height, unsigned int _width) :
  height(_height), width(_width) {
  cells.resize(_height);
  for (unsigned int i = 0; i < _height; i++) {
    cells[i].resize(_width);
    for (unsigned int j = 0; j < _width; j++) {
      int temperature = 0;
      if (!i && !j) {
        temperature = std::rand() % 71 - 35;
      } else {
        auto area = cells[i][j]->getArea();
        unsigned int cnt = 0;
        int sum = 0;
        for (auto c : area) {
          if (nullptr != cells[c.first][c.second]) {
            sum += cells[c.first][c.second]->getTemperature();
            cnt++;
          }
        }
        if (cnt) {
          temperature = std::rand() % 5 - 2 + sum / cnt;
        } else {
          temperature = std::rand() % 71 - 35;
        }
      }
      cells[i][j] = new Cell(this, {i, j}, temperature);
    }
  }
  unsigned int count = _height * _width;
  addOrder.resize(count);
  std::vector<unsigned int> residues(count);
  for (unsigned int i = count - 1; i >= 0; i--) {
    residues[i] = std::rand() % (i + 1);
    addOrder[i] = residues[i];
    for (unsigned int j = i + 1; j < count; j++) {
      addOrder[i] += residues[j] + 1;
      addOrder[i] %= (j + 1);
    }
    //  std::cout << addOrder[i];
  }
}

Ocean::~Ocean() {
  for (unsigned int i = 0; i < height; i++) {
    for (unsigned int j = 0; j < width; j++) {
      delete cells[i][j];
    }
  }
  objects.clear();
}

unsigned int Ocean::getWidth() {
  return width;
}

unsigned int Ocean::getHeight() {
  return height;
}

Cell* Ocean::getCell(unsigned int _x, unsigned int _y) {
  return cells[_x][_y];
}

void Ocean::addObject(Object* _object) {
  objects.insert(_object);
}


void Ocean::deleteObject(Cell *_cell) {
  objects.erase(_cell->getObject());
  _cell->killObject();
}

void Ocean::createObjects(NATURE _nature, unsigned int _count) {
  for (unsigned int i = 0; i < _count; i++) {
    unsigned int x = addOrder.back() / width;
    unsigned int y = addOrder.back() % width;
    addOrder.pop_back();
    Object* object = nullptr;
    if (NATURE::PREY == _nature) {
      object = new Prey(cells[x][y], NATURE::PREY, 0);
    } else if (NATURE::PREDATOR == _nature) {
      object = new Predator(cells[x][y], NATURE::PREDATOR, 0);
    } else if (NATURE::STONE == _nature) {
      object = new Stone(cells[x][y], NATURE::STONE, 0);
    }
    cells[x][y]->setObject(object);
    objects.insert(object);
  }
}

void Ocean::print() {
  for (unsigned int i = 0; i < height; i++) {
    for (unsigned int j = 0; j < width; j++) {
      auto object = cells[i][j]->getObject();
      if (nullptr != object) {
        //  std::cout << FEATURES::picture[object->getNature()];
        std::cout << picture[object->getNature()];
      } else {
        //  std::cout << FEATURES::picture[NATURE::UNKNOWN];
        std::cout << picture[NATURE::UNKNOWN];
      }
    }
    std::cout << '\n';
  }
}

void Ocean::run(unsigned int _years) {
  for (unsigned int year = 0; year < _years; year++) {
    for (unsigned int i = 0; i < height; i++) {
      for (unsigned int j = 0; j < width; j++) {
        int temperature = 0;
        if (!i && !j) {
          temperature = cells[i][j]->getTemperature() + std::rand() % 11 - 5;
        } else {
          auto area = cells[i][j]->getArea();
          unsigned int cnt = 0;
          int sum = 0;
          for (auto c : area) {
            if (nullptr != cells[c.first][c.second]) {
              sum += cells[c.first][c.second]->getTemperature();
              cnt++;
            }
          }
          if (cnt) {
            temperature = std::rand() % 5 - 2 + sum / cnt;
          } else {
            temperature = cells[i][j]->getTemperature() + std::rand() % 11 - 5;
          }
        }
        cells[i][j]->setTemperature(temperature);
      }
    }

    std::set<Object*> trash;
    for (auto* object : objects) {
        if (nullptr == object) {
          trash.insert(object);
          continue;
        }
        object->live();
        //  if (object->getAge() == FEATURES::longevity[object->getNature()])
        if (object->getAge() == longevity[object->getNature()])
          trash.insert(object);
    }
    for (auto* object : trash) {
      if (nullptr != object) {
        deleteObject(object->getCell());
      } else {
        objects.erase(object);
      }
    }
    print();
  }
}


