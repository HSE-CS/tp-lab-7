// Copyright 2020 S. BOR

#include "ocean.h"
#include <unistd.h>
#include <iostream>

Ocean::Ocean() {
  cells = new Cell **[N];
  for (int i = 0; i < N; i++) {
    cells[i] = new Cell *[M];
    for (int j = 0; j < M; j++) {
      Coords crd;
      crd.x = i, crd.y = j;
      cells[i][j] = new Cell(crd, this);
    }
  }
}

void Ocean::addObject(Object * obj, int i, int j) {
  cells[i][j]->setObject(obj);  
}

void Ocean::run() {
  while (true) {
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        if (cells[i][j]->obj != nullptr)
          cells[i][j]->obj->nextTurn();
    print();
    sleep(1);
  }
}

void Ocean::print() {
  std::cout << std::endl;
  for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++)
        if (cells[i][j]->obj != nullptr)
          cells[i][j]->obj->printSymb();
        else
          std::cout << "~";
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
