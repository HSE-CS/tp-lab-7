// Copyright 2021 ArinaMonicheva

#include <iostream>
#include "../include/ocean.h"
#include "../include/predator.h"

Ocean::Ocean(int width, int height) {
  this->height = height;
  this->width = width;
  cells = new Cell*[height];
  for (int i = 0; i < height; i++) {
    cells[i] = new Cell[width];
  }
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cells[i][j].init({ (coord_t)j, (coord_t)i }, this);
    }
  }
}

void Ocean::print() const {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (!cells[i][j].isEmpty()) {
        switch (cells[i][j].inhabitant->getType()) {
        case ObjType::STONE:
          std::cout << STONE_N;
          break;
        case ObjType::PREY:
          std::cout << PREY_N;
          break;
        case ObjType::PREDATOR:
          std::cout << PREDATOR_N;
          break;
        }
      } else {
          std::cout << ' ';
        }
    }
    std::cout << std::endl;
  }
}

void Ocean::addToBiosphere(Object* existingObject) {
  biosphere.push_back(existingObject);
}

int Ocean::movement(coords prev, coords newCds, Object* existingObject) {
  if (cells[newCds.y][newCds.x].isEmpty()) {
    cells[prev.y][prev.x].freeMe();
    existingObject->setCell(&(cells[newCds.y][newCds.x]));
    return 1;
  } else if (existingObject->getType() == ObjType::PREDATOR &&
     cells[newCds.y][newCds.x].inhabitant->getType() == ObjType::PREY) {
    cells[prev.y][prev.x].freeMe();
    cells[newCds.y][newCds.x].inhabitant->die();
    existingObject->setCell(&(cells[newCds.y][newCds.x]));
    return 2;
  } else {
    return 0;
  }
}

int Ocean::getWidth() {
  return width;
}

int Ocean::getHeight() {
  return height;
}

void Ocean::run() {  //
  while (biosphere.size()) {
    clock_t now = clock();
    print();
    while (clock() < now + CLOCKS_PER_SEC / 1) {
      continue;
    }
    int flag = 0;
    std::cout << "---------------------------------------------" << std::endl;
    std::list <Object*> :: iterator i = biosphere.begin();
    while (i != biosphere.end() && biosphere.size()) {
      if ((*i)->livesLeft() > 1 && (*i)->getType() != ObjType::STONE) {
        (*i)->live();
        if ((*i)->livesLeft() < 1) {
          (*i)->die();
          biosphere.erase(i++);
          flag++;
        }
      } else if ((*i)->getType() != ObjType::STONE) {
        (*i)->die();
        biosphere.erase(i++);
        flag++;
      }
      if (!flag) {
        i++;
      } else {
        flag = 0;
      }
    }
  }
}

void Ocean::addObjects(int quantity, int type,
 std::vector < std::vector <coords> > availableCoords) {
  time_t* n = NULL;
  unsigned* seed = 0;
  srand(time(n));

  while (quantity) {
    int y = r_rand(&seed) % availableCoords.size(), x =
     r_rand(&seed) % availableCoords[y].size();
    if (x > 0) {
      Object* temp = nullptr;
      switch (type) {
       case static_cast<int>ObjType::STONE: {
        temp = new Stone(&((cells[availableCoords[y][x].y])
         [availableCoords[y][x].x]));
        }
        break;
       case static_cast<int>ObjType::PREY: {
        temp = new Prey(&((cells[availableCoords[y][x].y])
         [availableCoords[y][x].x]));
        addToBiosphere(temp);
        }
        break;
       case static_cast<int>ObjType::PREDATOR: {
        temp = new Predator(
         &((cells[availableCoords[y][x].y])[availableCoords[y][x].x]));
        addToBiosphere(temp);
        }
        break;
      }
      quantity--;
    } else {
       availableCoords.erase(availableCoords.begin() + y);
    }
  }
}
