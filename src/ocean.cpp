// Copyright 2021 Andrey Bakurskii

#include "..\include\ocean.h"


void Ocean::run() {}

void Ocean::print() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (this->matrix_cell[i][j].obj_type == ObjType::EMPTY) {
        std::cout << EMPTY_N;
      }

      if (this->matrix_cell[i][j].obj_type == ObjType::PREY) {
        std::cout << PREY_N;
      }

      if (this->matrix_cell[i][j].obj_type == ObjType::PREDATOR) {
        std::cout << PREDATOR_N;
      }

      if (this->matrix_cell[i][j].obj_type == ObjType::STONE) {
        std::cout << STONE_N;
      }
    }
    std::cout << std::endl;
  }
}

void Ocean::fullMatrix(float prey, float predator, float stone) {
  this->matrix_cell = new Cell *[N];
  for (int i = 0; i < N; i++) {
    this->matrix_cell[i] = new Cell[M];
    for (int j = 0; j < M; j++) {
      this->matrix_cell[i][j].initCell(
          Pair{static_cast<coord_t>(i), static_cast<coord_t>(j)},
          this);

      this->matrix_cell[i][j].setObj(nullptr);
    }
  }

  int numPrey = static_cast<int>(prey * N * M);

  for (int i = 0; i < numPrey; i++) {
    while (true) {
      srand(static_cast<unsigned int>(time(0)));

      int x = static_cast<int>(rand() % N);
      int y = static_cast<int>(rand() % M);

      if (this->matrix_cell[x][y].object == nullptr) {
        Object *new_obj = new Prey(&this->matrix_cell[x][y], ObjType::PREY);
      
        this->matrix_cell[x][y].setObj(new_obj);
        this->objects.push_back(new_obj);
        break;
      }
    }
  }


  int numPredator = static_cast<int>(predator * N * M);

  for (int i = 0; i < numPredator; i++) {
    while (true) {
      srand(static_cast<unsigned int>(time(0)));

      int x = static_cast<int>(rand() % N);
      int y = static_cast<int>(rand() % M);

      if (this->matrix_cell[x][y].object == nullptr) {
        Object *new_obj = new Predator(&this->matrix_cell[x][y], ObjType::PREDATOR);

        this->matrix_cell[x][y].setObj(new_obj);
        this->objects.push_back(new_obj);
        break;
      }
    }
  }


  int numStone = static_cast<int>(stone * N * M);

  for (int i = 0; i < numStone; i++) {
    while (true) {
      srand(static_cast<unsigned int>(time(0)));

      int x = static_cast<int>(rand() % N);
      int y = static_cast<int>(rand() % M);

      if (this->matrix_cell[x][y].object == nullptr) {
        Object *new_obj = new Stone(&this->matrix_cell[x][y], ObjType::STONE);

        this->matrix_cell[x][y].setObj(new_obj);
        this->objects.push_back(new_obj);
        break;
      }
    }
  }
}

void Ocean::addObject(Object *new_obj) { this->objects.push_back(new_obj); }

void Ocean::deleteObject(Object *obj) {
  this->objects.remove(obj);
  delete obj;
}

Cell *Ocean::getEmptyCellNearTo(Cell *) { return nullptr; }

Cell *Ocean::getPreyCellNearTo(Cell *) { return nullptr; }
