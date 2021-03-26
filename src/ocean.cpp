//// Copyright 2021 Lukicheva Polina
#include <time.h>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "../include/prey.h"
#include "../include/predator.h"
#include "../include/cell.h"
#include "../include/ocean.h"

Ocean::Ocean(float stone, float prey, float predator)
{
  cells = new Cell * [N];
  for (int i = 0; i < N; i++) {
    cells[i] = new Cell[M];
    for (int j = 0; j < M; j++) {
      cells[i][j].init({ i, j }, this);
    }
  }
  int types[3] = { static_cast<int>(stone * N * M), static_cast<int>(prey * N * M), static_cast<int>(predator * N * M) };

  for (auto type : types) {
    for (int i = 0; i < type; i++) {
      while (true) {
        unsigned int seed = time(nullptr);
        int x = rand_r(&seed) % N;
        int y = rand_r(&seed) % M;
        if (cells[x][y].getObject() == nullptr && type == 0) {
          Stone* new_st = new Stone(&cells[x][y]);
          cells[x][y].obj = new_st;
          stuff.push_back(new_st);
          break;
        }

        if (cells[x][y].getObject() == nullptr && type == 1) {
          Prey* new_prey = new Prey(&cells[x][y]);
          cells[x][y].obj = new_prey;
          stuff.push_back(new_prey);
          break;
        }

        if (cells[x][y].getObject() == nullptr && type == 1) {
          Predator* new_pred = new Predator(&cells[x][y]);
          cells[x][y].obj = new_pred;
          stuff.push_back(new_pred);
          break;
        }

      }
    }
  }
}

Cell* Ocean::find(Cell* cell)
{
  int s = time(nullptr);
  int x = (cell->getX() + rand_r(&s)) % N;
  int y = (cell->getY() + rand_r(&s)) % M;
  return &cells[x][y];
}

void Ocean::print() const
{
  for (int i = 0; i < N; i++) 
    for (int j = 0; j < M; j++) 
      if (cells[i][j].getObject() == nullptr)
        std::cout << "-";
      else if (cells[i][j].getObject()->getType() == ObjType::STONE)
        std::cout << STONE_N;
      else if (cells[i][j].getObject()->getType() == ObjType::PREY)
        std::cout << PREY_N;
      else if (cells[i][j].getObject()->getType() == ObjType::PREDATOR)
        std::cout << PREDATOR_N;
}

void Ocean::addObjects(Object* obj)
{
  stuff.push_back(obj);
}

void Ocean::run()
{
  while (true) {
    for (Object* o : stuff) {
      if (o == nullptr)
        continue;
     // std::cout << o->getType();
      o->live();
    }
    print();
  }
}

